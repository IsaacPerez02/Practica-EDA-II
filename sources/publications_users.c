#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "../headers/publications_users.h"
#include "../headers/publications_users.h"

// Función para crear una nueva publicación
Publication* createPublication(const char* text) {
    Publication* newPublication = (Publication*)malloc(sizeof(Publication));
    strncpy(newPublication->text, text, MAX_CHARACTERS);
    newPublication->text[MAX_CHARACTERS] = '\0';
    newPublication->next = NULL;
    return newPublication;
}

// Función para agregar una publicación al timeline de un usuario
void addPublicationToTimeline(Usuario* user, const char* text) {
    Publication* newPublication = createPublication(text);
    if (user->timeline == NULL) {
        user->timeline = newPublication;
    } else {
        Publication* current = user->timeline;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newPublication;
    }
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
