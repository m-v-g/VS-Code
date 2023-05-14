/*произвольный доступб двойчный ввод-вывод*/
#include <stdio.h>
#include <stdlib.h>
#define ARSIZE 1000

int main()
{
    double numbers[ARSIZE];
    double value;
    const char * file = "numbers.dat";
    int i;
    long pos;
    FILE *iofile;
    //создание набора значений double
    for (i = 0; i < ARSIZE; i++)
    {
        numbers[i] = 100.0 * i + 1.0 / (i + 1);
    }
    //попитка открыть файл
    if ((iofile = fopen(file, "wb")) == NULL)
    {
        fprintf(stderr, "Не удается открить файл %s для вывода.\n", file);
        exit(EXIT_FAILURE);
    }
    //запись в файл массива в двойчном формате
    fwrite(numbers, sizeof(double), ARSIZE, iofile);
    fclose(iofile);
    if ((iofile = fopen(file, "rb")) == NULL)
    {
        fprintf(stderr, "Не удается открить файл %s для произвольного доступа.\n", file);
        exit(EXIT_FAILURE);
    }
    //чтение избранных элементов из файла
    printf("Введите индекс в диапазоне 0-%d.\n", ARSIZE - 1);
    while (scanf("%d", &i) == 1 && i >= 0 && i < ARSIZE)
    {
        pos = (long) i * sizeof(double); //вичисление смещения
        fseek(iofile, pos, SEEK_SET);    //переход в нужную позицию
        fread(&value, sizeof(double), 1, iofile);
        printf("По этому индексу находится значение %f.\n", value);
        printf("Введите следующий индекс (или значение за пределами диапазона для завершения):\n");
    }
    //завершение
    fclose(iofile);
    puts("Программа завершена.");
    return 0;
}