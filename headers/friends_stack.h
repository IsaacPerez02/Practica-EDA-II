#ifndef UNTITLED4_FRIENDS_STACK_H
#define UNTITLED4_FRIENDS_STACK_H
#include "../headers/user_list.h"
#define MAX_FRIENDS 10

/**
 * Friends_stack de un solo usuario
 */
typedef struct {
    int code_user;
    User friends[MAX_FRIENDS];
}Friends;

int count_friends(User friends[MAX_FRIENDS]);
void add_friends(Friends* friends, int new_id_code, User_list* list);
void delete_friends(Friends* friends, int id_code);
int search_friends(Friends* friends, int id_code);

#endif //UNTITLED4_FRIENDS_STACK_H
