#include <stdio.h>
#include <stdlib.h>

typedef struct element{
    int data;
    struct element * next;
}t_element;

typedef struct lista{
    struct t_element * first;
    struct telement * last;
}t_lista;

