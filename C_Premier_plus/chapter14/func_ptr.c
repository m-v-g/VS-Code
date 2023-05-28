#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 81
char * s_gets(char * st, int n);
char showmenu(void);
void eatline(void); //читает до конца
void show(void (* fp)(char *), char * str);
void ToUpper(char *); //преобразует строку в верхний регистр
void ToLower(char *); //преобразует строку в нижний регистр
void Transponse(char *); //меняет местами регистры
void Dummy(char *); //оставляет строку неизменной

int main(void)
{
    char line[LEN];
    char copy[LEN];
    char choice;
    void (*pfun)(char *); //укозатель на функцию, которая имеет аргумент типа char * и нечего не возвращает
    puts("Введите строку (пустая строка - выход из программы): ");
    while (s_gets(line, LEN) != NULL && line[0] != '\0')
    {
        while ((choice = showmenu()) != 'n')
        {
            switch (choice) //оператор switch установливает укозатель
            {
            case 'u':
                pfun = ToUpper;
                break;
            case 'l':
                pfun = ToLower;
                break;
            case 't':
                pfun = Transponse;
                break;
            case 'o':
                pfun = Dummy;
                break;
            default:
                break;
            }
            strcpy(copy, line); //сделать копию для show()
            show(pfun, copy); //использовать выбранную функцию
        }
        puts("Введите строку (пустая строка - выход из программы): ");
    }
    puts("Программа завершена.\n");
    return 0;
}

char showmenu(void)
{
    char ans;
    puts("Введите выбранный вариант из меню:");
    puts("u) верхний регистр                l) нижний регистр");
    puts("t) поменять местами регистры      o) исходный регистр");
    puts("n) следующая строка");
    ans = getchar(); //получает ответ
    ans = tolower(ans); //преобразует в нижний регистр
    eatline(); //избавляеться от оставшейся часьти строки
    while (strchr("ulton", ans) == NULL)
    {
        puts("Введите u, l, t, o или n:");
        ans = tolower(getchar());
        eatline();
    }
    return ans;
}

void eatline(void)
{
    while (getchar() != '\n')
    {
        continue;
    }
}

void ToUpper(char * str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

void ToLower(char * str)
{
    while (*str)
    {
        *str = tolower(*str);
        str++;
    }
}

void Transponse(char * str)
{
    while (*str)
    {
        if (islower(*str))
        {
            *str = toupper(*str);
        }
        else if (isupper(*str))
        {
            *str = tolower(*str);
        }
        str++;
    }
}

void Dummy(char * str)
{
    //оставляет строку неизменной
}

void show(void (* fp)(char *), char * str)
{
    (*fp)(str); //применить вибранную функцию к str
    puts(str); //разить результат
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