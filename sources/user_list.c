
#include "../headers/user.h"
#include "../headers/user_list.h"
#define FALSE 0
#define TRUE 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ID_NAME_LENGHT 20
#define MAX_NAME_LENGHT 20
#define MAX_PASSWORD_LENGHT 20
#define MAX_CORREO_LENGHT 30
#define MAX_CITY_LENGHT 20
#define MAX_GUSTOS 10
#define GUSTOS_LENGTH 20
#include <time.h>
#define LINEA_ASTERISCOS "********************"
#define LINEA_GUION "---------------"

//Función para añadir al primer usuario a la lista en caso de que solo haya un usuario en el archivo de usuarios
void first_user(User_list** list, char id_name[MAX_ID_NAME_LENGHT], char name[MAX_NAME_LENGHT], int code, int edad, char password[MAX_PASSWORD_LENGHT], char correo[MAX_CORREO_LENGHT], char ciudad[MAX_CITY_LENGHT], char gustos[5][GUSTOS_LENGTH]){
    User_list* first = (User_list*) malloc(sizeof (User_list));
    first->us = (User*) malloc(sizeof (User));
    strcpy(first->us->id_name, id_name);
    strcpy(first->us->nombre, name);
    strcpy(first->us->contrasena, password);
    strcpy(first->us->ubicacion, ciudad);
    strcpy(first->us->correo, correo);
    first->us->code = code;
    first->us->edad = edad;
    strcpy(first->us->gustos[0], gustos[0]);
    strcpy(first->us->gustos[1], gustos[1]);
    strcpy(first->us->gustos[2], gustos[2]);
    strcpy(first->us->gustos[3], gustos[3]);
    strcpy(first->us->gustos[4], gustos[4]);
    first->next = NULL;
    first->prev = NULL;
    *list = first;
}

//Función para añadir a un usuario a la lista con usuarios ya introducidos del archivo de usuarios
void add_user(User_list** list, char id_name[MAX_ID_NAME_LENGHT], char name[MAX_NAME_LENGHT], int code, int edad, char password[MAX_PASSWORD_LENGHT], char correo[MAX_CORREO_LENGHT], char ciudad[MAX_CITY_LENGHT], char gustos[5][GUSTOS_LENGTH]){
    User_list* new_user = (User_list*) malloc(sizeof (User_list));
    new_user->us = (User*) malloc(sizeof (User));
    strcpy(new_user->us->id_name, id_name);
    strcpy(new_user->us->nombre, name);
    strcpy(new_user->us->contrasena, password);
    strcpy(new_user->us->ubicacion, ciudad);
    strcpy(new_user->us->correo, correo);
    new_user->us->code = code;
    new_user->us->edad = edad;
    strcpy(new_user->us->gustos[0], gustos[0]);
    strcpy(new_user->us->gustos[1], gustos[1]);
    strcpy(new_user->us->gustos[2], gustos[2]);
    strcpy(new_user->us->gustos[3], gustos[3]);
    strcpy(new_user->us->gustos[4], gustos[4]);
    new_user->next = NULL;
    new_user->prev = NULL;
    User_list* temp = *list;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_user;
    new_user->prev = temp;
}

//Creamos el código del usuario introducido y creamos la lista en caso de que la lista esté vacía
void first_user_created(User_list** list, User* us){
    int code = create_code(list);
    User_list* first = (User_list*) calloc(1, sizeof (User_list));
    first->next = NULL;
    first->prev = NULL;
    first->us = us;
    first->us->code = code;
    *list = first;
}

//Creamos el código del usuario introducido y lo añadimos a la lista de usuarios
void add_user_created (User_list** list, User* us){
    int code = create_code(list);
    User_list* new_user = (User_list*) malloc(sizeof (User_list));
    new_user->next = NULL;
    new_user->prev = NULL;
    new_user->us = us;
    new_user->us->code = code;
    new_user->us->code = create_code(list);
    User_list* temp = *list;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_user;
    new_user->prev = temp;
}

//Cogemos a todos los usuarios del archivo y los añadimos a la lista
void loading_users(FILE * fa, User_list** list){
    char id_name[MAX_ID_NAME_LENGHT], name[MAX_NAME_LENGHT], contrasena[MAX_PASSWORD_LENGHT], ubicacion[MAX_CITY_LENGHT], correo[MAX_CORREO_LENGHT], gustos[5][GUSTOS_LENGTH];
    int edad, code;
    while (fscanf(fa, "%s %s %d %s %d %s %s %s %s %s %s %s", id_name, name, &code, contrasena, &edad, correo, ubicacion, gustos[0], gustos[1], gustos[2], gustos[3], gustos[4]) > 5) { //leer datos aquí
        if (*list == NULL) {
            first_user(list, id_name, name, code, edad, contrasena, correo, ubicacion, gustos);
        }
        else{
            add_user(list, id_name, name, code, edad, contrasena, correo, ubicacion, gustos);
        }
    }
}

