#ifndef UNTITLED4_USER_LIST_H
#define UNTITLED4_USER_LIST_H
#include <stdio.h>
#include "../headers/user.h"

typedef struct User_list{
    struct User_list* prev;
    struct User_list* next;
    User* us;
}User_list;

User_list* init_user(User* us);
User_list* first_user(User* us);
void add_user (User_list* list, User* us);
User_list* delete_user (User_list* list, User* us);
void print_users(User_list* list);
User* search_user(User_list * list, char check_user); //FALTA HACERLA CORRECTAMENTE
void save_all_users(User_list* list, FILE* fa); //FALTA

#endif //UNTITLED4_USER_LIST_H
