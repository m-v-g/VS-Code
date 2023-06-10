#include <stdio.h>
#include "names_st.h"

int main(void)
{
    names candidate;
    get_names(&candidate);
    printf("Добро пожаловать в программу, ");
    show_names(&candidate);
    printf("!\n");

    return 0;
}