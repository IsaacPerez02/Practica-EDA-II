#ifndef UNTITLED4_MANAGE_REQUESTS_QUEUE_H
#define UNTITLED4_MANAGE_REQUESTS_QUEUE_H

#include "requests_queue.h"

/**
 * Lista enlazada de solicitudes de todos los usuarios del sistema
 * next: Siguiente nodo del actual
 * tail: Array de solicitudes de todos los usuarios del sistema
 */
typedef struct {
    struct Manage_requests* next;
    Requests* requests;
}Manage_requests;

Manage_requests* init_manage();
Requests* add_request(Requests* requests, int code_user, int code_request);
Requests* delete_request(Requests* requests, int code_user);
Manage_requests search_manage_request(Manage_requests manage_requests, int code_user);

#endif //UNTITLED4_MANAGE_REQUESTS_QUEUE_H
