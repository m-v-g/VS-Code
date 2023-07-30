/*
 * gsm.c
 *
 *  Created on: 18 авг. 2019 г.
 *      Author: dima
 */
#include "main.h"
#include "gsm.h"
#include "usart_ring.h"
#include "nokia5110_LCD.h"
#include <stdlib.h>
//#include <stdio.h>


#define SEND_STR_SIZE 64
extern char dbi[7]; //podkluchaem masiv sozdanny v main.c
extern char operator[14]; //podkluchaem masiv sozdanny v main.c
extern char bat[4]; //podkluchaem masiv sozdanny v main.c
extern char sig[4]; //podkluchaem masiv sozdanny v main.c
extern uint32_t numbers[10]; //nomera sim karte

uint32_t num = 0;
uint8_t counter;

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;


///////////////////////// Функция для замены смволов \r и \n на пробелы ////////////////////////////
void replac_string(char *src)
{
	if(!src) return;

	for(;*src; src++)
	{
		if(*src == '\n' || *src == '\r') *src = ' ';
	}
}



///////////////////////// Функция для отправки настроечных команд, в цикле лучше не использовать ////////////////////////////
void set_comand(char *buff)
{
	uint8_t count_err = 0;
	char str[SEND_STR_SIZE] = {0,};
	snprintf(str, SEND_STR_SIZE, "%s\r\n", buff);
	HAL_UART_Transmit(GSM, (uint8_t*)str, strlen(str), 1000);
	HAL_Delay(200);

	memset(str, 0, SEND_STR_SIZE);

	for(uint8_t i = 0; i < 30; i++)
	{
		if(gsm_available()) //если модуль что-то прислал
		{
			uint16_t i = 0;

			while(gsm_available())
			{
				str[i++] = gsm_read();
				if(i > SEND_STR_SIZE - 1) break;
				HAL_Delay(1);
			}

			replac_string(str);

			char *p = NULL;

			if((p = strstr(str, "+CPAS:")) != NULL)
			{
				if(strstr(str, "0") == NULL)
				{
					HAL_UART_Transmit(DEBUG, (uint8_t*)p, strlen(p), 1000);
					HAL_UART_Transmit(DEBUG, (uint8_t*)"\n+CPAS not ready, must be '0'\n", strlen("\n+CPAS not ready, must be '0'\n"), 1000);

					while(1) // мигаем 5 секунд и ресетим плату
					{
						count_err++;
						HAL_GPIO_TogglePin(ERR_LED_GPIO_Port, ERR_LED_Pin);
						HAL_Delay(100);
						if(count_err > 49) HAL_NVIC_SystemReset();
					}
				}
			}
			else if((p = strstr(str, "+CREG:")) != NULL)
			{
				if(strstr(str, "0,1") == NULL)
				{
					HAL_UART_Transmit(DEBUG, (uint8_t*)p, strlen(p), 1000);
					HAL_UART_Transmit(DEBUG, (uint8_t*)"\n+CREG not ready, must be '0,1'\n", strlen("\n+CREG not ready, must be '0,1'\n"), 1000);

					while(1) // мигаем 5 секунд и ресетим плату
					{
						count_err++;
						HAL_GPIO_TogglePin(ERR_LED_GPIO_Port, ERR_LED_Pin);
						HAL_Delay(100);
						if(count_err > 49) HAL_NVIC_SystemReset();
					}
				}
			}

			else if((p = strstr(str, "+CSQ:")) != NULL) //esli stroka str soderjit stroku +CSQ:
			{
				p = strtok( str, "+CSQ: " ); //otkusivaem iz stroki str stroku +CSQ: i vozvrashaem ukozatel p
				//uint8_t csq = strtod(str, NULL); // FUNKCIYA 13KB!!!!!!!!!!!!!!!
				uint8_t csq = atoi(p); //preobrazuem stroku v chislo
				uint8_t db = (115 - (csq*2)); //sozdaem peremennuyu db i perevodim chislo v dBi
				snprintf(dbi, 7, "-%udBi", db); //pishem v masiv soobshenie
				uint8_t si = csq*3; //sozdaem peremennuyu si i perevodim chislo v procenti
				snprintf(sig, 4, "%u", si); //pishem v masiv soobshenie
			}

			else if((p = strstr(str, "+CSPN:")) != NULL) //esli stroka str soderjit stroku +CSPN:
			{
				p = strtok( str, " " ); // begin tokenizing sentence
				p = strtok( NULL, ":" ); // get next token
				//p = strtok( NULL, "\"" ); // get next token
				snprintf(operator, 14, "%s", p); //pishem v masiv soobshenie

			}

			else if((p = strstr(str, "+CBC:")) != NULL) //esli stroka str soderjit stroku +CBC:
			{
				p = strtok( str, " " ); //otkusivaem iz stroki str stroku   i vozvrashaem ukozatel p
				p = strtok( NULL, "," ); //otkusivaem iz stroki str stroku , i vozvrashaem ukozatel p
				p = strtok( NULL, "," ); //otkusivaem iz stroki str stroku , i vozvrashaem ukozatel p
				snprintf(bat, 4, "%s", p); //pishem v masiv soobshenie

			}





			p = 0; //zbrasivaem ukazatel

			char dbg_str[SEND_STR_SIZE + 32] = {0,};
			snprintf(dbg_str, SEND_STR_SIZE + 32, "Set %s %s\n", buff, str);
			HAL_UART_Transmit(DEBUG, (uint8_t*)dbg_str, strlen(dbg_str), 1000);

			return;
		}

		HAL_Delay(500);

	} // END for()

	HAL_UART_Transmit(DEBUG, (uint8_t*)"Not reply ", strlen("Not reply "), 1000);
	HAL_UART_Transmit(DEBUG, (uint8_t*)buff, strlen(buff), 1000);

	while(1) // мигаем 5 секунд и ресетим плату
	{
		count_err++;
		HAL_GPIO_TogglePin(ERR_LED_GPIO_Port, ERR_LED_Pin);
		HAL_Delay(100);
		if(count_err > 49) HAL_NVIC_SystemReset();
	}

}

