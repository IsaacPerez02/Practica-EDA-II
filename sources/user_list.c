
#include "../headers/user.h"
#include "../headers/user_list.h"
#define FALSE 0
#define TRUE 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define USERNAME_LENGTH 20 //Cantidad de caracteres máximo que puede tener un nombre de usuario
#define PASSWORD_LENGTH 30 //Cantidad de caracteres máximo que puede tener una contraseña
#define EMAIL_LENGTH 50 //Cantidad de caracteres máximo que puede tener un correo electrónico
#define UBICATION_LENGTH 20 //cantidad de caracteres de la ciudad


void first_user(User* us, User_list** list){
    User_list* first = (User_list*) malloc(sizeof (User_list));
    first->next = NULL;
    first->prev = NULL;
    first->us = us;
    *list = first;
}

void add_user (User_list** list, User* us){
    User_list* new_user = (User_list*) malloc(sizeof (User_list));
    new_user->next = NULL;
    new_user->prev = NULL;
    new_user->us = us;
    User_list* temp = *list;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_user;
    new_user->prev = temp;
}

void loading_users(FILE * fa, User_list** list){
    User* us;
    us = init_user_txt(fa);
    while (us != NULL) {
        if (list == NULL) {
            first_user(us, list);
        }
        else{
            add_user(list, us);
        }
        us = init_user_txt(fa);
    }
}

void delete_user (User_list** list, User* us){
    User_list* heap = *list;
    while (heap->us->id_name != us->id_name){
        heap = heap->next;
    }
    if (heap->next != NULL){
        heap->prev->next = heap->next;
        heap->next->prev = heap->prev;
    }
    else {
        heap->prev->next = heap->next;
    }
    free(heap);
}

void print_users(User_list* list){
    User_list* heap = list;
    while (heap != NULL){
        printf("%s %s %s %d %s %s %s %s %s %s %s\n", heap->us->id_name, heap->us->nombre, heap->us->contrasena, heap->us->edad, heap->us->ubicacion, heap->us->correo, heap->us->gustos[0], heap->us->gustos[1], heap->us->gustos[2], heap->us->gustos[3], heap->us->gustos[4]);
        heap = heap->next;
    }
}

User* search_user(User_list* list, char* check_user) {
    User_list* heap = list;
    while (heap->next != NULL){
        if (strcmp(heap->us->id_name, check_user) == 0) {
            return heap->us;
        }
        heap = heap->next;
    }
    return NULL;
}

User* check_user_password(User_list * list, char* check_password) {
    User_list* heap = list;
    while (heap->next != NULL) {
        if (strcmp(heap->us->contrasena, check_password) == 0) {
            return heap->us;
        }
        heap = heap->next;
    }
    return NULL;
}

