#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45

struct film
{
    char title[TSIZE];
    int rating;
    struct film * next; //укозатель на следующую структуру в списке
};
char * s_gets(char * st, int n);

int main(void)
{
    struct film * head = NULL;
    struct film * prev, * current;
    char input[TSIZE];
    /*сборка и сохранение информации*/
    puts("Введите название первого фильма: ");
    while (s_gets(input, TSIZE) != NULL && input[0] !='\0')
    {
        current = (struct film *)malloc(sizeof(struct film));
        if (head == NULL)
        {
            head = current;
        }
        else
        {
            prev->next = current;
        }
        current->next = NULL;
        strcpy(current->title, input);
        puts("Введите свое значение рейтинга <0-10>:");
        scanf("%d", &current->rating);
        while (getchar() != '\n')
        {
            continue;
        }
        puts("Введите название следующего фильма (или пустую строку для прекращения ввода):");
        prev = current;
    }

    if (head == NULL)
    {
        printf("Данние не введены.");
    }
    else
    {
        printf("Список фильмов:\n");
    }
    current = head;

    while (current != NULL)
    {
        printf("Фильм: %s Рейтинг: %d\n", current->title, current->rating);
        current = current->next;
    }
    
    current = head;
    while (current != NULL)
    {
        current = head;
        head = current->next;
        free(current);
    }
    puts("Програма завершена");
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