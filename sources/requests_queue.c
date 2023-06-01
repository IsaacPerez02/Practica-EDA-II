#include <malloc.h>
#include "../headers/requests_queue.h"

Requests* init_requests() {
    Requests* requests = (Requests*) malloc(sizeof (Requests));
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

int get_size(Requests* requests_queue, User_list** user_List) {
    User_list* heap = *user_List;
    int i = 0;
    int size = 0;
    while (heap != NULL) {
        printf("%d\n", requests_queue[i].code_user);
        printf("%d\n", heap->us->code);
        if (requests_queue[i].code_user == heap->us->code) {
            size++;
        }
        heap = heap->next;
        i++;
    }

    return size;
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

void loading_requests_code(Requests** requests_queue, User_list** user_list) {
    User_list* heap = *user_list;
    int i = 0;
    while (heap != NULL) {
        requests_queue[i] = init_requests();
        requests_queue[i]->code_user = heap->us->code;
        heap = heap->next;
        i++;
    }
}