/////////////////////// Функции для использования в цикле //////////////////////////
void balance(void)
{
	char ATD[] = "ATD#100#;\r\n"; // баланс (бабло)
	HAL_UART_Transmit(GSM, (uint8_t*)ATD, strlen(ATD), 1000);
}

void disable_connection(void)
{
	char ATH[] = "ATH\r\n"; // сбросить все соединения
	HAL_UART_Transmit(GSM, (uint8_t*)ATH, strlen(ATH), 1000);
}

void call(void)
{
	char ATD[] = "ATD+79819555551;\r\n"; // позвонить
	HAL_UART_Transmit(GSM, (uint8_t*)ATD, strlen(ATD), 1000);
}

void incoming_call(void)
{
	char ATA[] = "ATA\r\n"; // принять звонок
	HAL_UART_Transmit(GSM, (uint8_t*)ATA, strlen(ATA), 1000);
}

void get_date_time(void)
{
	char ATCCLK[] = "AT+CCLK?\r\n"; // узнать дату/время
	HAL_UART_Transmit(GSM, (uint8_t*)ATCCLK, strlen(ATCCLK), 1000);
}

void get_contact(void)
{
	for (counter = 1; counter <= 9; counter++)
	    {
	        char ATCPBR[11];
	        snprintf(ATCPBR, 11, "AT+CPBR=%u\n", counter); //pishem v masiv soobshenie
	        HAL_UART_Transmit(GSM, (uint8_t*)ATCPBR, strlen(ATCPBR), 1000);
	        HAL_UART_Transmit(DEBUG, (uint8_t*)ATCPBR, strlen(ATCPBR), 1000);
	        HAL_Delay(200);
	        char str[SEND_STR_SIZE] = {0,};

	        for(uint8_t i = 0; i < 30; i++)
	        	{
	        		if(gsm_available()) //если модуль что-то прислал
	        		{
	        			uint16_t i = 0;


	        			while(gsm_available())
	        			{
	        				str[i++] = gsm_read();
	        				if(i > SEND_STR_SIZE - 1) break;
	        				HAL_Delay(1);
	        			}

	        			replac_string(str);

	        			char *p = NULL;

			if((p = strstr(str, "+CPBR:")) != NULL) //esli stroka str soderjit stroku +CPBR:
			{
				p = strtok( str, "+CPBR: ," ); //otkusivaem iz stroki str stroku +CPBR: ,  i vozvrashaem ukozatel p
				p = strtok( NULL, "\"" ); // get next token
				num = atoi( p );
				numbers[counter] = num; //nomera sim karte
				snprintf(ATCPBR, 11, "0%lu\n", num); //pishem v masiv soobshenie
				//snprintf(num, 10, "%s", p); //pishem v masiv soobshenie
				HAL_UART_Transmit(DEBUG, (uint8_t*)ATCPBR, strlen(ATCPBR), 1000);

			}
			else
			{
				p = 0; //zbrasivaem ukazatelp = 0; //zbrasivaem ukazatel
				return;
			}
			p = 0; //zbrasivaem ukazatel

	        		}
	        	}

	    }
}

void alarm(void)
{
	for (int z = 1; z <= 3; ++z)
		{
		for (int g = 1; g < counter; g++)
	    	{
				char ATD[18];
				snprintf(ATD, 18, "ATD0%lu;\n", numbers[g]); //pishem v masiv soobshenie
				HAL_UART_Transmit(GSM, (uint8_t*)ATD, strlen(ATD), 1000);
				HAL_UART_Transmit(DEBUG, (uint8_t*)ATD, strlen(ATD), 1000);
				LCD_invertText(true);
				snprintf(ATD, 15, "DIAL 0%lu", numbers[g]); //pishem v masiv soobshenie
				LCD_print(ATD, 0, 2);
				HAL_Delay(20000);
				LCD_invertText(false);
				LCD_print("              ", 0, 2);
				disable_connection();
				HAL_Delay(500);
	    	}
		}
}

