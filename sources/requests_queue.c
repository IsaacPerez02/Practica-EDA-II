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
    }
}

/**
 *
 * @param requests
 * @param code_user
 * @return
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
 * Guardamos todas las requests antes de salir del programa
 * @param requests actuales
 * @param fr archivo de guardado
 */
void save_requests(Requests* requests, FILE* fr){
    for (int i = 0; i < MAX_USERS; ++i) {
        if(requests[i].code_user != 0){
            fprintf(fr, "%d. %d, ", requests[i].code_user, requests[i].size);
            for (int j = requests[i].head; j < requests[i].tail ; ++j) {
                fprintf(fr, "%d, ", requests[i].code_request[j]);
            }
            fprintf(fr, "\n");
        }
    }
}

/**
 *
 * @param requests
 */
void print_requests_graph(User_list* list, Requests* requests){
    int i = 1;
    if(requests->head < requests->tail){
        for (int j = requests->head; j < requests->tail; ++j) {
            User* us = search_user_code(list, requests->code_request[j]);
            printf("%d. %s\n ", i, us->id_name);
            i++;
        }
        printf("\n");
    }
    else{
        for (int j = requests->tail; j < requests->head; ++j) {
            User* us = search_user_code(list, requests->code_request[j]);
            printf("%d. %s\n ", i, us->id_name);
            i++;
        }
    }
}