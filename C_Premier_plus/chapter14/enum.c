/*использование перечислемых значений*/
#include <stdio.h>
#include <string.h> //для strcmp(), strchr()
#include <stdbool.h> //средство C99
char * s_gets(char * st, int n);
enum spectrum {red, orange, yellow, green, blue, violet};
const char * colors[] = {"red", "orange", "yellow", "green", "blue", "violet"};
#define LEN 30

int main(void)
{
    char choise[LEN];
    enum spectrum color;
    bool color_is_found = false;

    puts("Введите цвет (или пустую строку для выхода):");
    while (s_gets(choise, LEN) != NULL && choise[0] != '\0')
    {
        for (color = red; color <= violet; color++)
        {
            if (strcmp(choise, colors[color]) == 0)
            {
                color_is_found = true;
                break;
            }
        }
        switch (color)
        {
        case red:
            puts("Розы красные.");
            break;
        case orange:
            puts("Маки оранжевые.");
            break;
        case yellow:
            puts("Подсолнухи желтые.");
            break;
        case green:
            puts("Трова зеленая.");
            break;
        case blue:
            puts("Колокольчики синие.");
            break;
        case violet:
            puts("Фиалки фиолетовые.");
            break;
        
        default:
            printf("Цвет %s не известен.\n", choise);
            break;
        }
        color_is_found = false;
        puts("Введите следующий цвет (или пустую строку для выхода):");
    }
    puts("Программа завершена.\n");
    return 0;
}


char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); //поиск новой строки
        if (find)                //если адрес не равен NULL
        {
            *find = '\0';        //поместить туда нулевой символ
        }
        else
        {
            while (getchar() != '\n')
            {
                continue;  //отбросить остаток строки
            }
        }
    }
    return ret_val;
}