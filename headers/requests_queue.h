#ifndef UNTITLED4_REQUESTS_QUEUE_H
#define UNTITLED4_REQUESTS_QUEUE_H

#include "user.h"

/**
 * code_user: Código del propio usuario
 * code_friends: Lista de códigos de las solicitudes
 * head: Primer elemento
 * tail: Último elemento
 * size: Cantidad de solicitudes
 */

typedef struct {
    int code_user;
    int code_friends[MAX_FRIENDS];
    int head;
    int tail;
    int size;
}Requests;

Requests* init_requests();
int is_empty(Requests requests);
int is_full(Requests requests);
int first(Requests requests);
Requests* add_request(Requests* requests_queue, int code_user, int friend_code);
Requests* delete_request(Requests* requests_queue, int code_user);

#endif //UNTITLED4_REQUESTS_QUEUE_H
