#include <stdio.h>
#ifndef UNTITLED4_USER_H
#define UNTITLED4_USER_H
#define USERNAME_LENGTH 20 //Cantidad de caracteres máximo que puede tener un nombre de usuario
#define PASSWORD_LENGTH 30 //Cantidad de caracteres máximo que puede tener una contraseña
#define EMAIL_LENGTH 50 //Cantidad de caracteres máximo que puede tener un correo electrónico
#define UBICATION_LENGTH 20 //cantidad de caracteres de la ciudad
#define GUSTOS 6

typedef struct {
    char id_name[USERNAME_LENGTH];
    int code;
    char nombre[USERNAME_LENGTH];
    char contrasena[PASSWORD_LENGTH];
    int edad;
    char correo[EMAIL_LENGTH];
    char ubicacion[UBICATION_LENGTH];
    char gustos [5][GUSTOS];
} User;

User* create_user(char gustos[6][GUSTOS]);
User* init_user_txt(FILE* fa); //FALTA
int verify_id_name_user(char* id); //FALTA
int verify_name_user(char* name);
int verify_password_user(char* pass);
int verify_correo_user(char* correo);
int verify_edad_user(int edad);
int verify_ciudad_user(char* city);
int verify_gusto_user(char* gusto); //FALTA
User* loading_users(FILE* fa);

#endif //UNTITLED4_USER_H