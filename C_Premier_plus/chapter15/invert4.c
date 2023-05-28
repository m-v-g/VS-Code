/*ипользование операции с битами для отображения двоичного представления чисел*/
#include <stdio.h>
#include <limits.h>
char * itobs(int, char *);
void show_bstr(const char *);
int invert_end(int, int);

int main(void)
{
    char bin_str[CHAR_BIT * sizeof(int) + 1];
    int number;

    puts("Введите целые числа и просмотривайте их двоичные представления.");
    puts("Нечисловой ввод завершает программу.");
    while (scanf(" %d", &number) == 1)
    {
        itobs(number, bin_str);
        printf("%d представляется как \n", number);
        show_bstr(bin_str);
        putchar('\n');
        number = invert_end(number, 4);
        puts("Инвертирование последних 4 битов дает");
        show_bstr(itobs(number, bin_str));
        putchar('\n');
    }
    puts("Программа завершена.");
    return 0;
}

char * itobs(int n, char * ps)
{
    const static int size = CHAR_BIT * sizeof(int);
    for (int i = size - 1; i >= 0; i--, n >>= 1)
    {
        ps[i] = (01 & n) + '0';
    }
    ps[size] = '\0';
    return ps;
}

void show_bstr(const char * str)
{
    int i = 0;
    while (str[i]) //пока не будет достигнут нулевой символ
    {
        putchar(str[i]);
        if (++i % 4 == 0 && str[i])
        {
            putchar(' ');
        }
        
    }
    
}

int invert_end(int num, int bits)
{
    int mask = 0;
    int bitval = 1;

    while (bits-- > 0)
    {
        mask |= bitval;
        bitval <<= 1;
    }
    return num ^ mask;
}