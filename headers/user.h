#include <stdio.h>
#ifndef UNTITLED4_USER_H
#define UNTITLED4_USER_H
#define USERNAME_LENGTH 20 //Cantidad de caracteres máximo que puede tener un nombre de usuario
#define PASSWORD_LENGTH 30 //Cantidad de caracteres máximo que puede tener una contraseña
#define EMAIL_LENGTH 50 //Cantidad de caracteres máximo que puede tener un correo electrónico
#define UBICATION_LENGTH 20 //cantidad de caracteres de la ciudad
#define GUSTOS 20

enum Gustos {Videojuegos,
        Deportes,
        Musica,
        Literatura,
        Matematicas,
        Informática}; //Lista de gustos *CONSULTAR CON EL PROFE SI SE PUEDEN USAR ENUMERACIONES*

typedef struct {
    char id_name[USERNAME_LENGTH];
    char nombre[USERNAME_LENGTH];
    char contrasena[PASSWORD_LENGTH];
    int edad;
    char correo[EMAIL_LENGTH];
    char ubicacion[UBICATION_LENGTH];
    char gustos1 [GUSTOS];
    char gustos2 [GUSTOS];
    char gustos3 [GUSTOS];
    char gustos4 [GUSTOS];
    char gustos5 [GUSTOS];
} User;

User* init_users();
void create_user(User* u);
void loading_users(FILE* fa);

#endif //UNTITLED4_USER_H