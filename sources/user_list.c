#include "../headers/user.h"
#include "../headers/user_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_USERS 2
#define USERNAME_LENGTH 20 //Cantidad de caracteres máximo que puede tener un nombre de usuario
#define PASSWORD_LENGTH 30 //Cantidad de caracteres máximo que puede tener una contraseña
#define EMAIL_LENGTH 50 //Cantidad de caracteres máximo que puede tener un correo electrónico
#define UBICATION_LENGTH 20 //cantidad de caracteres de la ciudad


User_list* init_user(User* us){
    User_list* new_user = (User_list*) malloc(sizeof (User_list));
    new_user->us = us;
    new_user->next = NULL;
    new_user->prev = NULL;
    return new_user;
}

User_list* first_user(User* us){
    User_list* first_user = init_user(us);
    return first_user;
}

void add_user (User_list* list, User* us){
    User_list* new_user;
    new_user = init_user(us);
    User_list* temp = list;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_user;
    new_user->prev = temp;
}

User_list* delete_user (User_list * list, User* us){
    User_list* heap = list;
    while (heap->us->id_name != us->id_name){
        heap = list->next;
    }
    if (heap->next != NULL){
        heap->prev->next = heap->next;
        heap->next->prev = heap->prev;
    }
    else {
        heap->prev->next = heap->next;
    }
    free(heap);
    return list;
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

User_list* loading_users(FILE * fa){
    User* us;
    User_list* list;
    int* count;
    count = 0;
    us = init_user_txt(fa, count);
    printf("%s", us->id_name);
    /*while (count > 10) {
        if (list == NULL) {
            list = first_user(us);
        }
        else {
            add_user(list, us);
        }
        us = init_user_txt(fa, count);
    }
    return list;*/
}