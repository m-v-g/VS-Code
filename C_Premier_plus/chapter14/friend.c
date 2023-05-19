#include <stdio.h>
#define LEN 20
const char * msgs[5] = 
{
    "   Благодарю вас за чудесно проведенный вечер,  ",
    "Вы однозначно продемонстрировали,  что ",
    "являет собою особый тип мужчины. Мы обязательно должны встретиться", 
    "за восхитительным уж:ином с " ,
    " и весело провести время."
};

struct names               // первая структура
{
    char first[LEN];
    char last[LEN];
};

struct guy                 // вторая структура
{
    struct names handle;   // вложенная структура
    char favfood[LEN];
    char job[LEN];
    float income;
};

int main(void)
{
    struct guy fellow = // инициализация переменной
    {
        {  "Билли",  "Боне"  },
        "запечеными омарами",
        "персональный тренер",
        68112.00
    };

    printf("Дорогой %s, \n\n", fellow.handle.first);
    printf("%s%s.\n", msgs[0], fellow.handle.first);
    printf("%s%s.\n", msgs[1], fellow.job);
    printf("%s\n", msgs[2]);
    printf("%s%s%s", msgs[3], fellow.favfood, msgs[4]);
    if (fellow.income > 75000.0)
    {
        puts("!");
    }
    else
    {
        puts(".");
    }
    printf("\n%40s%s\n ", " ", "До скорой встречи,");
    printf("%40s%s\n", " ", "Шейла");

    return 0;
}