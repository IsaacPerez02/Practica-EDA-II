#include <malloc.h>
#include "../headers/friends_stack.h"
#define ERROR -1

/**
 * Funcion para contar el numero de amigos totales que tenemos
 * @param friends
 * @return numero de amigos totales
 */
int count_friends(User friends[MAX_FRIENDS]){
    int counter = 0;
    for (int i = 0; i < MAX_FRIENDS; ++i) {
        if (friends[i].code != 0){
            counter++;
        }
    }
    return counter;
}

/**
 * Funcion que devuelve el indice de la posicion donde se encuentra el amigo que queremos utilizar
 * @param friends
 * @param id_code
 * @return indice del usuario a buscar
 */
int search_friends(Friends* friends, int id_code){
    for (int i = 0; i < MAX_FRIENDS; i++){
        if (id_code == friends->friends[i].code){
            return i;
        }
    }
    return -1;
}

void add_friends(Friends* friends, int new_id_code, User_list* list){
    int count = count_friends(friends->friends);
    User* us;
    us = search_user_code(list, new_id_code);
    friends->friends[count + 1] = *us;
}

void delete_friends(Friends* friends, int id_code){
    User* new_list = (User*) malloc(sizeof (User) * MAX_FRIENDS);
    int j = 0;
    for (int i = 0; i < count_friends(friends->friends); i++) {
        if (friends->friends[i].code != id_code) {
            new_list[j] = friends->friends[i];
            j++;
        }
    }
    friends->friends = new_list;
}