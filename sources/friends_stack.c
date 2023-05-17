#include "../headers/friends_stack.h"

Friends* init_friends(){
    Friends* friends = NULL;
    friends->top = 0;
    friends->size = 0;
    return friends;
}
