#include <stdio.h>
#include "../headers/requests_queue.h"

/**
 * Inicializamos todas las requests de los usuarios
 * @return Requests inicializada completamente
 */
Requests * init_requests_user(){
    Requests* requests = (Requests*) malloc(MAX_USERS * sizeof (Requests));
    for (int i = 0; i < MAX_USERS; ++i) {
        requests[i].code_user = 0;
        requests[i].tail = 0;
        requests[i].head = 0;
        requests[i].size = 0;
        for (int j = 0; j < MAX_REQUESTS; ++j) {
            requests[i].code_request[j] = 0;
        }
    }
    return requests;
}

/**
 * Comprueba si la cola está vacía
 * @param requests: Cola de solicitudes
 * @return: Devuelve si la cola está vacía (1) o no (0)
 */
int is_empty(Requests* requests) {
    return (requests->size == 0);
}

/**
 * Comprueba si la cola está llena
 * @param requests: Cola de solicitudes
 * @return: Devuelve si la cola está llena (1) o no (0)
 */
int is_full(Requests* requests) {
    return (requests->size == MAX_REQUESTS);
}

/**
 * Cargamos las requests anteriores de los usuarios
 * @param requests request inicializada
 * @param fr archivo
 */
void load_requests(Requests* requests, FILE* fr){
    int code, code_requests, num_requests, i = 0;
    while(fscanf(fr, "%d. %d,", &code, &num_requests) > 1){
        requests[i].code_user = code;
        requests[i].head = 0;
        requests[i].tail = num_requests;
        requests[i].size = num_requests;
        for (int j = 0; j < num_requests; ++j) {
            fscanf(fr, "%d,", &code_requests);
            requests[i].code_request[j] = code_requests;
        }
        i++;
    }
}

/**
 * Inicializamos los requests del nuevo usuario
 * @param requests request inicializada
 * @param new_user_code codigo de usuario nuevo
 */
void new_user_requests(Requests* requests, int new_user_code){
    int comp = 1;
    for (int i = 0; i < MAX_USERS; ++i) {
        if(requests[i].code_user == 0 && comp == 1){
            requests[i].code_user = new_user_code;
            comp = 0;
        }
    }
}

/**
 * Inicializamos una nueva requests
 * @param requests request inicializada
 * @param new_request codigo del nuevo requests
 */
void add_requests(Requests* requests, int new_request) {
    if (requests->size == MAX_REQUESTS) {
        printf("No se pueden enviar mas solicitudes a este usuario.\n");
    }
    else {
        requests->code_request[requests->tail] = new_request;
        requests->tail++;
        if (requests->tail > MAX_REQUESTS) {
            requests->tail = 0;
        }
        requests->size++;
        printf("Solicitud enviada.\n");
    }
}

/**
 * Busca la lista de solicitudes de un usuario
 * @param requests: lista de solicitudes de todos los usuarios
 * @param code_user: código del usuario a buscar
 * @return: lista de solicitudes del usuario a buscar
 */
Requests* search_user_requests(Requests* requests, int code_user){
    for (int i = 0; i < MAX_USERS; ++i) {
        if(requests[i].code_user == code_user){
            return &requests[i];
        }
    }
    return NULL;
}

/**
 * Acepta la solicitud de un usuario y se vuelven amigos
 * @param friends: lista de amigos de todos los usuarios
 * @param code_user: código del usuario que acepta la solicitud
 * @param code_new_friend: código del usuario de la solicitud
 */
void accept_requests(Friends* friends, int code_user, int code_new_friend){
    Friends* friend = search_user_friends(friends, code_user);
    add_friend(friend, code_new_friend);
    friend = search_user_friends(friends, code_new_friend);
    add_friend(friend, code_user);
}

/**
 * Borra la primera solicitud de la cola
 * @param requests: Cola de solicitudes
 */
void delete_request(Requests* requests) {
    if (is_empty(requests)) {
        printf("No hay mas solicitudes.\n");
    }
    else {
        requests->code_request[requests->head] = 0;
        requests->head++;
        if (requests->head > MAX_REQUESTS) {
            requests->head = 0;
        }
        requests->size--;
    }
}

