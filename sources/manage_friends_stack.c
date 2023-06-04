#include "../headers/manage_friends_stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Manege_Friends* init_manage_friends(){
    Manege_Friends* manage = (Manege_Friends*) malloc(sizeof (Manege_Friends));
    manage->next = NULL;
    return manage;
}

void add_manage_friends(Manege_Friends* manege, int code){
    Manege_Friends* heap = manege;
    while (heap->next != NULL){
        heap = heap->next;
    }
    Manege_Friends* new_manage = (Manege_Friends*) malloc(sizeof (Manege_Friends));
    Friends* new = (Friends*) malloc(sizeof (Friends));
    new->code_user = code;
    new_manage->friends = new;
    new_manage->next = NULL;
    heap->next = new_manage;
}

Friends* search_list_friends(Manege_Friends* manage, int code_user){
    Manege_Friends* heap = manage;
    while (heap->next != NULL){
        if (heap->friends->code_user == code_user){
            return heap->friends;
        }
        heap = heap->next;
    }
    if (heap->friends->code_user == code_user){
        return heap->friends;
    }
    return NULL;
}