#ifndef UNTITLED4_FRIENDS_STACK_H
#define UNTITLED4_FRIENDS_STACK_H
#include "../headers/user_list.h"
#define MAX_FRIENDS 10

typedef struct {
    int code;
    User friends[MAX_FRIENDS];
    int top;
    int size;
}Friends;



Friends* init_friends();
int count_friends(int friends[MAX_FRIENDS]);
int request(char id_name[MAX_ID_NAME_LENGHT], User_list* list);
void add_friend(int id_code, User_list* list);


#endif //UNTITLED4_FRIENDS_STACK_H
