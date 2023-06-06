#ifndef UNTITLED4_FRIENDS_GRAPH_H
#define UNTITLED4_FRIENDS_GRAPH_H
#include <malloc.h>
#include "user_list.h"

typedef struct {
    int code_user;
    int num_friends;
    int code_friends[MAX_FRIENDS];
}Friends;

Friends* init_friends_user(User_list* list);
void load_friends(Friends* friends, FILE* ff);
void print_friends_graph(Friends* friends);

#endif //UNTITLED4_FRIENDS_GRAPH_H
