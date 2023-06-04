#ifndef UNTITLED4_PUBLICATIONS_USERS_H
#define UNTITLED4_PUBLICATIONS_USERS_H
#include "../headers/user.h"
#define MAX_CHARACTERS 120

#define MAX_TEXT_LENGTH 120

typedef struct Node {
    char text[MAX_TEXT_LENGTH + 1];
    struct Node* next;
    struct Node* prev;
} Node;

Node* init_node(char text[MAX_TEXT_LENGTH + 1]);
void addPost(Node* timeline, char text[MAX_TEXT_LENGTH + 1]);
void printTimeline(Node* timeline);

#endif //UNTITLED4_PUBLICATIONS_USERS_H
