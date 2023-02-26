#include <stdio.h>
const int S_PER_M = 60;         //количество секунд в минуте
const int S_PER_H = 3600;       //количество минут в часе
const double M_PER_K = 0.62137; //количество миль в километре
int main(void)
{
    double distk, distm; //дистанция пробега в километрах
    double rate;         //средная скорост в милях в час
    int min, sec;        //время пробега в минутах и секундах
    int time;            //время пробега только в секундах
    double mtime;        //время пробега одной мили в секундах
    int mmin, msec;      //время пробега одной мили в минутах и секундах

    printf("Эеф программа преобразует время пробега дистанции в метрической системе\n"
    "во время пробега одной мили и вычисляет вашу среднюю\n"
    "скорост в ьшлях и часах\n"
    "Введите дистанцию пробега в километрах\n");
    scanf("%lf", &distk); //%lf для типа double
    printf("Введите время в ьинутах и секундах.\n");
    printf("Начните с ввода минут.\n");
    scanf("%d", &min);
    printf("Теперь введите секунды.\n");
    scanf("%d", &sec);

    time = S_PER_M * min + sec; //переводит время в секунды
    distm = M_PER_K * distk;    //переводит километри в мили
    rate = distm / time * S_PER_H; //умножает километры в секунду на количество секунд в часе дает количество миль в часе
    mtime = (double)time / distm;  //деление времени на ростояние даёт время пробега одной мили
    mmin = (int)mtime / S_PER_M;   //вичисление полного количества минут
    msec = (int)mtime / S_PER_M;   //вычисление остатка в секундах
    printf("Вы пробежали %1.2f км (%1.2f мили) за %d мин, %d сек.\n", distk, distm, min, sec);
    printf("Такая скорост соответствует пробегу одной мили за %d мин, ", mmin);
    printf("%d сек.\nВаша средная скорост составила %1.2f миль в секунду/\n", msec, rate);

    return 0;
}