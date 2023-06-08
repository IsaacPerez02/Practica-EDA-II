#ifndef UNTITLED4_PUBLICATIONS_USERS_H
#define UNTITLED4_PUBLICATIONS_USERS_H

#include "user_list.h"
#include "defines.h"
#include "friends_graph.h"

/**
 * Arreglo de publicaciones de un usuario
 * code_user: Código de la lista de publicaciones de un usuario
 * publication: Publicaciones del usuario
 */
typedef struct {
    int code_user;
    char publication[MAX_TEXT_LENGTH];
} Publications;

Publications* init_publications();
void load_publications(Publications* publications, FILE* fp);
void create_publication(Publications* publications_user, int code_user, char text[MAX_TEXT_LENGTH]);
void print_publications(Publications* publications_list, User us);
void show_timeline(Publications* publications_list, Friends* friends_list, User_list* user_list, User us);
void save_publications(Publications* publications, FILE* fp);

#endif //UNTITLED4_PUBLICATIONS_USERS_H