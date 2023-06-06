#include <stdio.h>
#include "../headers/requests_queue.h"
#define LINEA_ASTERISCOS "******************************"


/**
 * Inicializa los datos de la cola de solicitudes de un usuario
 * @param requests: Cola de solicitudes
 */
void init_requests(Requests* requests) {
    requests->head = 0;
    requests->tail = 0;
    requests->size = 0;
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
 * Devuelve el primer elemento de la cola
 * @param requests: Cola de solicitudes
 * @return: Devuelve el código del primer elemento de la cola
 */
int first(Requests* requests) {
    if (is_empty(requests)) {
        return 0;
    }
    else {
        return requests->code_request[requests->head];
    }
}

/**
 * Añade una solicitud de amistad
 * @param requests: Cola de solicitudes
 * @param request_code: Código del usuario que envía la solicitud
 */
void add_request(Requests* requests, int request_code) {
    if (requests->size == MAX_REQUESTS) {
        printf("No se pueden enviar mas solicitudes a este usuario.\n");
    }
    else {
        int tail = requests->tail;
        requests->code_request[tail] = request_code;
        requests->tail++;
        if (requests->tail > MAX_REQUESTS) {
            requests->tail = 0;
        }
        requests->size++;
    }
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
        requests->head++;
        if (requests->head > MAX_REQUESTS) {
            requests->head = 0;
        }
        requests->size--;
    }
}

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

void new_user_requests(Requests* requests, int new_user_code){
    int comp = 1;
    for (int i = 0; i < MAX_USERS; ++i) {
        if(requests[i].code_user == 0 && comp == 1){
            requests[i].code_user = new_user_code;
            comp = 0;
        }
    }
}

void add_requests(Requests* requests, int new_request){
    requests->code_request[requests->tail] = new_request;
    requests->tail++;
    requests->size++;
}

Requests* search_user_requests(Requests* requests, int code_user){
    for (int i = 0; i < MAX_USERS; ++i) {
        if(requests[i].code_user == code_user){
            return &requests[i];
        }
    }
    return NULL;
}

void save_requests(Requests* requests, FILE* fr){
    for (int i = 0; i < MAX_USERS; ++i) {
        if(requests[i].code_user != 0){
            fprintf(fr, "%d. %d, ", requests[i].code_user, requests[i].size);
            for (int j = requests[i].head; j < requests[i].tail ; ++j) {
                fprintf(fr, "%d, ", requests[i].code_request[j]);
            }
        }
    }
}

void print_requests_graph(Requests* requests){
    printf("%d. ", requests->code_user);
    for (int j = requests->head; j < requests->tail; ++j) {
        printf("%d, ", requests->code_request[j]);
    }
    printf("\n");
}