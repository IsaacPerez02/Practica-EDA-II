#include "../headers/requests_stack.h"

/**
 * Inicializa el stack de usuarios elegidos al azar
 * @return: stack de usuarios inicializado
 */
Requests_stack init_stack() {
    Requests_stack requests_stack;
    for (int i = 0; i < 3; i++) {
        requests_stack.requests_code[i] = 0;
    }
    requests_stack.top = 0;
    return requests_stack;
}

/**
 * Comprueba si el stack está vacío
 * @param requests_stack: Stack de usuarios aleatorios
 * @return: TRUE si el stack está vacío; FALSE si no está vacío
 */
int stack_is_empty(Requests_stack requests_stack) {
    return (requests_stack.top == 0);
}

/**
 * Comprueba si el stack está lleno
 * @param requests_stack: stack de usuarios aleatorios
 * @return: TRUE si el stack está lleno; FALSE si no está lleno
 */
int stack_is_full(Requests_stack requests_stack) {
    return (requests_stack.top == 3);
}

/**
 * Añade el código de un usuario al azar al stack
 * @param requests_stack: stack de usuarios aleatorios
 * @param code_request: código del usuario generado aleatoriamente
 */
void add_request_stack(Requests_stack* requests_stack, int code_request) {
    int top = requests_stack->top; //Posición siguiente a añadir
    requests_stack->requests_code[top] = code_request;
    requests_stack->top++;
}

/**
 * Borra el código del último usuario añadido
 * @param requests_stack: stack de usuarios aleatorios
 */
void delete_request_stack(Requests_stack* requests_stack) {
    int top = requests_stack->top; //Posición siguiente a añadir
    requests_stack->requests_code[top - 1] = 0;
    requests_stack->top--;
}

/**
 * Devuelve el último usuario añadido
 * @param requests_stack: stack de usuarios aleatorios
 * @return: último usuario añadido
 */
int top(Requests_stack requests_stack) {
    return requests_stack.requests_code[requests_stack.top];
}

/**
 * Busca a un usuario de la lista al azar y añadimos su código al stack
 * @param users_list: lista de usuarios del sistema
 * @param requests_list: lista de solicitudes del usuario logeado
 * @param friends_list: lista de amigos del usuario logeado
 * @param login_code: código del usuario logeado
 * @return: stack de usuarios al azar
 */
Requests_stack add_users_to_stack(User_list* users_list, Requests* requests_list, Friends* friends_list, int login_code) {
    Requests_stack requests_stack = init_stack(); //Inicializa el stack
    srand(time(NULL));
    int idx; //Índice del usuario escogido al azar
    int code; //Código generado

    for (int i = 0; i < 3; i++) {
        idx = rand() % get_num_users(users_list); //Generamos un número del 0 a la cantidad de usuarios que haya en la lista
        //Recorremos la lista de usuarios en base al índice que nos haya tocado
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

        //Si el código está duplicado...
        if (isDuplicate) {
            i--; //Reiniciamos el bucle para generar un nuevo código
            continue;
        }

        add_request_stack(&requests_stack, code); //Añade el código generado al stack
    }

    return requests_stack;
}

/**
 * Gestiona el stack de usuarios. Podremos elegir entre los usuarios que se nos han generado si enviarles una solicitud o no
 * @param user_list: lista de usuarios del sistema
 * @param requests_list: lista de solicitudes de los usuarios
 * @param requests_stack: stack de usuarios
 * @param login_code: código del usuario logeado
 * @param publications: lista de publicaciones de los usuarios
 */
void manage_stack(User_list* user_list, Requests* requests_list, Requests_stack requests_stack, int login_code, Publications* publications) {
    int option_requests = -1;
    int i;
    User* stack_user; //Usuario actual del stack
    Requests* stack_requests; //Lista de solicitudes del usuario actual del stack
    //Imprimimos los nombres de los usuarios del stack
    printf("***** Usuarios *****\n");
    for (i = 0; i < 3; i++) {
        printf("%d.- %s\n", i + 1, search_user_code(user_list, requests_stack.requests_code[i])->id_name);
    }

    //Mostramos su información uno por uno y decidimos si enviarles solicitud o no
    for (i = 0; i < 3; i++) {
        stack_user = search_user_code(user_list, requests_stack.requests_code[requests_stack.top - 1]);
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
        printf("\n");
        print_publications(publications, *stack_user); //Imprime sus publicaciones

        while (option_requests != 0) {
            printf("\n\nDeseas enviarle una solicitud a %s?\n", stack_user->id_name);
            printf("1.- Si\n"); //Enviar solicitud
            printf("2.- No\n"); //No enviar solicitud
            printf("0.- Cancelar\n"); //Salir de la gestión del stack
            printf("Elija una opcion:\n");
            scanf("%d", &option_requests);

            if (option_requests == 1) { //Si
                //Enviamos solicitud y lo quitamos del stack
                stack_requests = search_user_requests(requests_list, stack_user->code);
                add_requests(stack_requests, login_code);
                delete_request_stack(&requests_stack);
                break;
            }
            else if (option_requests == 2) { //No
                //Lo quitamos del stack directamente
                delete_request_stack(&requests_stack);
                break;
            }
            else if (option_requests == 0) { //Cancelar
                printf("Saliendo de la gestion de enviar solicitudes...\n");
                return;
            }
            else {
                printf("Escoja una opcion correcta.\n");
            }
        }
    }
}