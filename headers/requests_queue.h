#ifndef UNTITLED4_REQUESTS_QUEUE_H
#define UNTITLED4_REQUESTS_QUEUE_H

#define MAX_FRIENDS 10

/**
 * Cola de solicitudes de un usuario
 * code_request: Arreglo de códigos de los usuarios que le han mandado solicitud a este usuario
 * head: Inicio de la cola
 * tail: Final de la cola
 * size: Cantidad de elementos de la cola
 */
typedef struct {
    int code_request[MAX_FRIENDS];
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

#endif //UNTITLED4_REQUESTS_QUEUE_H
