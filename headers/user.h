#include <stdio.h>
#include "requests_queue.h"

#ifndef UNTITLED4_USER_H
#define UNTITLED4_USER_H
#define USERNAME_LENGTH 20 //Cantidad de caracteres máximo que puede tener un nombre de usuario
#define PASSWORD_LENGTH 30 //Cantidad de caracteres máximo que puede tener una contraseña
#define EMAIL_LENGTH 50 //Cantidad de caracteres máximo que puede tener un correo electrónico
#define UBICATION_LENGTH 20 //cantidad de caracteres de la ciudad
#define MAX_FRIENDS 10
#define MAX_GUSTOS 10
#define GUSTOS_LENGTH 20
#define MAX_CHARACTERS 120

/**
 * Usuario del sistema
 * id_name: Nombre de usuario
 * code: Código del usuario
 * nombre: Nombre real del usuario
 * contrasena: Contraseña del usuario
 * edad: Edad del usuario
 * correo: Correo electrónico del usuario
 * ubicacion: Localización del usuario
 * Gustos: Preferencias del usuario
 * requests: Cola de solicitudes del usuario
 */
typedef struct {
    char id_name[USERNAME_LENGTH];
    int code;
    char nombre[USERNAME_LENGTH];
    char contrasena[PASSWORD_LENGTH];
    int edad;
    char correo[EMAIL_LENGTH];
    char ubicacion[UBICATION_LENGTH];
    char gustos [MAX_GUSTOS][GUSTOS_LENGTH];
    int friends[MAX_FRIENDS];
    Requests requests;
} User;

User* create_user(char gustos[MAX_GUSTOS][GUSTOS_LENGTH]);
int verify_id_name_user(char* id);
int verify_name_user(char* name);
int verify_password_user(char* pass);
int verify_correo_user(char* correo);
int verify_edad_user(int edad);
int verify_ciudad_user(char* city);
int verify_gusto_user(char gustos[5][GUSTOS_LENGTH], char gusto[GUSTOS_LENGTH]); //FALTA

int count_friends(int friends[MAX_FRIENDS]);
void add_friends(User* us, int new_id_code);
void delete_friends(User* us, int delete_id_code);

#endif //UNTITLED4_USER_H