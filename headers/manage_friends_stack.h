#ifndef UNTITLED4_MANAGE_FRIENDS_STACK_H
#define UNTITLED4_MANAGE_FRIENDS_STACK_H
#include "../headers/friends_stack.h"

/**
 * Manage_Friend_stack para manejar todos los Friends_stack de usuarios
 */
typedef struct Manege_Friends{
    struct Manege_Friends* next;
    Friends* friends;
}Manege_Friends;

Manege_Friends* init_manage_friends();
void add_manage_friends(Manege_Friends* manege, int code);
Friends* search_list_friends(Manege_Friends* manage, int code_user);

#endif //UNTITLED4_MANAGE_FRIENDS_STACK_H
