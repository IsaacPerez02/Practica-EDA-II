#include "../headers/requests_stack.h"

Requests_stack init_stack() {
    Requests_stack requests_stack;
    for (int i = 0; i < 3; i++) {
        requests_stack.requests_code[i] = 0;
    }
    requests_stack.top = 0;
}

int stack_is_empty(Requests_stack requests_stack) {
    return (requests_stack.top == 0);
}

int stack_is_full(Requests_stack requests_stack) {
    return (requests_stack.top == 3);
}

void add_request_stack(Requests_stack* requests_stack, int code_request) {
    int top = requests_stack->top;
    requests_stack->requests_code[top] = code_request;
    requests_stack->top++;
}

void delete_request_stack(Requests_stack* requests_stack) {
    int top = requests_stack->top;
    requests_stack->requests_code[top] = 0;
    requests_stack->top--;
}

int top(Requests_stack requests_stack) {
    return requests_stack.requests_code[requests_stack.top];
}

Requests_stack add_users_to_stack(User_list* users_list, Requests* requests_list, Friends* friends_list, int login_code) {
    Requests_stack requests_stack = init_stack();
    srand(time(NULL));
    int idx;
    int code;

    for (int i = 0; i < 3; i++) {
        idx = rand() % get_num_users(users_list);
        User_list* heap = users_list;
        for (int j = 0; j < idx; j++) {
            heap = heap->next;
        }
        code = heap->us->code;

        //Comprobamos que el código del usuario escogido al azar no esté en la lista de solicitudes o de amigos del
        //usuario o que no sea el suyo propio
        for (int k = 0; k < MAX_USERS; k++) {
            //Si es el caso, volvemos a buscar un código
            if (code == requests_list->code_request[k] || code == friends_list->code_friends[k] || code == login_code) {
                //Ahora comprobamos que el código no esté en el stack
                for (int l = 0; l < requests_stack.top; l++) {
                    if (code == requests_stack.requests_code[l]) {
                        idx = rand() % get_num_users(users_list);
                        heap = users_list;
                        for (int j = 0; j < idx; j++) {
                            heap = heap->next;
                        }
                        code = heap->us->code;
                        k = 0;
                    }
                }
            }
        }
        printf("%d", code);
        add_request_stack(&requests_stack, code);
    }

    return requests_stack;
}