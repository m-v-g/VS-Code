#include <stdio.h>
#define LEN 20

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
    struct guy fellow[2] = // инициализация переменной
    {
        {{  "Билли",  "Боне"  },
        "запечеными омарами",
        "персональный тренер",
        68112.00},
        {{  "Джим",  "Хокинс"  },
        "рыбным фрикасе",
        "редактор таблоида",
        232400.00}
    };
    struct guy * him;  /* указатель на структуру */

    printf("адрес #1: %p #2: %p\n", &fellow[0], &fellow[1]);
    him = &fellow[0]; /* сообщает указателю,  на что указывать */
    printf("Укозатель #1: %p #2 %p\n", him, him + 1);
    printf("him->income ровно $%.2f: (*him).income ровно $%.2f\n", him->income, (*him).income);
    him++;  /* указатель на следующую структуру */
    printf("him->favfood ровно %s: him->handle.last ровно %s\n", him->favfood, him->handle.last);

    return 0;
}