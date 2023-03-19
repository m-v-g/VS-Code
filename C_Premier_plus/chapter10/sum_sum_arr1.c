#include <stdio.h>
#define SIZE 10

int sum(int *ar, int n);
//int sum(int *ar, int n); //չի աշխատում
int main(void)
{
    int marbles[SIZE] = {20, 10, 5, 39, 4, 16, 19, 26, 31, 20};
    long answer;

    answer = sum(marbles, SIZE);
    printf("Общая сумма элементов массива marbles ровна %ld.\n", answer);
    printf("Обём памяти, отведенной под массив marbles, состовляет %zd байтов.\n", sizeof marbles);
    
    return 0;
}

int sum(int *ar, int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        //total += ar[i];
        total += *ar; //добавить значение к total переместит указатель на следующий элемент
    }
    printf("Размер ar состовляет %zd байтов.\n", sizeof ar);

    return total;
}