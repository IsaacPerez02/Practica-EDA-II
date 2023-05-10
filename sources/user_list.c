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

User_list* init_list (){
    User_list *list = NULL;
    list = (User_list*) malloc(sizeof (User_list));
    list->prev = NULL;
    list->next = NULL;
    list->us = NULL;
    return list;
}

void add_user (User_list* list, User* us){
    User_list* new_user = (User_list*) malloc(sizeof (User_list));
    new_user->us = us;
    new_user->next = NULL;
    new_user->prev = NULL;
    if (list->us == NULL){
        list = new_user;
        list->prev = NULL;
    }
    else{
        User_list* temp = list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_user;
        new_user->prev = temp;
    }
    printf("%s\n", list->us->nombre)
}

void delete_user (User_list * list, User* us){
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
}

void print_users(User_list* list){
    User_list* heap = list;
    printf("%s\n", list->us->id_name);
    while (heap != NULL){
        printf("HOLA");
        printf("%s %s %s %d %s %s %s %s %s %s %s\n", heap->us->id_name, heap->us->nombre, heap->us->contrasena, heap->us->edad, heap->us->ubicacion, heap->us->correo, heap->us->gustos[0], heap->us->gustos[1], heap->us->gustos[2], heap->us->gustos[3], heap->us->gustos[4]);
        heap = heap->next;
    }
}


/*
User search_user(User_list* list, User check_user) {
    User_list* heap = list;
    while (check_user.id_name != heap->us->id_name) {
        if (check_user.contrasena != '\0') {
            if (check_user.contrasena != heap->us->contrasena) {
                check_user.id_name = '\0';
                return check_user;
            }
        }
        heap = list->next;
    }

    check_user = *heap->us;
    return check_user;
}
*/