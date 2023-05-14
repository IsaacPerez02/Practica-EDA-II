
#include "../headers/user.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

#define USERNAME_LENGTH 20 //Cantidad de caracteres máximo que puede tener un nombre de usuario
#define PASSWORD_LENGTH 30 //Cantidad de caracteres máximo que puede tener una contraseña
#define EMAIL_LENGTH 50 //Cantidad de caracteres máximo que puede tener un correo electrónico
#define UBICATION_LENGTH 20 //cantidad de caracteres de la ciudad
#define GUSTOS 6
#define MAX_LENGTH 200

User* create_user (char gustos[6][GUSTOS]){
    User* u = (User*) malloc(sizeof (User));
    int indice, status;
    // Asignacion de variables de usuario a la estructura
    printf("Empieza a crear tu usuario...\n");
    printf("Introduzca su ID: \n");
    scanf("%s", u->id_name);

    //Introducir el nombre
    printf("Introduzca su nombre: \n");
    scanf("%s", u->nombre);
    status = verify_name_user(u->nombre);
    while(status == FALSE) {
        printf("Introduzca su nombre: \n");
        scanf("%s", u->nombre);
        status = verify_name_user(u->nombre);
    }
    printf("El nombre ha sido introducido correctamente.\n");

    //Introducir la contraseña
    printf("Introduzca su contrasena: \n");
    scanf("%s", u->contrasena);
    status = verify_password_user(u->contrasena);
    while (status == FALSE) {
        printf("Introduzca su contrasena: \n");
        scanf("%s", u->contrasena);
        status = verify_password_user(u->contrasena);
    }
    printf("La contrasena ha sido introducida correctamente.");

    printf("Introduzca su edad: \n");
    scanf("%d", &u->edad);

    status = verify_edad_user(u->edad);
    while (status == FALSE){
        printf("Introduzca su edad: \n");
        scanf("%d", &u->edad);
        status = verify_edad_user(u->edad);
    }
    printf("La edad ha sido introducida correctamente.\n");

    printf("Introduzca su correo: \n");
    scanf("%s", u->correo);

    status = verify_correo_user(u->correo);
    while (status == FALSE) {
        printf("Introduzca su correo: \n");
        scanf("%s", u->correo);
        status = verify_correo_user(u->correo);
    }
    printf("El correo ha sido introducido correctamente.\n");

    printf("Introduzca su ubicacion: \n");
    scanf("%s", u->ubicacion);
    status = verify_ciudad_user(u->ubicacion);
    while (status == FALSE){
        printf("Introduzca su ubicacion: \n");
        scanf("%s", u->ubicacion);
        status = verify_ciudad_user(u->ubicacion);
    }
    printf("La ciudad ha sido introducida correctamente.\n");

    for (int i = 0; i < GUSTOS; i++){
        printf("%d. %s \n", i + 1, gustos[i]);
    }
    printf("Introduzca sus gustos uno por uno: \n");
    for (int i = 0; i < 5; i++){
        printf("%d: \n", i + 1, gustos[i]);
        scanf("%d", &indice);
        indice--;
        strcpy(u->gustos[i], gustos[indice]);
    }
    return u;
}

User* init_user_txt(FILE* fa, int* count){
    int count_function;
    char buffer[MAX_LENGTH];
    User* us = (User*) malloc(sizeof (User));
    fgets(buffer, MAX_LENGTH, fa);
    return us;
}

int verify_id_name_user(char* id){
}

int verify_name_user(char* name) {
    int i = 0;
    while (name[i] != '\0') { //\0 = NULL
        if (48 >= name[i] || name[i] <= 57) {
            printf("Tu nombre no puede contener numeros.\n");
            return FALSE;
        }
        i++;
    }
    return TRUE;
}

//La contraseña debe de tener longitud 8 o superior, 1 minúscula, 1 mayúscula y 1 número
int verify_password_user(char* pass) {
    int minusculas = 0;
    int mayusculas = 0;
    int numeros = 0;
    int i = 0; //El índice equivale a la longitud de la contraseña

    while (pass[i] != '\0') {
        //Comprobamos si contiene una minúscula
        if (97 >= pass[i] || pass[i] <= 122) {
            minusculas++;
        }

        //Comprobamos si contiene una mayúscula
        if (65 >= pass[i] || pass[i] <= 90) {
            mayusculas++;
        }

        //Comprobamos si contiene un número
        if (48 >= pass[i] || pass[i] <= 57) {
            numeros++;
        }

        i++;
    }

    if (i >= 8) {
        if (minusculas >= 1) {
            if (mayusculas >= 1) {
                if (numeros >= 1) {
                    return TRUE;
                }
                else {
                    printf("No has introducido un numero en tu contrasena.\n");
                }
            }
             else {
                 printf("No has introducido una mayuscula en tu contrasena.\n");
             }
        } else {
            printf("No has introducido una minuscula en tu contrasena.\n");
        }
    }
    else {
        printf("Tu contrasena tiene longitud %d. Debe de tener longitud de 8 o mas.\n", i);
    }

    return FALSE;
}

int verify_correo_user(char* correo) {
    int status = TRUE;
    int i = 0;
    int contador = 0;
    while (correo[i] != '\0'){
        if(correo[i] == '@'){
            contador ++;
            i ++;
        }
        else{
            i ++;
        }
    }
    if(contador == 1){
        return TRUE;
    }
    else{
        printf("El correo introducido no es correcto \n");
        return FALSE;
    }
}

int verify_edad_user(int edad) {
    if (0 < edad && edad < 18) {
        printf("La edad minima debe ser de 18 años!!\n");
        return FALSE;
    }
    else if (edad <= 0){
        printf("La edad debe ser positiva!!\n");
        return FALSE;
    }
    return TRUE;
}

int verify_ciudad_user(char* city) {
    int i = 0;
    while(city[i] != '\0'){
        if(isdigit(city[i])){
            printf("La ciudad no puede tener numeros!!\n");
            return FALSE;
        }
        i++;
    }
    return TRUE;
}


int verify_gusto_user(char* gusto){
    int status = TRUE;
}