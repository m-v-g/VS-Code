/*определение и использование полей*/
#include <stdio.h>
#include <stdbool.h> //C99, представление bool, true, false
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

void show_settings(const struct box_props * pb);

int main(void)
{
    /*создание иницализация структуры box_props*/
    struct box_props box = {true, YELLOW, true, GREEN, DASHED};
    printf("Исходные настройки окна:\n");
    show_settings(&box);

    box.opeque = false;
    box.fill_color = WHITE;
    box.border_coior = MAGENTA;
    box.border_style = SOLID;
    printf("\nИзмененые настройки окна:\n");
    show_settings(&box);
    return 0;
}

void show_settings(const struct box_props * pb)
{
    printf("Окно %s.\n", pb->opeque == true ? "непрозрачно" : "прозрачно");
    printf("Цвет фона %s.\n", colors[pb->fill_color]);
    printf("Рамуа %s.\n", pb->show_border == true ? "отображать" : "не отображать");
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