/**
 * Gestiona las solicitudes del usuario logeado
 * @param requests_list: Lista de solicitudes
 * @param code_user: Código del usuario logeado
 * @param friends: Lista de amigos
 */
void manage_requests(User_list* user_list, Requests* requests_list, Friends* friends) {
    int option_requests = -1;
    if(requests_list->head < requests_list->tail){
        //Gestión de solicitud de un usuario. Al no tener más solicitudes, saldremos de la gestión de solicitudes
        for (int i = requests_list->head; i < requests_list->tail && option_requests != 0; i++) {
            printf("\n%s\n", LINEA_ASTERISCOS);
            printf("Que deseas hacer con la solicitud de %s?\n", search_user_code(user_list, requests_list->code_request[i])->id_name);
            printf("1.- Aceptar\n");
            printf("2.- Rechazar\n");
            printf("0.- Atras\n");
            printf("Elija una opcion:\n");
            scanf("%d", &option_requests);

            if (option_requests == 1) {
                accept_requests(friends, requests_list->code_user, requests_list->code_request[i]);
                delete_request(requests_list); //Al aceptar la solicitud, la borramos de la lista del usuario
                printf("Solicitud aceptada.\n");
            }
            else if (option_requests == 2) {
                delete_request(requests_list); //Borramos la solicitud directamente sin añadirlo como amigo
                printf("Solicitud rechazada.\n");
            }
            else if (option_requests == 0) {
                printf("Saliendo de la gestion de solicitudes...\n");
            }
        }
    }
    else{
        for (int j = requests_list->tail; j < requests_list->head; j++){
            printf("\n%s\n", LINEA_ASTERISCOS);
            printf("Que deseas hacer con la solicitud de %s?\n", search_user_code(user_list, requests_list->code_request[j])->id_name);
            printf("1.- Aceptar\n");
            printf("2.- Rechazar\n");
            printf("0.- Atras\n");
            printf("Elija una opcion:\n");
            scanf("%d", &option_requests);
            if (option_requests == 1) {
                accept_requests(friends, requests_list->code_user, requests_list->code_request[j]);
                delete_request(requests_list); //Al aceptar la solicitud, la borramos de la lista del usuario
                printf("Solicitud aceptada.\n");
            }
            else if (option_requests == 2) {
                delete_request(requests_list); //Borramos la solicitud directamente sin añadirlo como amigo
                printf("Solicitud rechazada.\n");
            }
            else if (option_requests == 0) {
                printf("Saliendo de la gestion de solicitudes...\n");
            }
        }
    }
}



/**
 * Guardamos todas las requests antes de salir del programa
 * @param requests actuales
 * @param fr archivo de guardado
 */
void save_requests(Requests* requests, FILE* fr){
    for (int i = 0; i < MAX_USERS; ++i) {
        if(requests[i].code_user != 0){
            fprintf(fr, "%d. %d, ", requests[i].code_user, requests[i].size);
            if(requests[i].head < requests[i].tail){
                for (int j = requests[i].head; j < requests[i].tail ; j++) {
                    fprintf(fr, "%d, ", requests[i].code_request[j]);
                }
                fprintf(fr, "\n");
            }
            else{
                for (int j = requests[i].tail; j < requests[i].head ; j++) {
                    fprintf(fr, "%d, ", requests[i].code_request[j]);
                }
                fprintf(fr, "\n");
            }
        }
    }
    free(requests);
}

/**
 * Muestra por consola la lista de solicitudes de un usuario
 * @param list: lista de usuarios del sistema
 * @param requests: lista de solicitudes del usuario logeado
 */
void print_requests_graph(User_list* list, Requests* requests){
    int i = 1;
    if(requests->head < requests->tail){
        for (int j = requests->head; j < requests->tail; j++) {
            User* us = search_user_code(list, requests->code_request[j]);
            printf("%d. %s\n ", i, us->id_name);
            i++;
        }
        printf("\n");
    }
    else{
        for (int j = requests->tail; j < requests->head; j++) {
            User* us = search_user_code(list, requests->code_request[j]);
            printf("%d. %s\n ", i, us->id_name);
            i++;
        }
    }
    printf("\n%s%s\n\n", LINEA_ASTERISCOS, LINEA_ASTERISCOS);
}