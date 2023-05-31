#ifndef UNTITLED4_PUBLICATIONS_USERS_H
#define UNTITLED4_PUBLICATIONS_USERS_H
#define MAX_WORDS 120

typedef struct Publications {
    char publication[MAX_WORDS];
    struct Publications* next;
    struct Publications* last;
}Publications;

#endif //UNTITLED4_PUBLICATIONS_USERS_H
