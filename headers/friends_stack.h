#ifndef UNTITLED4_FRIENDS_STACK_H
#define UNTITLED4_FRIENDS_STACK_H
#include "../headers/user_list.h"
#define MAX_FRIENDS 10

typedef struct {
    User* friends[MAX_FRIENDS];
    int code;
    int top;
    int size;
}Friends;

Friends* init_friends(); //FALTA DESARROLLAR TODAS LAS FUNCIONES PARA LOS AMIGOS INTRODUCIDOS EN LA COLA DE CADA USUARIO ASI COMO
                         //ENTRELAZAR LOS AMIGOS DE CADA USUARIO CON SU ESTRUCTURA DE DATOS

#endif //UNTITLED4_FRIENDS_STACK_H
