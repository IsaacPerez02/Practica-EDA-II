#include <stdio.h>
#ifndef UNTITLED4_USER_H
#define UNTITLED4_USER_H
#define USERNAME_LENGTH 20 //Cantidad de caracteres máximo que puede tener un nombre de usuario
#define PASSWORD_LENGTH 30 //Cantidad de caracteres máximo que puede tener una contraseña
#define EMAIL_LENGTH 50 //Cantidad de caracteres máximo que puede tener un correo electrónico
#define UBICATION_LENGTH 20 //cantidad de caracteres de la ciudad
#define MAX_GUSTOS 10
#define GUSTOS_LENGTH 20

typedef struct {
    char id_name[USERNAME_LENGTH];
    int code;
    char nombre[USERNAME_LENGTH];
    char contrasena[PASSWORD_LENGTH];
    int edad;
    char correo[EMAIL_LENGTH];
    char ubicacion[UBICATION_LENGTH];
    char gustos [MAX_GUSTOS][GUSTOS_LENGTH];
    //Friends amigos;
} User;

User* create_user(char gustos[MAX_GUSTOS][GUSTOS_LENGTH]);
int verify_id_name_user(char* id); //FALTA
int verify_name_user(char* name);
int verify_password_user(char* pass);
int verify_correo_user(char* correo);
int verify_edad_user(int edad);
int verify_ciudad_user(char* city);
int verify_gusto_user(char gustos[5][GUSTOS_LENGTH], char gusto[GUSTOS_LENGTH]); //FALTA

#endif //UNTITLED4_USER_H