//Al cerrar el programa, guardamos a todos los usuarios de la lista en el archivo
void save_all_users(User_list* list, FILE* fa){
    User_list* heap = list;
    while (heap->next != NULL){
        fprintf(fa, "%s %s %d %s %d %s %s %s %s %s %s %s\n", heap->us->id_name, heap->us->nombre, heap->us->code, heap->us->contrasena, heap->us->edad, heap->us->correo, heap->us->ubicacion, heap->us->gustos[0], heap->us->gustos[1], heap->us->gustos[2], heap->us->gustos[3], heap->us->gustos[4]);
        heap = heap->next;
    }
    fprintf(fa, "%s %s %d %s %d %s %s %s %s %s %s %s\n", heap->us->id_name, heap->us->nombre, heap->us->code, heap->us->contrasena, heap->us->edad, heap->us->correo, heap->us->ubicacion, heap->us->gustos[0], heap->us->gustos[1], heap->us->gustos[2], heap->us->gustos[3], heap->us->gustos[4]);
}

//Borramos a un usuario introducido de la lista
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

//Mostramos la información de todos los usuarios de la lista
void print_users(User_list* list){
    User_list* heap = list;
    while (heap != NULL){
        printf("***Nombre usuario: %s***\n", heap->us->id_name);
        printf("Nombre: %s\n", heap->us->nombre);
        printf("Código: %d\n", heap->us->code);
        printf("Contraseña: %s\n", heap->us->contrasena);
        printf("Edad: %d\n", heap->us->edad);
        printf("Ubicación: %s\n", heap->us->ubicacion);
        printf("Correo: %s\n", heap->us->correo);
        printf("Gustos: %s, %s, %s, %s, %s\n", heap->us->gustos[0], heap->us->gustos[1], heap->us->gustos[2], heap->us->gustos[3], heap->us->gustos[4]);
        //printf("%s %s %d %s %d %s %s %s %s %s %s %s\n", heap->us->id_name, heap->us->nombre, heap->us->code, heap->us->contrasena, heap->us->edad, heap->us->ubicacion, heap->us->correo, heap->us->gustos[0], heap->us->gustos[1], heap->us->gustos[2], heap->us->gustos[3], heap->us->gustos[4]);
        printf("%s\n", LINEA_GUION);
        heap = heap->next;
    }
}

//Función de buscar a un usuario de la lista por su nombre de usuario. Si está en la lista, lo devolvemos
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

//Función de verificar el nombre de usuario y su contraseña para poder iniciar sesión
User* check_user_password(User_list * list, char id_name[MAX_ID_NAME_LENGHT] ,char password[MAX_PASSWORD_LENGHT]){
    User_list* heap = list;
    while (heap->next != NULL) {
        if (strcmp(id_name, heap->us->id_name) == 0){
            if(strcmp(password, heap->us->contrasena) == 0){
                return heap->us; //devolvemos el usuario que inicia sesion
            }
            else {
                return NULL;
            }
        }
        heap = heap->next;
    }
    //por si casualmente el usuario en iniciar sesion es el ultimo de la lista volvemos a comprobar
    if (strcmp(id_name, heap->us->id_name) == 0){
        if(strcmp(password, heap->us->contrasena) == 0){
            return heap->us; //devolvemos el usuario que inicia sesion
        }
        else {
            return NULL;
        }
    }
    return NULL; //si no esta devolvemos NULL
}

//Genera un número del 100000 al 999999
int create_code(User_list** list) {
    int code;
    time_t t;
    User_list* temp = *list; //Creamos una copia de la lista para navegar por todos los usuarios
    srand((unsigned) time(&t));
    code = rand() % 1000000 + 100000; //Generamos un código
    if (temp == NULL){
        return code;
    }

    //Comprobamos en cada usuario si su código coincide con el código generado
    while (temp->next != NULL) {
        //Si es el caso, creamos otro código y volvemos a revisar todos los usuarios
        if (code == temp->us->code) {
            srand((unsigned) time(&t));
            code = rand() % 1000000 + 100000;
            temp = *list;
        }
        else { //Si no es el caso, pasamos a revisar al siguiente usuario
            temp = temp->next;
        }
    }
    return code; //Al final, devolvemos el código que no coincida con ningún otro usuario
}

