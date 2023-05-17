#ifndef UNTITLED4_USER_LIST_H
#define UNTITLED4_USER_LIST_H
#include <stdio.h>
#include "../headers/user.h"

typedef struct User_list{
    struct User_list* prev;
    struct User_list* next;
    User* us;
}User_list;

void first_user(User* us, User_list** list);
void add_user (User_list** list, User* us);
void delete_user (User_list** list, User* us);
void print_users(User_list* list);
User* search_user(User_list * list, char* check_user); //FALTA HACERLA CORRECTAMENTE
void loading_users(FILE* fa, User_list** list);
void save_all_users(User_list* list, FILE* fa); //FALTA, Isaac lo hace


#endif //UNTITLED4_USER_LIST_H
