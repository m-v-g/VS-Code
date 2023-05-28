/*сохроняет содержимое книги в файл*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * s_gets(char * st, int n);
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100 //максимальное количество книг
typedef struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
}BOOK; //BOOK = struct book

int main(void)
{
    BOOK library[MAXBKS]; //масив структур типа book
    int count = 0;
    int index, filecount;
    FILE * pbooks;
    int size = sizeof(struct book);
    if ((pbooks = fopen("book.dat", "a + b")) == NULL)
    {
        fputs("Не удается открить файл book.dat\n", stderr);
        exit(1);
    }
    rewind(pbooks); //переход в начало файла
    while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
    {
        if (count == 0)
        {
            puts("Текущее содержимое файла book.dat:");
            printf("%s авторства %s: $%.2f\n", library[count].title, library[count].author, library[count].value);
            count++;
        }
    }
    filecount = count;
    if (count == MAXBKS)
    {
        fputs("Файл book.dat заполнен.", stderr);
        exit(2);
    }
    printf("Введите название книги.\n");
    printf("Нажмите [enter] в начале строкиб чтобы закончит ввод.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
    {
        printf("Теперь введите ФИО автора.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Теперь введите цену.\n");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
        {
            continue; //очистить входную строку
        }
        if (count < MAXBKS)
        {
            printf("Введите название следуюшей книги.\n");
        }
    }
    if (count > 0)
    {
        printf("Каталог ваших книг:\n");
        for (index = 0; index < count; index++)
        {
            printf("%s авторства %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
        }
        fwrite(&library[filecount], size, count - filecount, pbooks);
    }
    else
    {
        printf("Вообше нет книг? Очень плохо.\n");
    }
    puts("Программа завершена.\n");
    fclose(pbooks);
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