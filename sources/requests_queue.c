#include <malloc.h>
#include "../headers/requests_queue.h"
#define LINEA_ASTERISCOS "******************************"

//Función para inicializar la cola de solicitudes de un usuario
Requests* init_requests() {
    Requests* requests = NULL;
    for (int i = 0; i < MAX_FRIENDS; i++) {
        requests->code_friends[i] = 0;
    }
    requests->head = 0;
    requests->tail = 0;
    requests->size = 0;
    return requests;
}
/*
int count_friends(int list[MAX_FRIENDS]){
    int count = 0;
    for (int i = 0; i < MAX_FRIENDS; i++){
        if (list[i] != 0){
            count++;
        }
    }
    return count;
}
 */
/*
Requests* add_request(Requests* requests, int code_user, int code_request){
    Requests* heap = requests;
    int i = 0, index;
    while (i < requests->size){
        if (heap[i].code_user == code_user){
            index = count_friends(heap[i].code_friends);
            heap[i].code_friends[index] = code_request;
        }
    }
    return heap;
}
 */
/*
//Comprueba si la cola de solicitudes está vacía
int is_empty(Requests requests) {
    if (requests.size <= 0) {
        return 1;
    }
    else {
        return 0;
    }
}

//Comprueba si la cola de solicitudes está llena
int is_full(Requests requests) {
    if (requests.size == 10) {
        return 1;
    }
    else {
        return 0;
    }
}

//Devuelve el código del primer usuario de la cola de solicitudes
int first(Requests requests) {
    if (is_empty(requests) == 1) {
        return -1;
    }
    else {
        return requests.code_friends[requests.head];
    }
}
*/
/**
 * Carga la cola de solicitudes de todos los usuarios del archivo
 * @param requests_list: Lista de la cola de solicitudes de los usuarios
 * @param user_list: Lista de usuarios
 */
 /*
void loading_requests_code(Requests** requests_list, User_list** user_list) {
    User_list* heap = *user_list;
    int i = 0;
    while (heap != NULL) {
        requests_list[i] = init_requests();
        requests_list[i]->code_user = heap->us->code;
        heap = heap->next;
        i++;
    }
}

/**
 * Añade al último usuario recién creado a la lista de cola de solicitudes
 * @param requests_list: Lista de la cola de solicitudes de los usuarios
 * @param user_list: Lista de usuarios
 * @param user: Usuario recién creado
 */
 /*
void add_user_created_to_requests_list(Requests** requests_list, User_list* user_list, User* user) {
    int idx = get_request_list_size(&user_list) - 1;
    requests_list[idx] = init_requests();
    requests_list[idx]->code_user = user->code;
}

/**
 * Devuelve el tamaño de la lista de la cola de solicitudes de usuarios
 * @param user_List: Lista de usuarios
 * @return: Tamaño de la lista
 */
 /*
int get_request_list_size(User_list** user_List) {
    User_list* heap = *user_List;
    int size = 0;
    while (heap != NULL) {
        size++;
        heap = heap->next;
    }
    return size;
}

/**
 * Envia la solicitud de amistad al usuario correspondiente. Esta función actúa como un 'Enqueue'
 * @param requests_list: Lista de la cola de solicitudes de los usuarios
 * @param user_list: Lista de usuarios
 * @param code_user: Código del usuario que envía la solicitud
 * @param request_code: Código del usuario al que enviamos la solicitud
 */
 /*
void send_request(Requests** requests_list, User_list* user_list, int code_user, int request_code) {
    int requests_list_size = get_request_list_size(&user_list); //Tamaño de la lista
    //Comprobamos en la lista al usuario que queramos enviar la solicitud mediante su código
    for (int i = 0; i < requests_list_size; i++) {
        if (requests_list[i]->code_user == request_code) {
            int tail = requests_list[i]->tail; //Índice del tail
            requests_list[i]->code_friends[tail] = code_user; //Le enviamos la solicitud al usuario
            requests_list[i]->tail++; //Pasamos a la siguiente posición del tail
            //Si supera el tamaño total, ponemos el tail en la primera posición
            if (requests_list[i]->tail > 9) {
                requests_list[i]->tail = 0;
            }
            requests_list[i]->size++;
        }
    }
}

/**
 * Menú de gestión de solicitudes del usuario. Mostrará la cola de solicitudes para aceptarlas o rechazarlas por orden
 * de cuándo se recibieron
 * @param requests_list: Lista de la cola de solicitudes de los usuarios
 * @param user_list: Lista de usuarios
 * @param code_user: Código del usuario que está gestionando el menú
 */
 /*
void manage_requests(Requests** requests_list, User_list* user_list, int code_user) {
    int requests_list_size = get_request_list_size(&user_list); //Tamaño de la lista
    int option_request = -1;
    //Comprobamos en la lista al usuario que queramos enviar la solicitud mediante su código
    for (int i = 0; i < requests_list_size; i++) {
        if (requests_list[i]->code_user == code_user) {
            int head = requests_list[i]->head;
            //Comprobamos que el usuario tenga solicitudes pendientes. Si no las tiene, volveremos al menú anterior
            if (requests_list[i]->size != 0) {
                print_requests(requests_list[i]->code_friends, user_list, head, requests_list[i]->size);

                while (option_request != 0) {
                    head = requests_list[i]->head;
                    printf("\n%s\n", LINEA_ASTERISCOS);
                    printf("Que deseas hacer con la solicitud de %s?\n", search_user_code(user_list, requests_list[i]->code_friends[head])->id_name);
                    printf("1.- Aceptar\n");
                    printf("2.- Rechazar\n");
                    printf("0.- Atras\n");
                    printf("Elija una opcion:\n");
                    scanf("%d", &option_request);

                    if (option_request == 1) {
                        //Aceptar solicitud
                        printf("Solicitud aceptada\n");
                        //delete_request(requests_list, user_list, code_user);
                    }
                    else if (option_request == 2) {
                        //Rechazar solicitud
                        printf("Solicitud rechazada.\n");
                        //delete_request(requests_list, user_list, code_user);
                    }
                    else {
                        printf("Escoja una opcion correcta.\n");
                    }

                    //Si el usuario no tiene más solicitudes, volveremos al menú del usuario
                    if (requests_list[i]->head == requests_list[i]->tail) {
                        option_request = 0;
                    }

                    if (option_request == 0) {
                        printf("Saliendo de la gestion de solicitudes...\n");
                    }
                }
            }
            else {
                printf("No tienes solicitudes pendientes.\n");
            }
        }
    }
}

/**
 * Imprime el nombre de los usuarios de la cola de solicitudes
 * @param requests_queue: Cola de solicitudes del usuario
 * @param user_list: Lista de usuarios
 * @param head: Índice inicial de la cola
 * @param size: Tamaño de la cola
 */
 /*
void print_requests(int* requests_queue, User_list* user_list, int head, int size) {
    char* request_code;
    printf("\n%s\n", LINEA_ASTERISCOS);
    for (int i = head; i < size; i++) {
        request_code = search_user_code(user_list, requests_queue[i])->id_name;
        printf("%d.- %s\n", i + 1, request_code);
    }
}

/**
 * Borra la primera solicitud recibida. Esta función actúa como un 'Dequeue'
 * @param requests_list: Lista de la cola de solicitudes de los usuarios
 * @param user_list: Lista de usuarios
 * @param code_user: Código del usuario gestionando las solicitudes
 */
 /*
void delete_request(Requests** requests_list, User_list* user_list, int code_user) {
    int requests_list_size = get_request_list_size(&user_list);
    for (int i = 0; i < requests_list_size; i++) {
        if (requests_list[i]->code_user == code_user) {
            int head = requests_list[i]->head; //Índice del head
            requests_list[i]->code_friends[head] = 0; //Eliminamos la solicitud (asignamos el código de amigo como nulo)
            requests_list[i]->head++; //Pasamos a la siguiente posición del head
            //Si supera el tamaño total, ponemos el head en la primera posición
            if (requests_list[i]->head > 9) {
                requests_list[i]->head = 0;
            }
            requests_list[i]->size--; //Disminuimos el tamaño de la cola
        }
    }
}
*/