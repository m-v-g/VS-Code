#include <stdio.h>
#include "names_st.h"

void get_names(names * pn)
{
    printf("Введите свое имя: ");
    s_gets(pn->first, SLEN);
    printf("Введите свою фамилию: ");
    s_gets(pn->last, SLEN);
}

void show_names(const names * pn)
{
    printf("%s %s", pn->first, pn->last);
}

char *s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); //поиск символа новой строки
        if (find)                //если адрес не является NULL
        {
            *find = '\0';        //поместить туда нулевой символ
        }
        else
        {
            while (getchar() != '\n')
            {
                continue;
            }
        }
    }
    return ret_val;
}