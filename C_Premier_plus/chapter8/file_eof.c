#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int ch;
    FILE * fp;
    char filenam[50]; //для хранения имени файла

    printf("Введите имя файла: ");
    scanf("%s", filenam);
    fp = fopen(filenam, "r"); //открит файл для чтения
    if (fp == NULL)
    {
        printf("Не удаётся открит файл. Программа завершена.\n");
        exit(1);  //выйти из программы
    }
    //функция getch(ch) получает символ из откритого файла
    while ((ch = getc(fp)) != EOF)
    {
        putchar(ch);
    }
    fclose(fp); //закрит файл
    return 0;
}