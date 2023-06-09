#ifndef UNTITLED4_REQUESTS_STACK_H
#define UNTITLED4_REQUESTS_STACK_H
#include "defines.h"
#include "user_list.h"
#include "requests_queue.h"
#include "publications_users.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Stack de solicitudes. Su función es buscar 3 usuarios al azar para enviarles solicitud o no
 * requests_code: Lista de solicitudes de los usuarios elegidos al azar
 * top: ïndice del siguiente usuario a añadir
 */
typedef struct {
    int requests_code[3];
    int top;
} Requests_stack;

Requests_stack init_stack();
int stack_is_empty(Requests_stack requests_stack);
int stack_is_full(Requests_stack requests_stack);
void add_request_stack(Requests_stack* requests_stack, int code_request);
void delete_request_stack(Requests_stack* requests_stack);
int top(Requests_stack requests_stack);
Requests_stack add_users_to_stack(User_list* users_list, Requests* requests_list, Friends* friends_list, int login_code);
void manage_stack(User_list* user_list, Requests* requests_list, Requests_stack requests_stack, int login_code, Publications* publications);

#endif //UNTITLED4_REQUESTS_STACK_H