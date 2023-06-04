#include <malloc.h>
#include "../headers/friends_stack.h"
#define ERROR -1

int count_friends(User friends[MAX_FRIENDS]){
    int counter = 0;
    for (int i = 0; i < MAX_FRIENDS; ++i) {
        if (friends[i].code != 0){
            counter++;
        }
    }
    return counter;
}

int search_friends(Friends* friends, int id_code){
    for (int i = 0; i < MAX_FRIENDS; i++){
        if (id_code == friends->friends[i].code){
            return i;
        }
    }
    return -1;
}

void add_friends(Friends* friends, int new_id_code, User_list* list){
    int count = count_friends(friends->friends);
    User* us;
    us = search_user_code(list, new_id_code);
    friends->friends[count + 1] = *us;
}

void delete_friends(Friends* friends, int id_code){

}