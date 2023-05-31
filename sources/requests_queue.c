#include "../headers/requests_queue.h"

Requests* init_requests() {
    Requests* requests = NULL;
    requests->code_user = 0;
    requests->head = 0;
    requests->tail = 0;
    requests->size = 0;
    return requests;
}

int is_empty(Requests requests) {
    if (requests.size <= 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int is_full(Requests requests) {
    if (requests.size == 10) {
        return 1;
    }
    else {
        return 0;
    }
}

int first(Requests requests) {
    if (is_empty(requests) == 1) {
        return -1;
    }
    else {
        return requests.code_friends[requests.head];
    }
}

Requests* accept_request(Requests* requests_queue, int code_user, int friend_code) {
    int tail = requests_queue[code_user].tail; //Índice del tail
    requests_queue[code_user].code_friends[tail] = friend_code; //Aceptamos la solicitud (le asignamos el código de amigo)
    requests_queue[code_user].tail++; //Pasamos a la siguiente posición del tail
    //Si supera el tamaño total, ponemos el tail en la primera posición
    if (requests_queue[code_user].tail > 9) {
        requests_queue[code_user].tail = 0;
    }
    requests_queue[code_user].size++; //Aumentamos el tamaño de la cola
    return requests_queue;
}

Requests* delete_request(Requests* requests_queue, int code_user) {
    int head = requests_queue[code_user].head; //Índice del head
    requests_queue[code_user].code_friends[head] = 0; //Eliminamos la solicitud (asignamos el código de amigo como nulo)
    requests_queue[code_user].head++; //Pasamos a la siguiente posición del head
    //Si supera el tamaño total, ponemos el head en la primera posición
    if (requests_queue[code_user].head > 9) {
        requests_queue[code_user].head = 0;
    }
    requests_queue[code_user].size--; //Disminuimos el tamaño de la cola
    return requests_queue;
}