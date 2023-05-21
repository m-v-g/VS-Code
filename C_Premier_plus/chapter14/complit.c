/*составные литералы*/
#include <stdio.h>
#define MAXTITL 81
#define MAXAUTL 31

struct book //шаблон структуры: book - дескриптор
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(void)
{
    struct book readfirst;
    int score;
    printf("Введите рейтинг: ");
    scanf("%d", &score);
    if (score >= 84)
    {
        readfirst = (struct book) {"Преступление и наказание",
                                   "Федор Достоевскй",
                                   11.25};
    }
    else
    {
        readfirst = (struct book) {"Красивая шляпа мистера Баунси",
                                   "Фрейд Уинсом",
                                   5.99};
    }
    printf("Назначенные вами рейтинги:\n");
    printf("%s авторства %s: $%.2f\n", readfirst.title, readfirst.author, readfirst.value);
    return 0;
}