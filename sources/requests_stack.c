#include "../headers/requests_stack.h"

Requests_stack init_stack() {
    Requests_stack requests_stack;
    for (int i = 0; i < 3; i++) {
        requests_stack.requests_code[i] = 0;
    }
    requests_stack.top = 0;
    return requests_stack;
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
    printf("Hola\n");
    srand(time(NULL));
    printf("Hola\n");
    int idx;
    int code;

    for (int i = 0; i < 3; i++) {
        idx = rand() % get_num_users(users_list);
        User_list* heap = users_list;
        for (int j = 0; j < idx; j++) {
            heap = heap->next;
        }
        code = heap->us->code;

        int isDuplicate = 0;
        //Comprobamos que el código del usuario escogido al azar no esté en la lista de solicitudes o de amigos del usuario o que no sea el suyo propio
        for (int k = 0; k < MAX_USERS; k++) {
            if (code == requests_list->code_request[k] || code == friends_list->code_friends[k] || code == login_code) {
                isDuplicate = 1;
                break;
            }
        }

        //Comprobamos si el código ya está en la pila de solicitudes
        for (int l = 0; l < requests_stack.top; l++) {
            if (code == requests_stack.requests_code[l]) {
                isDuplicate = 1;
                break;
            }
        }

        if (isDuplicate) {
            i--; //Reiniciamos el bucle para generar un nuevo código
            continue;
        }

        printf("%d\n", code);
        add_request_stack(&requests_stack, code);
    }

    return requests_stack;
}


void manage_stack(User_list* user_list, Requests* requests_list, Requests_stack requests_stack, int login_code) {
    int option_requests = -1;
    int i;
    User* stack_user;
    Requests* stack_requests;
    printf("***** Usuarios *****\n");
    for (i = 0; i < requests_stack.top; i++) {
        printf("%d.- %s\n", i + 1, search_user_code(user_list, requests_stack.requests_code[i])->id_name);
    }

    for (i = 0; i < requests_stack.top; i++) {
        stack_user = search_user_code(user_list, requests_stack.requests_code[i]);
        printf("\n%s\n", LINEA_ASTERISCOS);
        printf("Nombre usuario: %s\n", stack_user->id_name);
        printf("Nombre real: %s\n", stack_user->nombre);
        printf("Edad: %d \n", stack_user->edad);
        printf("Correo: %s\n", stack_user->correo);
        printf("Ubicacion: %s\n", stack_user->ubicacion);
        printf("Gustos: ");
        for (int j = 0; j < 5; j++) {
            printf("%s ", stack_user->gustos[j]);
        }

        while (option_requests != 0) {
            printf("\n\nDeseas enviarle una solicitud a %s?\n", stack_user->id_name);
            printf("1.- Si\n");
            printf("2.- No\n");
            printf("0.- Cancelar\n");
            printf("Elija una opcion:\n");
            scanf("%d", &option_requests);

            if (option_requests == 1) {
                stack_requests = search_user_requests(requests_list, stack_user->code);
                add_requests(stack_requests, login_code);
                break;
            }
            else if (option_requests == 2) {
                break;
            }
            else if (option_requests == 0) {
                printf("Saliendo de la gestion de enviar solicitudes...");
                return;
            }
            else {
                printf("Escoja una opcion correcta.\n");
            }
        }
    }
}