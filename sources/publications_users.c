#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/publications_users.h"
#include "../headers/user_list.h"

/**
 * Crea una publicación y la guarda en el arreglo del usuario
 * @param publications_list
 * @param code_user
 * @param publication
 */
void create_publication(Publications** publications_list, int code_user, char publication[MAX_TEXT_LENGTH]) {
    int i = 0;
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

void print_publications(Publications* publications_list, int code) {
    int i = 0;
    while (publications_list[i].code_user != 0) {
        if (publications_list[i].code_user == code) {
            int size = publications_list[i].size;
            for (int j = 0; j < size; j++) {
                printf("");
            }
            return;
        }
        i++;
    }
}