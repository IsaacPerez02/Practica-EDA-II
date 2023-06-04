#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/publications_users.h"
#include "../headers/user.h"

Node* init_node(char text[MAX_TEXT_LENGTH + 1]){
    Node* newNode = (Node*) malloc(sizeof (Node));
    strcpy(newNode->text, text);
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void addPost(Node* timeline, char text[MAX_TEXT_LENGTH + 1]){
    Node* newNode = init_node(text);
    if (timeline == NULL){
        timeline = newNode;
    }
    else{
        Node* heap = timeline;
        while (heap->next != NULL){
            heap = heap->next;
        }
        heap->next = newNode;
        newNode->prev = heap;
    }
}


void printTimeline(Node* timeline){
    Node* heap = timeline;
    while (heap->next != NULL){
        printf("%s\n", heap->text);
        heap = heap->next;
    }
    printf("%s\n", heap->text);
}
