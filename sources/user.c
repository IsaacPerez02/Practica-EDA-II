#include "../headers/user.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_USERS 2
#define USERNAME_LENGTH 20 //Cantidad de caracteres máximo que puede tener un nombre de usuario
#define PASSWORD_LENGTH 30 //Cantidad de caracteres máximo que puede tener una contraseña
#define EMAIL_LENGTH 50 //Cantidad de caracteres máximo que puede tener un correo electrónico
#define UBICATION_LENGTH 20 //cantidad de caracteres de la ciudad


//inicializamos el usuario nuevo
User* init_users (){
    User* us = (User*) malloc(sizeof (User));
    return us;
}

void create_user (User* u){
    // Asignacion de variables de usuario a la estructura
    printf("Empieza a crear tu usuario...\n");
    printf("Introduzca su ID: \n");
    scanf("%s", &u.id_name);
    printf("Introduzca su Nombre: \n");
    scanf("%s", &u.nombre);
    printf("Introduzca su contraseña: \n");
    scanf("%s", &u.contrasena);
    printf("Introduzca su edad: \n");
    scanf("%d", &u.edad);
    printf("Introduzca su correo: \n");
    scanf("%s", &u.correo);
    printf("Introduzca su ubicacion: \n");
    scanf("%s", &u.ubicacion);
}

void loading_users(FILE * fa){
    int success, i = 0;
    User users[MAX_USERS];
    success = fscanf(fa, "%s %s %s %d %s %s %s %s %s %s %s", users[i].id_name, users[i].nombre, users[i].contrasena, &users[i].edad, users[i].correo, users[i].ubicacion, users[i].gustos1, users[i].gustos2, users[i].gustos3, users[i].gustos4, users[i].gustos5);
    while (success > 10){
        i++;
        success = fscanf(fa, "%s %s %s %d %s %s %s %s %s %s %s", users[i].id_name, users[i].nombre, users[i].contrasena, &users[i].edad, users[i].correo, users[i].ubicacion, users[i].gustos1, users[i].gustos2, users[i].gustos3, users[i].gustos4, users[i].gustos5);
    }
}