
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
#define MAX_GUSTOS 6
#define GUSTOS_LENGTH 20

User* create_user (char gustos[MAX_GUSTOS][GUSTOS_LENGTH]){
    User* u = (User*) malloc(sizeof (User));
    int indice, status, status_gusto;
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
    printf("Introduzca su contrasena (longitud 8, 1 minuscula, 1 mayuscula y 1 numero): \n");
    scanf("%s", u->contrasena);
    status = verify_password_user(u->contrasena);
    while (status == FALSE) {
        printf("Introduzca su contrasena (longitud 8, 1 minuscula, 1 mayuscula y 1 numero): \n");
        scanf("%s", u->contrasena);
        status = verify_password_user(u->contrasena);
    }
    printf("La contrasena ha sido introducida correctamente.\n");

    //Introducir la edad
    printf("Introduzca su edad: \n");
    scanf("%d", &u->edad);

    status = verify_edad_user(u->edad);
    while (status == FALSE){
        printf("Introduzca su edad: \n");
        scanf("%d", &u->edad);
        status = verify_edad_user(u->edad);
    }
    printf("La edad ha sido introducida correctamente.\n");

    //Introducir el correo
    printf("Introduzca su correo: \n");
    scanf("%s", u->correo);

    status = verify_correo_user(u->correo);
    while (status == FALSE) {
        printf("Introduzca su correo: \n");
        scanf("%s", u->correo);
        status = verify_correo_user(u->correo);
    }
    printf("El correo ha sido introducido correctamente.\n");

    //Introducir ubicación
    printf("Introduzca su ubicacion: \n");
    scanf("%s", u->ubicacion);
    status = verify_ciudad_user(u->ubicacion);
    while (status == FALSE){
        printf("Introduzca su ubicacion: \n");
        scanf("%s", u->ubicacion);
        status = verify_ciudad_user(u->ubicacion);
    }
    printf("La ciudad ha sido introducida correctamente.\n");

    //Introducir gustos
    for (int i = 0; i < MAX_GUSTOS; i++){
        printf("%d. %s \n", i + 1, gustos[i]);
    }
    for (int i = 0; i < 5; i++) {
        printf("Introduzca su gusto: \n");
        scanf("%d", &indice);
        indice--;
        status_gusto = verify_gusto_user(u->gustos, gustos[indice]);
        while (status_gusto != TRUE) {
            printf("El gusto ya ha sido introducido!\nIntroduzca de nuevo un gusto diferente:\n");
            scanf("%d", &indice);
            indice--;
            status_gusto = verify_gusto_user(u->gustos, gustos[indice]);
        }
        strcpy(u->gustos[i], gustos[indice]);
    }
    return u;
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
    char mensaje_error[500] = {'\n'}; //Mensaje de error si no se cumplen todas las condiciones. Concatenaremos un
    //un string indicando qué condiciones faltan al final.
    int condiciones_cumplidas = 0; //Por cada condición cumplida, sumamos 1. Si se cumplen todas, la contraseña es correcta

    while (pass[i] != '\0') {
        //Comprobamos si contiene una minúscula
        if (islower(pass[i]) > 0) {
            minusculas++;
        }

        //Comprobamos si contiene una mayúscula
        if (isupper(pass[i]) > 0) {
            mayusculas++;
        }

        //Comprobamos si contiene un número
        if (isdigit(pass[i]) > 0) {
            numeros++;
        }

        i++;
    }

    //Comprobamos si se han cumplido todas las condiciones de la contraseña
    //Longitud
    if (i >= 8) {
        condiciones_cumplidas++;
    }
    else {
        strcat(mensaje_error, "Tu contrasena debe contener una longitud de 8 o mas.\n");
    }

    //Minúsculas
    if (minusculas >= 1) {
        condiciones_cumplidas++;
    }
    else {
        strcat(mensaje_error, "Tu contrasena debe contener al menos una minuscula\n");
    }

    //Mayúsculas
    if (mayusculas >= 1) {
        condiciones_cumplidas++;
    }
    else {
        strcat(mensaje_error, "Tu contrasena debe contener al menos una mayuscula\n");
    }

    //Números
    if (numeros >= 1) {
        condiciones_cumplidas++;
    }
    else {
        strcat(mensaje_error, "Tu contrasena debe contener al menos un numero\n");
    }

    if (condiciones_cumplidas == 4) {
        return TRUE;
    }
    printf("Faltan datos en tu contrasena:");
    printf("%s", mensaje_error);
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


int verify_gusto_user(char gustos[5][GUSTOS_LENGTH], char gusto[GUSTOS_LENGTH]){
    for (int i = 0; i < 5; i++){
        if (strcmp(gustos[i], gusto) == 0) {
            return FALSE;
        }
    }
    return TRUE;
}