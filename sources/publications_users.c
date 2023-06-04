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

// Función para mostrar el timeline de un usuario
void showTimeline(const Usuario* user) {
    printf("Timeline de %s:\n", user->username);
    Publication* current = user->timeline;
    int count = 1;
    while (current != NULL) {
        printf("%d. %s\n", count, current->text);
        current = current->next;
        count++;
    }
}

// Función para liberar la memoria utilizada por las publicaciones
void freeTimeline(Usuario* user) {
    Publication* current = user->timeline;
    while (current != NULL) {
        Publication* next = current->next;
        free(current);
        current = next;
    }
    user->timeline = NULL;
}
