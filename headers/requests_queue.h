#ifndef UNTITLED4_REQUESTS_QUEUE_H
#define UNTITLED4_REQUESTS_QUEUE_H

#include "user_list.h"

/**
 * code_user: Código del propio usuario
 * code_friends: Lista de códigos de las solicitudes
 * head: Primer elemento
 * tail: Último elemento
 * size: Cantidad de solicitudes de un usuario
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
int get_size(Requests* requests_queue, User_list** user_List);
Requests* accept_request(Requests* requests_queue, int code_user, int friend_code);
Requests* delete_request(Requests* requests_queue, int code_user);
void loading_requests_code(Requests** requests_queue, User_list** user_list);

#endif //UNTITLED4_REQUESTS_QUEUE_H
