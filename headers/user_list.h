#ifndef UNTITLED4_USER_LIST_H
#define UNTITLED4_USER_LIST_H
#define MAX_ID_NAME_LENGHT 20
#define MAX_NAME_LENGHT 20
#define MAX_PASSWORD_LENGHT 20
#define MAX_CORREO_LENGHT 30
#define MAX_CITY_LENGHT 20
#define MAX_WORD_LENGHT 20
#include <stdio.h>
#include "user.h"
#include "dicctionary_topic.h"

typedef struct User_list{
    struct User_list* prev;
    struct User_list* next;
    User* us;
}User_list;

void first_user(User_list** list, char id_name[MAX_ID_NAME_LENGHT], char name[MAX_NAME_LENGHT], int code, int edad, char password[MAX_PASSWORD_LENGHT], char correo[MAX_CORREO_LENGHT], char ciudad[MAX_CITY_LENGHT], char gustos[5][GUSTOS_LENGTH]);
void add_user(User_list** list, char id_name[MAX_ID_NAME_LENGHT], char name[MAX_NAME_LENGHT], int code, int edad, char password[MAX_PASSWORD_LENGHT], char correo[MAX_CORREO_LENGHT], char ciudad[MAX_CITY_LENGHT], char gustos[5][GUSTOS_LENGTH]);
int create_code(User_list** list);
void first_user_created(User_list** list, User* us);
void add_user_created (User_list** list, User* us);
void add_file_users(User_list** list);
void delete_user (User_list** list, User* us);
void print_users(User_list* list);
User* search_user_id_name(User_list * list, char* check_user); //FALTA HACERLA CORRECTAMENTE
User* search_user_code(User_list* list, int code);
void loading_users(FILE* fa, User_list** list);
void save_all_users(User_list* list, FILE* fa); //FALTA, Isaac lo hace
User* check_user_password(User_list * list, char id_name[MAX_ID_NAME_LENGHT] ,char password[MAX_PASSWORD_LENGHT]);


#endif //UNTITLED4_USER_LIST_H
