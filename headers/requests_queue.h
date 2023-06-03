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
void loading_requests_code(Requests** requests_list, User_list** user_list);
int get_request_list_size(User_list** user_List);
void add_user_created_to_requests_list(Requests** requests_list, User_list* user_list, User* user);
void send_request(Requests** requests_list, User_list* user_list, int code_user, int request_code);
void manage_requests(Requests** requests_list, User_list* user_list, int code_user);
void print_requests(int* requests_queue, User_list* user_list, int head, int size);
void delete_request(Requests** requests_list, User_list* user_list, int code_user);

#endif //UNTITLED4_REQUESTS_QUEUE_H
