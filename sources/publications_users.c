#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/publications_users.h"
#include "../headers/user_list.h"

Publications* init_publications() {
    Publications* publications_list = (Publications*) malloc(sizeof (Publications) * MAX_USERS);
    for (int i = 0; i < MAX_USERS; i++) {
        publications_list[i].code_user = 0;
        publications_list[i].size = 0;
        for (int j = 0; j < MAX_PUBLICATIONS; j++) {
            strcpy(publications_list[i].publication[j], "\0");
        }
    }
    return publications_list;
}

void load_publications(Publications** publications, FILE* fp) {

}

/**
 * Crea una publicación y la guarda en el arreglo del usuario
 * @param publications_list
 * @param code_user
 * @param publication
 */
void create_publication(Publications** publications_list, int code_user, char publication[MAX_TEXT_LENGTH]) {
    int i = 0, comp = 1;
    for (int j = 0; j < MAX_PUBLICATIONS; ++j) {
        if(comp == 1 && publications_list[j] == 0){
            publications_list[j]->code_user = code_user;
            comp = 0;
        }
    }
    while (publications_list[i]->code_user != 0) {
        if (publications_list[i]->code_user == code_user) {
            int size = publications_list[i]->size;
            strcpy(publications_list[i]->publication[size], publication);
            publications_list[i]->size++;
            return;
        }
        i++;
    }
}

void print_publications(Publications* publications_list, User us) {
    int i = 0;
    while (publications_list[i].code_user != 0) {
        if (publications_list[i].code_user == us.code) {
            printf("\n%s\n", LINEA_ASTERISCOS);
            printf("Publicaciones de %s:\n", us.id_name);
            int size = publications_list[i].size;
            for (int j = 0; j < size; j++) {
                printf("%s\n\n", publications_list[i].publication[j]);
            }
            return;
        }
        i++;
    }
}