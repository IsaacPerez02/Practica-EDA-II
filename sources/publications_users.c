#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/publications_users.h"
#include "../headers/user_list.h"

/**
 * Inicializa las variables de las publicaciones de los usuarios del sistema
 * @return: arreglo de publicaciones de todos los usuarios inicializado
 */
Publications* init_publications() {
    //reservamos memoria para las publicaciones
    Publications* publications_list = (Publications*) malloc(sizeof (Publications) * MAX_USERS);
    //inicializamos publicacion tras publicacion
    for (int i = 0; i < MAX_USERS; i++) {
        publications_list[i].code_user = 0;
        strcpy(publications_list[i].publication, " ");
    }
    return publications_list;
}

/**
 * Carga las publicaciones del archivo de publicaciones
 * Estructura del archivo: 'código del usuario' 'texto de la publicación'
 * @param publications: lista de publicaciones de los usuarios
 * @param fp: archivo de publicaciones
 */
void load_publications(Publications* publications, FILE* fp) {
    int code, i = 0;
    char text[MAX_TEXT_LENGTH];
    //vamos leyendo el archivo para ir cargando las publicaciones
    while(fscanf(fp, "%d. ", &code) > 0){
        publications[i].code_user = code;
        fgets(text, MAX_TEXT_LENGTH, fp);
        text[strcspn(text, "\n")] = '\0'; // Eliminar salto de línea del final
        strcpy(publications[i].publication, text);
        i++;
    }
}

/**
 * Crea una publicación y la guarda en el arreglo del usuario
 * @param publications_list: Lista de publicaciones de los usuarios
 * @param code_user: Código del usuario que ha publicado
 * @param publication: Publicación que ha escrito el usuario
 */
void create_publication(Publications* publications_user, int code_user, char text[MAX_TEXT_LENGTH]) {
    int comp = 1;
    //vamos iterando hasta encontrar un hueco para la nueva publicacion
    for (int i = 0; i < MAX_PUBLICATIONS; ++i) {
        if(publications_user[i].code_user == 0 && comp == 1){
            publications_user[i].code_user = code_user;
            strcpy(publications_user[i].publication, text);
            comp = 0;
        }
    }

}

/**
 *Imprime todas las publicaciones de un usuario que se haya escogido
 * @param publications_list: Lista de publicaciones de los usuarios
 * @param us: Usuario que queremos ver sus publicaciones
 */
void print_publications(Publications* publications_list, User us) {
    //imprimimos las publicaciones del usuario que queramos
    printf("\nEl usuario %s ha realizado las siguientes publicaciones:\n", us.id_name);
    for (int i = 0; i < MAX_PUBLICATIONS; ++i) {
        if(us.code == publications_list[i].code_user){
            printf("%s\n", publications_list[i].publication);
            printf("\n%s%s\n\n", LINEA_ASTERISCOS, LINEA_ASTERISCOS);
        }
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

/**
 * Guarda la lista de publicaciones de todos los usuarios en el archivo de publicaciones
 * @param publications: lista de publicaciones de los usuarios
 * @param fp: archivo de publicaciones
 */
void save_publications(Publications* publications, FILE* fp){
    for (int i = 0; i < MAX_USERS; ++i) {
        if(publications[i].code_user != 0){
            fprintf(fp, "%d. %s\n", publications[i].code_user, publications[i].publication);
        }
    }
    free(publications);
}