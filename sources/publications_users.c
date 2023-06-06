#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/publications_users.h"
#include "../headers/user_list.h"

/**
 * Inicializa las variables de las publicaciones de los usuarios del sistema
 * @return
 */
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

/**
 * Carga las publicaciones del archivo de todos los usuarios
 * @param publications
 * @param fp
 */
void load_publications(Publications** publications, FILE* fp) {

}

/**
 * Crea una publicación y la guarda en el arreglo del usuario
 * @param publications_list: Lista de publicaciones de los usuarios
 * @param code_user: Código del usuario que ha publicado
 * @param publication: Publicación que ha escrito el usuario
 */
void create_publication(Publications** publications_list, int code_user, char publication[MAX_TEXT_LENGTH]) {
    int i = 0, comp = 1;
    for (int j = 0; j < MAX_PUBLICATIONS; ++j) {
        if(comp == 1 && publications_list[j] == 0){
            publications_list[j]->code_user = code_user;
            comp = 0;
        }
    }
    //Buscamos el código del usuario en la lista de publicaciones
    while (publications_list[i]->code_user != 0) {
        if (publications_list[i]->code_user == code_user) {
            //Una vez encontrado, añadimos el mensaje escrito en su lista de publicaciones
            int size = publications_list[i]->size;
            strcpy(publications_list[i]->publication[size], publication);
            publications_list[i]->size++;
            return;
        }
        i++;
    }
}

/**
 *Imprime todas las publicaciones de un usuario que se haya escogido
 * @param publications_list: Lista de publicaciones de los usuarios
 * @param us: Usuario que queremos ver sus publicaciones
 */
void print_publications(Publications* publications_list, User us) {
    int i = 0;
    //Buscamos el código del usuario en la lista de publicaciones
    while (publications_list[i].code_user != 0) {
        if (publications_list[i].code_user == us.code) {
            //Una vez encontrado, mostramos por pantalla todas sus publicaciones
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

/**
 * Muestra todas las publicaciones de los amigos que tenga el usuario logeado
 * @param publications_list: Lista de publicaciones de los usuarios
 * @param friends_list: Lista de amigos de los usuarios
 * @param user_list: Lista de usuarios del sistema
 * @param us: Usuario logeado
 */
void show_timeline(Publications* publications_list, Friends* friends_list, User_list* user_list, User us) {
    int i = 0;
    //Buscamos el código del usuario en la lista de amigos
    while (friends_list[i].code_user != 0) {
        if (friends_list[i].code_user == us.code) {
            //Una vez encontrado, mostramos por pantalla las publicaciones de todos sus amigos
            for (int j = 0; j < friends_list[i].num_friends; j++) {
                print_publications(publications_list, *search_user_code(user_list, friends_list[i].code_friends[j]));
            }
            return;
        }
        i++;
    }
}