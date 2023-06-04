#include <malloc.h>
#include "../headers/manage_requests_queue.h"

Manage_requests* init_manage() {
    Manage_requests* manage_requests = (Manage_requests*) malloc(sizeof (Manage_requests));
    manage_requests->next = NULL;
    return manage_requests;
}

Requests* add_request(Requests* requests, int code_user, int code_request) {

}

Requests* delete_request(Requests* requests, int code_user) {

}

Manage_requests search_manage_request(Manage_requests manage_requests, int code_user) {

}