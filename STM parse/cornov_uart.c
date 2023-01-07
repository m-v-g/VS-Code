#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define WELCOME_MSG "Welcome to the Nucleo management console\r\n"
#define MAIN_MENU   "Select the option you are interested in:\r\n\t1. Toggle LD2 LED\r\n\t2. Read USER BUTTON status\r\n\t3. Clear screen and print this message "
#define PROMPT "\r\n> "

void printWelcomeMessage(void);
uint8_t processUserInput(uint8_t opt);
uint8_t readUserInput(void);
uint8_t opt = 0;
bool b = false;

int main()
{
    printf("asd\n");
    /*
    int asd;
    printf("hello world");
    scanf("%d", &asd);
    printf("asd = %d", asd);
    */
    printMessage:
	
	    printWelcomeMessage();

	while (1)  {
		opt = readUserInput();
		processUserInput(opt);
		if(opt == 3)
			goto printMessage;
	}
    return 0;
}

void printWelcomeMessage(void) {
    printf("\033[0;0H");
    printf("\033[2J");
    printf(WELCOME_MSG);
    printf(MAIN_MENU);
	//HAL_UART_Transmit(&huart2, (uint8_t*)"\033[0;0H", strlen("\033[0;0H"), HAL_MAX_DELAY);
	//HAL_UART_Transmit(&huart2, (uint8_t*)"\033[2J", strlen("\033[2J"), HAL_MAX_DELAY);
	//HAL_UART_Transmit(&huart2, (uint8_t*)WELCOME_MSG, strlen(WELCOME_MSG), HAL_MAX_DELAY);
	//HAL_UART_Transmit(&huart2, (uint8_t*)MAIN_MENU, strlen(MAIN_MENU), HAL_MAX_DELAY);
}

uint8_t readUserInput(void) {
	char readBuf[1];
    printf(PROMPT);
	//HAL_UART_Transmit(&huart2, (uint8_t*)PROMPT, strlen(PROMPT), HAL_MAX_DELAY);
    scanf("%d", readBuf);
	//HAL_UART_Receive(&huart2, (uint8_t*)readBuf, 1, HAL_MAX_DELAY);
	return atoi(readBuf);
}


uint8_t processUserInput(uint8_t opt) {
	char msg[30];

	if(!opt || opt > 3)
		return 0;

	sprintf(msg, "%d", opt);
    printf(msg);
	//HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

	switch(opt) {
	case 1:
		//HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
        b++;
		sprintf(msg, "LED IS %d", b);
		printf(msg);
		break;
	case 2:
		//sprintf(msg, "\r\nUSER BUTTON status: %s", HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET ? "PRESSED" : "RELEASED");
		//HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
		printf("USER BUTTON");
		break;
	case 3:
		return 2;
	};

	return 1;
}