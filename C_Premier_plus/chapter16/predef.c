#include <stdio.h>

#if __STDC_VERSION__ != 201710L
#error НЕСООТВЕТСТВИЕ C11
#endif

void why_me(void);

int main(void)
{
    printf("Файл: %s.\n", __FILE__);
    printf("Дата: %s.\n", __DATE__);
    printf("Время: %s.\n", __TIME__);
    printf("Версия: %ld.\n", __STDC_VERSION__);
    printf("Это строка: %d.\n", __LINE__);
    printf("Это функсия: %s.\n", __func__);

    why_me();
    return 0;
}

void why_me(void)
{
    printf("Это строка: %d.\n", __LINE__);
    printf("Это функсия: %s.\n", __func__);
#line 1000
    printf("Это строка: %d.\n", __LINE__);
#line 5000 "cool.c"
    printf("Это строка: %d.\n", __LINE__);
    printf("Файл: %s.\n", __FILE__);
}