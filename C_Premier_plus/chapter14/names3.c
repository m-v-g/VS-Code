#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SLEN 81
struct namect
{
    char * fname; //использование укозателей
    char * lname;
    int letters;
};

void getinfo(struct namect *); //выделение памяти
void makeinfo(struct namect *);
void showinfo(const struct namect *);
void cleanup(struct namect *); //освобождение памятиб когда она не нужна
char * s_gets(char * st, int n);

int main(void)
{
    struct namect person;
    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
    cleanup(&person);
    return 0;
}

void getinfo(struct namect * pst)
{
    char temp[SLEN];
    printf("Введите свое имя.\n");
    s_gets(temp, SLEN);
    pst->fname = (char *) malloc(strlen(temp) + 1); //видиление памяти для хранения имени
    strcpy(pst->fname, temp); //копирование имени в выделенную память
    printf("Введите свю фамилию.\n");
    s_gets(temp, SLEN);
    pst->lname = (char *) malloc(strlen(temp) + 1); //видиление памяти для хранения имени
    strcpy(pst->lname, temp); //копирование имени в выделенную память
}

void makeinfo(struct namect * pst)
{
    pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo(const struct namect * pst)
{
    printf("%s %s, ваше имя и фамилия содержит %d букв.\n", pst->fname, pst->lname, pst->letters);
}

void cleanup(struct namect * pst)
{
    free(pst->fname);
    free(pst->lname);
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