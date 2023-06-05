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
    return (requests->size == MAX_FRIENDS);
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
    if (requests->size == MAX_FRIENDS) {
        printf("No se pueden enviar mas solicitudes a este usuario.\n");
    }
    else {
        int tail = requests->tail;
        requests->code_request[tail] = request_code;
        requests->tail++;
        if (requests->tail > MAX_FRIENDS) {
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
        if (requests->head > MAX_FRIENDS) {
            requests->head = 0;
        }
        requests->size--;
    }
}