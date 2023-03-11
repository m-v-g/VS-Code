/*
Программа запрашивает у пользователя код символа и выводит соответствующий ему символ. 
Затем проигрывает звуковой сигнал, ожидает две секунды и выводит заданный текст. 
Для прослушивания звукового сигнала используются функции Beep() и Sleep(), определенные в библиотеке <Windows.h>.
*/

#include<stdio.h>
#include<Windows.h> // необходимая библиотека для использованных функций Beep() и Sleep()

int main(void) {
    int code = 0; // переменная для хранения введенного кода

    printf("Введите код символа: ");
    scanf("%d", &code);
    fflush(stdin); // очистка буфера входных данных

    printf("Символ, соответствующий коду %d: '%c'\n", code, (char)code);

    Beep(500, 1000); // проигрываем звуковой сигнал
    Sleep(2000); // ждем 2 секунды
    printf("Напуганная внезапным звуком, Вика вскрикнула:\"Во имя всех звезд, что это было!\"\n");
    
    return 0;
}
