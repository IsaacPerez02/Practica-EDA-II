#ifndef UNTITLED4_FRIENDS_GRAPH_H
#define UNTITLED4_FRIENDS_GRAPH_H
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "defines.h"
#include "user_list.h"

typedef struct {
    int code_user;
    int num_friends;
    int code_friends[MAX_FRIENDS];
}Friends;

Friends* init_friends_user();
void load_friends(Friends* friends, FILE* ff);
void new_user_friends(Friends* friends, int new_user_code);
void add_friend(Friends* friends, int new_friend);
void delete_friend(Friends* friends, int delete_friend);
Friends* search_user_friends(Friends* friends, int code_user);
void save_friends(Friends* friends, FILE* ff);
void print_friends_graph(Friends* friends);

#endif //UNTITLED4_FRIENDS_GRAPH_H
