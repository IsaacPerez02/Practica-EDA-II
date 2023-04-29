//
// Created by adria on 29/04/2023.
//

#ifndef UNTITLED4_USER_H
#define UNTITLED4_USER_H
#define USERNAME_CHARS 20 //Cantidad de caracteres máximo que puede tener un nombre de usuario
#define PASSWORD_CHARS 30 //Cantidad de caracteres máximo que puede tener una contraseña
#define EMAIL_CHARS 50 //Cantidad de caracteres máximo que puede tener un correo electrónico

enum Ubicacion {Barcelona}; //Lista de ciudades *CONSULTAR CON EL PROFE SI SE PUEDEN USAR ENUMERACIONES*
enum Gustos {Videojuegos,
        Deportes,
        Música,
        Literatura,
        Matemáticas,
        Informática}; //Lista de gustos *CONSULTAR CON EL PROFE SI SE PUEDEN USAR ENUMERACIONES*

typedef struct {
    char nombre[USERNAME_CHARS];
    char contraseña[PASSWORD_CHARS];
    int edad;
    char correo[EMAIL_CHARS];
    enum Ubicacion ubicacion;
    enum Gustos gustos[5];
} User;

#endif //UNTITLED4_USER_H