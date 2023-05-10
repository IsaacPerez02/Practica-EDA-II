#ifndef UNTITLED4_USER_LIST_H
#define UNTITLED4_USER_LIST_H
#include <stdio.h>
#include "../headers/user.h"

typedef struct User_list{
    struct User_list* prev;
    struct User_list* next;
    User* us;
}User_list;

User_list* init_list ();
void add_user (User_list * list, User* us);
void delete_user (User_list * list, User* us);
User login_user(User_list * list);
User search_user(User_list * list, User check_user);

#endif //UNTITLED4_USER_LIST_H
