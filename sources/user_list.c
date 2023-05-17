
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


void first_user(User_list** list, char id_name[MAX_ID_NAME_LENGHT], char name[MAX_NAME_LENGHT], int edad, char password[MAX_PASSWORD_LENGHT], char correo[MAX_CORREO_LENGHT], char ciudad[MAX_CITY_LENGHT]){
    User_list* first = (User_list*) malloc(sizeof (User_list));
    first->us = (User*) malloc(sizeof (User));
    strcpy(first->us->id_name, id_name);
    strcpy(first->us->nombre, name);
    strcpy(first->us->contrasena, password);
    strcpy(first->us->ubicacion, ciudad);
    strcpy(first->us->correo, correo);
    first->us->edad = edad;
    first->next = NULL;
    first->prev = NULL;
    *list = first;
}

void add_user (User_list** list, char id_name[MAX_ID_NAME_LENGHT], char name[MAX_NAME_LENGHT], int edad, char password[MAX_PASSWORD_LENGHT], char correo[MAX_CORREO_LENGHT], char ciudad[MAX_CITY_LENGHT]){
    User_list* new_user = (User_list*) malloc(sizeof (User_list));
    new_user->us = (User*) malloc(sizeof (User));
    strcpy(new_user->us->id_name, id_name);
    strcpy(new_user->us->nombre, name);
    strcpy(new_user->us->contrasena, password);
    strcpy(new_user->us->ubicacion, ciudad);
    strcpy(new_user->us->correo, correo);
    new_user->next = NULL;
    new_user->prev = NULL;
    User_list* temp = *list;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_user;
    new_user->prev = temp;
}

void first_user_created(User_list** list, User* us){
    User_list* first = (User_list*) calloc(1, sizeof (User_list)); //User_list->User malloc
    first->next = NULL;
    first->prev = NULL;
    first->us = us;
    *list = first;
}

void add_user_created (User_list** list, User* us){
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
    char id_name[USERNAME_LENGTH], name[USERNAME_LENGTH], contrasena[PASSWORD_LENGTH], ubicacion[UBICATION_LENGTH], correo[USERNAME_LENGTH], gustos[5][GUSTOS];
    int edad;
    while (fscanf(fa, "%s %s %s %d %s %s", id_name, name, contrasena, &edad, correo, ubicacion) > 5) { //leer datos aquí
        if (*list == NULL) {
            first_user(list, id_name, name, edad, contrasena, correo, ubicacion);
        }
        else{
            add_user(list, id_name, name, edad, contrasena, correo, ubicacion);
        }
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
        printf("%s %s %s %d %s %s\n", heap->us->id_name, heap->us->nombre, heap->us->contrasena, heap->us->edad, heap->us->ubicacion, heap->us->correo/*, heap->us->gustos[0], heap->us->gustos[1], heap->us->gustos[2], heap->us->gustos[3], heap->us->gustos[4]*/);
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