void sms(int i)
{
	char text[9] = {0,};
if (i == 1) {
	snprintf(text, 6, "ARMED"); //pishem v masiv soobshenie
}
else if (i == 2) {
	snprintf(text, 9, "DISARMED"); //pishem v masiv soobshenie
}
else if (i == 3) {
	snprintf(text, 6, "AC ON"); //pishem v masiv soobshenie
}
else if (i == 4) {
	snprintf(text, 7, "AC OFF"); //pishem v masiv soobshenie
}
	char CMGS[21];
	LCD_invertText(true);
	LCD_print(" SENDING  SMS ", 0, 2);
	snprintf(CMGS, 21, "AT+CMGS=\"0%lu\"\r\n", numbers[1]); //pishem SMS na pervy nomer
	HAL_UART_Transmit(GSM, (uint8_t*)CMGS, strlen(CMGS), 1000);
	HAL_Delay(100);
	//HAL_UART_Transmit(GSM, (uint8_t*)"ARMED", strlen("ARMED"), 1000);
	snprintf(CMGS, 9, "%s", text); // текст смс
	HAL_UART_Transmit(GSM, (uint8_t*)CMGS, strlen(CMGS), 1000);
	HAL_UART_Transmit(DEBUG, (uint8_t*)CMGS, strlen(CMGS), 1000);
	HAL_UART_Transmit(DEBUG, (uint8_t*)"\n", strlen("\n"), 1000);
	HAL_Delay(100);
	snprintf(CMGS, GSM_RX_BUFFER_SIZE, "%c", (char)26); // символ ctrl-z
	HAL_UART_Transmit(GSM, (uint8_t*)CMGS, strlen(CMGS), 1000);
	LCD_invertText(false);
	LCD_print("              ", 0, 2);
}

void welcome(void)
{
	// в Кубе настроить 5 пинов как Output, например PA3 - PA7 (можно переименовать их в соответствии с назначением)
  // и прописать в функции ниже - ПОРТ, П�?Н. Подключать в соответствии с названиями контактов экрана.
  LCD_setRST(GPIOB, RST_Pin);
  LCD_setCE(GPIOB, CE_Pin);
  LCD_setDC(GPIOB, DC_Pin);
  LCD_setDIN(GPIOB, DIN_Pin);
  LCD_setCLK(GPIOB, CLK_Pin);

  LCD_init();

  //uint16_t i = 0;
  HAL_GPIO_WritePin(ERR_LED_GPIO_Port, ERR_LED_Pin, GPIO_PIN_SET);
  LCD_print("LABIRINT", 18, 2);
  LCD_print("ELECTRIC", 18, 3);
  LCD_print("GSMD_MINI_v1.2", 0, 5);
  HAL_Delay(2000);
  LCD_clrScr(); // очистить экран
  LCD_print("LABIRINT", 18, 0);
  LCD_print("ELECTRIC", 18, 1);
  LCD_invertText(true);
  LCD_print("   starting   ", 0, 2);
  HAL_Delay(500);
  LCD_print("   power on   ", 0, 2);
  HAL_GPIO_WritePin(GSM_RESET_GPIO_Port, GSM_RESET_Pin, GPIO_PIN_SET);
  HAL_Delay(30000); // задержка чтоб модем успел раздуплиться, если его включение происходит вместе с включением МК
}

void starting(void)
{
	chek_speed(); // проверка и установка скорости 19200, нужна один раз
  LCD_print(" speed  check ", 0, 2);
  HAL_Delay(500);
  ////////////////// настройка модема ///////////////////
  LCD_print(" status check ", 0, 2);
  HAL_Delay(500);
  set_comand(ATCPAS);  // проверка статуса модема
  LCD_print("registr  check", 0, 2);
  HAL_Delay(500);
  set_comand(ATCREG);  // проверка регистрации в сети - должен вернуть  +CREG: 0,1
  LCD_print("   loading    ", 0, 2);
  HAL_Delay(500);
  set_comand(ATCLIP1); // включить АОН
  set_comand(ATE);     // отключить «эхо»
  set_comand(ATS);     // поднимать трубку только "вручную"
  set_comand(ATDDET);  // включить DTMF
  //set_comand(ATCCLKK); // установить дату/время

  /////////////////// настройки для работы с sms ////////////////
  set_comand(ATCMGF);    // устанавливает текстовый режим смс-сообщения
  set_comand(ATCPBS);    // открывает доступ к данным телефонной книги SIM-карты
  set_comand(ATCSCS);    // кодировка текста - GSM
  set_comand(ATCNMI);    // настройка вывода смс в консоль

  //////////////////// различная инфа /////////////////////
  set_comand(ATIPR);       // скорость usart'a модема
  set_comand(ATI);         // название и версия модуля
  set_comand(ATCGSN);      // считывание IMEI из EEPROM
  set_comand(ATCSPN);      // оператор сети


  get_contact();
}
