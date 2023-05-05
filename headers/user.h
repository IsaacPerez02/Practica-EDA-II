#include <stdio.h>
#ifndef UNTITLED4_USER_H
#define UNTITLED4_USER_H
#define USERNAME_LENGTH 20 //Cantidad de caracteres máximo que puede tener un nombre de usuario
#define PASSWORD_LENGTH 30 //Cantidad de caracteres máximo que puede tener una contraseña
#define EMAIL_LENGTH 50 //Cantidad de caracteres máximo que puede tener un correo electrónico
#define UBICATION_LENGTH 20 //cantidad de caracteres de la ciudad

enum Gustos {Videojuegos,
        Deportes,
        Musica,
        Literatura,
        Matematicas,
        Informática}; //Lista de gustos *CONSULTAR CON EL PROFE SI SE PUEDEN USAR ENUMERACIONES*

typedef struct {
    char nombre[USERNAME_CHARS];
    char contraseña[PASSWORD_CHARS];
    int edad;
    char correo[EMAIL_LENGTH];
    char ubicacion[UBICATION_LENGTH];
    enum Gustos gustos[5];
} User;

void init_user();
void ord_user(FILE* fa);

#endif //UNTITLED4_USER_H