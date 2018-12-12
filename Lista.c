/*
*Author: Mateus Leal Soares, Computer Science student.
*About: Implementation of a simple list in C language.
*Studied on Data Structures discipline at University of Brasilia.
*/

#include <stdio.h>
#include <stdlib.h>

//Define the struct of all elements that composes a list
typedef struct element{
    int data;
    struct element * next;
}t_element;

//Define the head and tail of a list
typedef struct list{
    struct t_element * head;
    struct t_element * tail;
}t_list;

//Create a empty list
t_list * createList(){
    t_list * l = (t_list*)malloc(sizeof(t_list));
    if(l == NULL){
        printf("Could not create a list.\n");       //Error at allocation
        return;
    }
    l->head = NULL;                                 //Empty list
    l->tail = NULL;
    return (l);
}

//Print the content of the elements of the list
void printList(t_list * l){
    t_element * current = l->head;
    if(current == NULL){
        printf("Empty list.\n");                    //Head = Null, the list is empty
        return;
    }
    while(current != NULL){
        printf("%d ", current->data);               //Print the data of the elements
        current = current->next;
    }
}

//Insert an element/value on the list based on the positon passed as argument
void insert(int position, int value, t_list * l){
    if(position < 0){
        printf("Invalid position. Starts from zero (0).\n");
        return;                                     //Positions starts from 0
    }
    if(l->head == NULL){                            //In case of empty list
        printf("Empty list. The value will be inserted in the first position (0).\n");
        t_element * new = (t_element *)malloc(sizeof(t_element));
        new->data = value;
        new->next = NULL;
        l->head = new;                              //Head and tail points to the new element as its the only one
        l->tail = new;
        return;                                     //return
    }
    //and in case its not a empty list, do the following
    t_element * current = l->head;                  //Set an auxiliar element and its previous one
    t_element * previous = NULL;
    t_element * new = (t_element *)malloc(sizeof(t_element));   //Create the element we want to insert
    new->data = value;
    for(int i = 0; i < position && current != NULL; i++){
        previous = current;                         //Use the auxiliar elements to go through the list, it will stop when find the position to insert an element or when the list is finished
        current = current->next;
    }
    if(current != NULL){                            //If the list has not finished it means we find the correct position to insert
        if(current == l->head){                     //If this position is the first one, we push the list to the right and insert
            new->next = l->head;
            l->head = new;
        }else{                                      //Else insert in middle of a list consists in pushing the list after position to the left
            new->next = current;                    //Insert the new in the position of the current one, and set previous pon=inter to the new
            previous->next = new;
        }
    }else{                                          //The position exceed the size of the list, insert in the end
        printf("The asked position is the last one or exceed the size of the list. Inserted in last position.\n");
        previous->next = new;                       //Set previous pointer to the new
        new->next = NULL;                           //Set the new pointer to null, and tail to the new
        l->tail = new;
    }
    return;
}

//Remove an element in the given position, returning the value of the element
int remove(int position, t_list * l){
    if(l->head == NULL){                            //If the list is empty, nothing can be removed
        printf("Empty list. Cannot remove any element.\n");
        return -1;
    }
    if(position < 0){                               //If the position is negative we did not selected any element
        printf("Position is invalid. Starts from zero (0).\n");
        return -1;
    }
    t_element * removed = l->head;                  //Set auxiliary elements. The one we want to remove and its previous
    t_element * previous = NULL;
    for(int i = 0; i < position && removed != NULL; i++){   //Go through the list till we find the position or the list has finished
        previous = removed;
        removed = removed->next;
    }
    if(removed != NULL){                            //If the list has not finished we've found the elements position
        int tmp = removed->data;                    //Save the value of the element in an auxiliar variable before removing it
        if(l->head == removed){                     //If we want to remove is the first one, set head to the next
            l->head = removed->next;
        }else{
            previous->next = removed->next;         //Else: remove from the middle of the list by setting previous pointing to the next
        }
        if(l->tail == removed){
            l->tail = previous;                     //If the element we want to remove is the last one, set tail to the previous one
            previous->next = NULL;                  //And previous points to null
        }
        free(removed);                              //Free the allocated space of the element we want to remove
        return tmp;                                 //Return the value of the removed element
    }
    printf("The list has finished and we could not find the element to be removed.\n"); //Else the list has finished and the position to be removed was not find
    return -1;
}