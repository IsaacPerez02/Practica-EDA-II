#include "../headers/friends_graph.h"

/**
 * Inicializa la lista de amigos de todos los usuarios del sistema
 * @return: arreglo de amigos de los usuarios inicializado
 */
Friends* init_friends_user(){
    //reservamos memoria para los amigos
    Friends* friends = (Friends*) malloc(MAX_USERS * sizeof (Friends));
    //inicializamos los valores
    for (int i = 0; i < MAX_USERS; ++i) {
        friends[i].code_user = 0;
        friends[i].num_friends = 0;
        for (int j = 0; j < MAX_FRIENDS; ++j) {
            friends[i].code_friends[j] = 0;
        }
    }
    return friends;
}

/**
 * Carga los amigos del archivo de amigos.
 * Estructura del archivo: 'Código usuario'. 'cantidad de amigos', 'código de amigo', (* 'cantidad de amigos')
 * @param friends: lista de amigos de todos los usuarios
 * @param ff: archivo de amigos
 */
void load_friends(Friends* friends, FILE* ff){
    int code, code_friend, num_friends, i = 0;
    //vamos leyendo para cargar los amigos de los usuarios
    while(fscanf(ff, "%d. %d,", &code, &num_friends) > 1){
        friends[i].code_user = code;
        friends[i].num_friends = num_friends;
        for (int j = 0; j < num_friends; ++j) {
            fscanf(ff, "%d,", &code_friend);
            friends[i].code_friends[j] = code_friend;
        }
        i++;
    }
}

/**
 * Añade el código de un usuario recién creado a la lista de amigos
 * @param friends: lista de amigos de todos los usuarios
 * @param new_user_code: código del nuevo usuario
 */
void new_user_friends(Friends* friends, int new_user_code){
    int comp = 1;
    //inicializamos los posibles friends del nuevo usuario
    for (int i = 0; i < MAX_USERS; ++i) {
        if(friends[i].code_user == 0 && comp == 1){
            friends[i].code_user = new_user_code;
            comp = 0;
        }
    }
}

/**
 * Añade el código de usuario a la lista de amigos del usuario que ha aceptado su solicitud
 * @param friends: lista de amigos de un usuario
 * @param new_friend: código de usuario de la solicitud aceptada
 */
void add_friend(Friends* friends, int new_friend){
    //añadimos a un usuario un nuevo amigo
    friends->code_friends[friends->num_friends] = new_friend;
    friends->num_friends++;
}

/**
 * Busca en la lista de amigos de los usuarios la lista de amigos por el código introducido
 * @param friends: lista de amigos de todos los usuarios
 * @param code_user: código del usuario a buscar
 * @return: lista de amigos del usuario a buscar
 */
Friends* search_user_friends(Friends* friends, int code_user){
    //iteramos hasta encontrar a una estructura friend de un usuario por codigo
    for (int i = 0; i < MAX_USERS; ++i) {
        if(friends[i].code_user == code_user){
            return &friends[i];
        }
    }
    return NULL;
}

/**
 * Guarda la lista de amigos de todos los usuarios en el archivo de amigos al finalizar el programa
 * @param friends: lista de amigos de todos los usuarios
 * @param ff: archivo de amigos
 */
void save_friends(Friends* friends, FILE* ff){
    //vamos guardando usuario por usuario con sus friends pertinentes
    for (int i = 0; i < MAX_USERS; ++i) {
        if(friends[i].code_user != 0){
            fprintf(ff, "%d. %d, ", friends[i].code_user, friends[i].num_friends);
            for (int j = 0; j < friends[i].num_friends; ++j) {
                fprintf(ff, "%d, ", friends[i].code_friends[j]);
            }
            fprintf(ff,"\n");
        }
    }
    free(friends);
}

/**
 * Muestra por consola la lista de amigos de un usuario
 * @param list: lista de usuarios del sistema
 * @param friends: lista de amigos de un usuario
 */
void print_friends_graph(User_list* list, Friends* friends){
    int i = 1;
    //imprimimos los amigos de un usuario
    for (int j = 0; j < friends->num_friends; ++j) {
        User* us = search_user_code(list, friends->code_friends[j]);
        printf("%d. %s\n", i, us->id_name);
        i++;
    }
    printf("\n%s%s\n\n", LINEA_ASTERISCOS, LINEA_ASTERISCOS);
}
