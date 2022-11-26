/*
 * FirstProgram.c
 *
 *  Created on: 17 мая 2017 г.
 *      Author: ivanovcinnikov
 */
//Это тоже комментарий

#include <stdio.h>

int main (int argc, const char* argv[]) {
	// \n \t \\ \0
	printf("Hello\0 World! \n");
	printf("This is a new \trow with tab. ");
	printf("This is a new row with \\ symbol\n");

	// %d %s %c %p %f %lf %x %%
	// %.2f
	// %05d
	int a = 50;
	printf("text and%5d%%\n", a);

	short sh = 345;		//2 bytes -32768...32767
	int number = -56;	//4 bytes -2.147.000000...+2.147.000000
	unsigned int uint = 4000000000; // bytes 0...+4.294.000.000
	unsigned char symbol = 'A';	// 0...255
	float real = 5.345f;		//4 bytes
	double realdouble = 5.345;	//8 bytes long float
	// no boolean type
	int true = 1;
	int false = 0;
	char sym = 75;		// 1 byte -128...127

	printf("Переменная а имеет значение: %d \n", a);
	printf("Переменная а хранится по адресу: %p \n", &a);
/*
	int input;
	printf("Введите, пожалуйста, число:");
	scanf("%d", &input);
	printf("Вы ввели число %d, мы удвоили его для Вас: %d\n", input, input*2);
*/
	// + - * /
	// & | ! ^ << >>

	int variable = 70;
	printf("Переменная variable %d\n", variable);
	variable = variable + 50;
	variable += 50;
	printf("К переменной было дважды прибавлено 50 и получилось %d \n", variable);
	variable = variable / 4;		// дробная часть будет проигнорирована
	printf("Целочисленное деление переменной на 4: %d\n", variable);

	int reminder = variable % 4;
	printf("Остаток от деления 170 на 4: %d\n", reminder);
	reminder++;
	printf("Инкремент %d \n", reminder);


	return 0;
}

