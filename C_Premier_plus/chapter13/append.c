/*добавление содержимого файла в файл назначения*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81

void append(FILE *source, FILE *dest);
char *s_gets(char *st, int n);

int main(void)
{
    FILE *fa, *fs; //fa для файла назначения, fs для исходного фаила
    int files = 0; //количество добовляемих файлов
    char file_app[SLEN];  //имя файла назначения
    char file_src[SLEN];  //имя исходного файла
    int ch;
    puts("Введите имя файла назначения: ");
    s_gets(file_app, SLEN);
    if ((fa = fopen(file_app, "a+")) == NULL)
    {
        fprintf(stderr, "Не удается открит %s\n", file_app);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("Не удается создать выходной вуфер\n", stderr);
        exit(EXIT_FAILURE);
    }
    puts("Введите имя первого исходного файла (или пустую строку для завершения): ");
    while (s_gets(file_src, SLEN) && file_src[0] != '\0')
    {
        if (strcmp(file_src, file_app) == 0)
        {
            fputs("Добавить файл в конце самого себя невозможно\n", stderr);
        }
        else if ((fs = fopen(file_src, "r")) == NULL)
        {
            fprintf(stderr, "Не удается открить %s\n", file_src);
        }
        else
        {
            if (setvbuf(fs, NULL, _IOFBF,  BUFSIZE) != 0)
            {
                fputs("Не удается создать выходной вуфер\n", stderr);
                continue;
            }
            append(fs, fa);
            if (ferror(fs) != 0)
            {
                fprintf(stderr, "Ошибка при чтении файла %s.\n", file_src);
            }
            if (ferror(fa) != 0)
            {
                fprintf(stderr, "Ошибка при чтении файла %s.\n", file_app);
            }
            fclose(fs);
            files++;
            printf("Содержимое файла %s добавлено.\n", file_src);
            puts("Введите имя следующего файла (или пустую строку для завершения): ");
        }
    }
    printf("Добавление завершено. Количество добавленних файлов: %d.\n", files);
    rewind(fa);
    printf("Содержимое %s:\n", file_app);
    while ((ch = getc(fa)) != EOF)
    {
        putchar(ch);
    }
    puts("Отображение завершено.");
    fclose(fa);
    return 0;
}