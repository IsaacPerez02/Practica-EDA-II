#ifndef UNTITLED4_PUBLICATIONS_USERS_H
#define UNTITLED4_PUBLICATIONS_USERS_H
#include "../headers/user.h"
#define MAX_CHARACTERS 120

// Definición de la estructura de una publicación
typedef struct Publication {
    char text[MAX_CHARACTERS + 1];
    struct Publication* next;
} Publication;

// Definición de la estructura de un usuario
typedef struct User1 {
    char username[50];
    Publication* timeline;
} Usuario;


Publication* createPublication(const char* text);
void addPublicationToTimeline(Usuario* user, const char* text);
void showTimeline(const Usuario* user);
void freeTimeline(Usuario* user);


#endif //UNTITLED4_PUBLICATIONS_USERS_H
