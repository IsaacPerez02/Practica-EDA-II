#include <stdio.h>
#include "defines.h"

#ifndef UNTITLED4_USER_H
#define UNTITLED4_USER_H

/**
 * Usuario del sistema
 * id_name: Nombre de usuario
 * code: Código del usuario
 * nombre: Nombre real del usuario
 * contrasena: Contraseña del usuario
 * edad: Edad del usuario
 * correo: Correo electrónico del usuario
 * ubicacion: Localización del usuario
 * gustos: Preferencias del usuario
 * requests: Cola de solicitudes del usuario
 */
typedef struct {
    char id_name[MAX_ID_NAME_LENGHT];
    int code;
    char nombre[MAX_NAME_LENGHT];
    char contrasena[MAX_PASSWORD_LENGHT];
    int edad;
    char correo[MAX_CORREO_LENGHT];
    char ubicacion[MAX_CITY_LENGHT];
    char gustos [MAX_GUSTOS][GUSTOS_LENGTH];
} User;

User* create_user(char gustos[MAX_GUSTOS][GUSTOS_LENGTH]);
int verify_id_name_user(char* id);
int verify_name_user(char* name);
int verify_password_user(char* pass);
int verify_correo_user(char* correo);
int verify_edad_user(int edad);
int verify_ciudad_user(char* city);
int verify_gusto_user(char gustos[5][GUSTOS_LENGTH], char gusto[GUSTOS_LENGTH]); //FALTA

#endif //UNTITLED4_USER_H