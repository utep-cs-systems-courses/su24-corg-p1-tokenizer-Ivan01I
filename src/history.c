#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"
List* init_history(){
    List *list = (List *)malloc(sizeof(List));
    if(list == NULL){
        return NULL;
    }
    list->root = NULL;
    return list;
}
void add_history(List *list, char *str){
    if(list == NULL || str == NULL){
        return;
    }
    Item *new_item = (Item *)malloc(sizeof(Item));
    if(new_item == NULL){
        return;
    }
    static int id_counter = 1;
    new_item -> id = id_counter++;
    new_item -> str = strdup(str);
    if(new_item -> str == NULL){
        free(new_item);
        return;
    }
    new_item -> next = NULL;
    if(list -> root == NULL){
        list -> root = new_item;
    }
    else{
        Item *current = list->root;
        while(current -> next != NULL){
            current = current -> next;
        }
        current -> next = new_item;
    }
}
char *get_history(List *list, int id){
    if(list == NULL){
        return NULL;
    }
    Item *current = list -> root;
    while(current != NULL){
        if(current -> id == id){
            return current -> str;
        }
        current = current -> next;
    }
    return NULL;
}
void print_history(List *list){
    if(list == NULL){
        return;
    }
    Item *current = list -> root;
    while(current != NULL){
        printf("[%d] %s\n", current -> id, current -> str);
        current = current -> next;
    }
}
void free_history(List *list){
    if(list == NULL){
        return;
    }
    Item *current = list -> root;
    while(current != NULL){
        Item *next = current -> next;
        free(current -> str);
        free(current);
        current = next;
    }
    free(list);
}
