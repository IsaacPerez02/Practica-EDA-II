#ifndef UNTITLED4_REQUESTS_QUEUE_H
#define UNTITLED4_REQUESTS_QUEUE_H
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include "friends_graph.h"
#include "defines.h"
#include "user_list.h"

/**
 * Cola de solicitudes de un usuario
 * code_request: Arreglo de códigos de los usuarios que le han mandado solicitud a este usuario
 * head: Inicio de la cola
 * tail: Final de la cola
 * size: Cantidad de elementos de la cola
 */
typedef struct {
    int code_user;
    int code_request[MAX_REQUESTS];
    int head;
    int tail;
    int size;
}Requests;


Requests * init_requests_user();
int is_empty(Requests* requests);
int is_full(Requests* requests);
void load_requests(Requests* requests, FILE* fr);
void new_user_requests(Requests* requests, int new_user_code);
void add_requests(Requests* requests, int new_request);
Requests* search_user_requests(Requests* requests, int code_user);
void manage_requests(User_list* user_list, Requests* requests_list, Friends* friends);
int is_empty_requests(Requests* requests);
void accept_requests(Requests* requests, Friends* friends, int code_user, int code_new_friend);
void delete_request(Requests* requests);
void save_requests(Requests* requests, FILE* fr);
void print_requests_graph(User_list* list, Requests* requests);

#endif //UNTITLED4_REQUESTS_QUEUE_H
