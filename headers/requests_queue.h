#ifndef UNTITLED4_REQUESTS_QUEUE_H
#define UNTITLED4_REQUESTS_QUEUE_H
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#define MAX_USERS 20
#define MAX_REQUESTS 10

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

void init_requests(Requests* requests);
int is_empty(Requests* requests);
int is_full(Requests* requests);
int first(Requests* requests);
void add_request(Requests* requests, int request_code);
void delete_request(Requests* requests);

Requests * init_requests_user();
void load_requests(Requests* requests, FILE* fr);
void new_user_requests(Requests* requests, int new_user_code);
void add_requests(Requests* requests, int new_request);
Requests* search_user_requests(Requests* requests, int code_user);
void save_requests(Requests* requests, FILE* fr);
void print_requests_graph(Requests* requests);

#endif //UNTITLED4_REQUESTS_QUEUE_H
