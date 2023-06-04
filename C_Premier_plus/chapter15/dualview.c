/*битовые поля и побитовые операции*/
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

/* КОНСТАНТЫ БИТОВЫХ ПОЛЕЙ */
/* стили линии */
#define SOLID 0
#define DOTTED 1
#define DASHED 2
/* основние цвета */
#define BLUE 4
#define GREEN 2
#define RED 1
/* смешенние цвета */
#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)

/* ПОБИТОВЫЕ КОНСТАНТЫ */
#define OPAQUE       0x1
#define FILL_BLUE    0x8
#define FILL_GREEN    0x4
#define FILL_RED     0x2
#define FILL_MASK    0xE
#define BORDER       0x100
#define BORDER_BLUE  0x800
#define BORDER_GREEN 0x400
#define BORDER_RED   0x200
#define BORDER_MASK  0xE00
#define B_SOLID      0
#define B_DOTTED     0x1000
#define B_DASHED     0x2000
#define STYLE_MASK   0x3000

const char * colors[8] = {"черный", "красный", "зеленый", "желтый", "синий", "пурпурный", "голубой", "белый"};
struct box_props
{
    bool opeque                 : 1;
    unsigned int fill_color     : 3;
    unsigned int                : 4;
    bool show_border            : 1;
    unsigned int border_coior   : 3;
    unsigned int border_style   : 2;
    unsigned int                : 2; 
};

union Views //взгляд на данные как на struct или как на unsigned short
{
    struct box_props st_view;
    unsigned short us_view;
};

void show_settings(const struct box_props * pb);
void show_settings1(unsigned short);
char * itobs(int n, char * ps);

int main(void)
{
    /*создание обекта Views, иницализация представления в виде структуры*/
    union Views box = {{true, YELLOW, true, GREEN, DASHED}};
    char bin_str[8 * sizeof(unsigned int) + 1];

    printf("Исходные настройки окна:\n");
    show_settings(&box.st_view);
    printf("\nНастройки окна с использованием представления unsigned short:\n");
    show_settings1(box.us_view);
    printf("комбинация битов %s\n", itobs(box.us_view, bin_str));

    box.us_view &= ~FILL_MASK;               //очистить бити фона
    box.us_view |= (FILL_BLUE | FILL_GREEN); //переустановит фон
    box.us_view ^= OPAQUE;                   //переключить прозрачность
    box.us_view |=BORDER_RED;                //ошибочный подход
    box.us_view &= ~STYLE_MASK;              //очистить бити стиля
    box.us_view |= B_DOTTED;                 //установить пунктирный стиль

    printf("\nИзмененые настройки окна:\n");
    show_settings(&box.st_view);
    printf("\nНастройки окна с использованием представления unsigned short:\n");
    show_settings1(box.us_view);
    printf("комбинация битов %s\n", itobs(box.us_view, bin_str));

    return 0;
}

void show_settings(const struct box_props * pb)
{
    printf("Окно %s.\n", pb->opeque == true ? "непрозрачно" : "прозрачно");
    printf("Цвет фона %s.\n", colors[pb->fill_color]);
    printf("Рамка %s.\n", pb->show_border == true ? "отображать" : "не отображать");
    printf("Цвет рамки %s.\n", colors[pb->border_coior]);
    printf("Стиль рамки ");
    switch (pb->border_style)
    {
    case SOLID:
        printf("сплошной.\n");
        break;
    
    case DOTTED:
        printf("пунктирный.\n");
        break;
    
    case DASHED:
        printf("штриховый.\n");
        break;
    
    default:
        printf("неизвестного типа.\n");
        break;
    }
}

void show_settings1(unsigned short us)
{
    printf("Окно %s.\n", (us & OPAQUE) == true ? "непрозрачно" : "прозрачно");
    printf("Цвет фона %s.\n", colors[(us >> 1) & 07]);
    printf("Рамка %s.\n", (us & BORDER) == true ? "отображать" : "не отображать");
    printf("Цвет рамки %s.\n", colors[(us >> 9) & 07]);
    printf("Стиль рамки ");
    switch (us & STYLE_MASK)
    {
    case SOLID:
        printf("сплошной.\n");
        break;
    
    case DOTTED:
        printf("пунктирный.\n");
        break;
    
    case DASHED:
        printf("штриховый.\n");
        break;
    
    default:
        printf("неизвестного типа.\n");
        break;
    }
}

char * itobs(int n, char * ps)
{
    const static int size = CHAR_BIT * sizeof(int);
    for (int i = size - 1; i >= 0; i--, n >>= 1)
    {
        ps[i] = (01 & n) + '0';
    }
    ps[size] = '\0';
    return ps;
}