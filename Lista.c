#include <stdio.h>
#include <stdlib.h>

typedef struct element{
    int data;
    struct element * next;
}t_element;

typedef struct list{
    struct t_element * first;
    struct t_element * last;
}t_list;

t_list * createList(){
    t_list * l = (t_list*)malloc(sizeof(t_list));
    if(l == NULL){
        printf("Could not create a list.\n");
        return;
    }
    l->first = NULL;
    l->last = NULL;
    return (l);
}

void printList(t_list * l){
    t_element * current = l->first;
    if(current == NULL){
        printf("Empty list.\n");
        return;
    }
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
}

void insert(int position, int value, t_list * l){
    if(position < 0){
        printf("Invalid position. Starts from zero (0).\n");
        return;
    }
    if(l->first == NULL){
        printf("Empty list. The value will be inserted in the first position (0).\n");
        t_element * new = (t_element *)malloc(sizeof(t_element));
        new->data = value;
        new->next = NULL;
        l->first = new;
        l->last = new;
        return;
    }
    t_element * current = l->first;
    t_element * previous = NULL;
    t_element * new = (t_element *)malloc(sizeof(t_element));
    new->data = value;
    for(int i = 0; i < position && current != NULL; i++){
        previous = current;
        current = current->next;
    }
    if(current != NULL){
        if(current == l->first){
            new->next = l->first;
            l->first = new;
        }else{
            new->next = current;
            previous->next = new;
        }
    }else{
        printf("The asked position is the last one or exceed the size of the list. Inserted in last position.\n");
        previous->next = new;
        new->next = NULL;
        l->last = new;
    }
    return;
}

int remove(int position, t_list * l){
    if(l->first == NULL){
        printf("Empty list. Cannot remove any element.\n");
        return -1;
    }
    if(position < 0){
        printf("Position is invalid. Starts from zero (0).\n");
        return -1;
    }
    t_element * removed = l->first;
    t_element * previous = NULL;
    for(int i = 0; i < position && removed != NULL; i++){
        previous = removed;
        removed = removed->next;
    }
    if(removed != NULL){
        int tmp = removed->data;
        if(l->first == removed){
            l->first = removed->next;
        }else{
            previous->next = removed->next;
        }
        if(l->last == removed){
            l->last = previous;
            previous->next = NULL;
        }
        free(removido);
        return tmp;
    }
    printf("The list has finished and we could not find the element to be removed.\n");
    return -1;
}