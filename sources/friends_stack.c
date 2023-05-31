#include "../headers/friends_stack.h"
#define ERROR -1

Friends* init_friends(){
    Friends* friends = NULL;
    friends->top = 0;
    friends->size = 0;
    return friends;
}

int count_friends(int friends[MAX_FRIENDS]){
    int counter = 0;
    for (int i = 0; i < MAX_FRIENDS; ++i) {
        if (friends[i] != 0){
            counter ++;
        }
    }
    return counter;
}

int request(char id_name[MAX_ID_NAME_LENGHT], User_list* list){
    User* us;
    us = search_user_id_name(list, id_name);
    if (us != NULL){
        return us->code;
    }
    else {
        return ERROR;
    }
}

void add_friend(int id_code, User_list* list){
    User* us;
    us = search_user_code(list, id_code);
}