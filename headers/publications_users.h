#ifndef UNTITLED4_PUBLICATIONS_USERS_H
#define UNTITLED4_PUBLICATIONS_USERS_H

#include "user.h"
#include "user_list.h"

#define LINEA_ASTERISCOS "******************************"


#define MAX_PUBLICATIONS 10
#define MAX_TEXT_LENGTH 120

/**
 * Arreglo de publicaciones de un usuario
 */
typedef struct {
    int code_user;
    char publication[MAX_PUBLICATIONS][MAX_TEXT_LENGTH];
    int size;
} Publications;

Publications* init_publications();
void load_publications(Publications** publications, FILE* fp);

void create_publication(Publications** publications_list, int code_user, char publication[MAX_TEXT_LENGTH]);
void print_publications(Publications* publications_list, User us);

#endif //UNTITLED4_PUBLICATIONS_USERS_H