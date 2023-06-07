
#include "../headers/user.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

#define MAX_ID_NAME_LENGHT 20
#define MAX_NAME_LENGHT 20
#define MAX_PASSWORD_LENGHT 20
#define MAX_CORREO_LENGHT 30
#define MAX_CITY_LENGHT 20
#define MAX_GUSTOS 10
#define MAX_USERS 20
#define GUSTOS_LENGTH 20
#define ERROR -1
#define LINEA_ASTERISCOS "********************"

/**
 * Crea a un nuevo usuario
 * @param gustos: Gustos que podrá elegir el usuario
 * @return: Devuelve al usuario recién creado con casi todos sus campos completos
 */
User* create_user (char gustos[MAX_GUSTOS][GUSTOS_LENGTH]){
    User* u = (User*) malloc(sizeof (User));
    int indice, status, status_gusto;

    //Asignacion de variables de usuario a la estructura
    //Introducir el nombre de usuario
    printf("\n%s\n", LINEA_ASTERISCOS);
    printf("Empiece a crear su usuario...\n");
    printf("Introduzca su nombre de usuario: \n");
    scanf("%s", u->id_name);
    printf("El nombre de usuario ha sido introducido correctamente.\n");

    //Introducir el nombre
    printf("\n%s\n", LINEA_ASTERISCOS);
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
    printf("\n%s\n", LINEA_ASTERISCOS);
    printf("Introduzca su contrasena. La contraseña debe tener 8 caracteres, 1 minúscula, 1 mayúscula y 1 número:\n");
    scanf("%s", u->contrasena);
    status = verify_password_user(u->contrasena);
    while (status == FALSE) {
        printf("Introduzca su contrasena. La contraseña debe tener 8 caracteres, 1 minúscula, 1 mayúscula y 1 número:\n");
        scanf("%s", u->contrasena);
        status = verify_password_user(u->contrasena);
    }
    printf("La contrasena ha sido introducida correctamente.\n");

    //Introducir la edad
    printf("\n%s\n", LINEA_ASTERISCOS);
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
    printf("\n%s\n", LINEA_ASTERISCOS);
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
    printf("\n%s\n", LINEA_ASTERISCOS);
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
    printf("\n%s\n", LINEA_ASTERISCOS);
    for (int i = 0; i < MAX_GUSTOS; i++){
        printf("%d. %s \n", i + 1, gustos[i]);
    }
    for (int i = 0; i < 5; i++) {
        printf("Introduzca su gusto %d: \n", i + 1);
        scanf("%d", &indice);
        indice--;
        status_gusto = verify_gusto_user(u->gustos, gustos[indice]);
        while (status_gusto != TRUE) {
            printf("Ese gusto ya ha sido introducido.\nIntroduzca de nuevo un gusto diferente:\n");
            scanf("%d", &indice);
            indice--;
            status_gusto = verify_gusto_user(u->gustos, gustos[indice]);
        }
        strcpy(u->gustos[i], gustos[indice]);
    }

    printf("\n%s\n", LINEA_ASTERISCOS);
    return u;
}

int verify_id_name_user(char* id){

}

/**
 * Comprueba que el nombre real introducido no tenga números
 * @param name: Nombre real introducido
 * @return: TRUE si el nombre real no tiene números; FALSE si tiene números
 */
int verify_name_user(char* name) {
    int i = 0;
    while (name[i] != '\0') { //\0 = NULL
        if (48 >= name[i] || name[i] <= 57) {
            printf("Tu nombre no puede contener números.\n");
            return FALSE;
        }
        i++;
    }
    return TRUE;
}

/**
 * Comprueba que la contraseña introducida cumpla los siguientes requisitos:
 * · Contenga 8 letras o más
 * · Contenga 1 minúscula o más
 * · Contenga 1 mayúscula o más
 * · Contenga 1 número o más
 * @param pass: Contraseña introducida
 * @return: Devuelve TRUE si se cumplen todas las condiciones; FALSE si no se cumplen todas las condiciones
 */
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
        strcat(mensaje_error, "Tu contraseña debe contener 8 caracteres o más.\n");
    }

    //Minúsculas
    if (minusculas >= 1) {
        condiciones_cumplidas++;
    }
    else {
        strcat(mensaje_error, "Tu contraseña debe contener al menos 1 minúscula\n");
    }

    //Mayúsculas
    if (mayusculas >= 1) {
        condiciones_cumplidas++;
    }
    else {
        strcat(mensaje_error, "Tu contraseña debe contener al menos 1 mayúscula\n");
    }

    //Números
    if (numeros >= 1) {
        condiciones_cumplidas++;
    }
    else {
        strcat(mensaje_error, "Tu contraseña debe contener al menos 1 número\n");
    }

    if (condiciones_cumplidas == 4) {
        return TRUE;
    }
    printf("Faltan datos en tu contraseña:");
    printf("%s", mensaje_error);
    return FALSE;
}

/**
 * Comprueba que el correo electrónico introducido contenga @
 * @param correo: Correo electrónico introducido
 * @return: Devuelve TRUE si el correo introducido contiene @; FALSE si no contiene @
 */
int verify_correo_user(char* correo) {
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
        printf("El correo introducido no es correcto.\n");
        return FALSE;
    }
}

/**
 * Comprueba que la edad introducida sea un número positivo y mayor que 18
 * @param edad: Edad introducida
 * @return: Devuelve TRUE si la edad introducida es un número positivo mayor que 18; FALSE si no cumple las dos condiciones
 */
int verify_edad_user(int edad) {
    if (0 < edad && edad < 18) {
        printf("La edad mínima debe ser de 18 años.\n");
        return FALSE;
    }
    else if (edad <= 0){
        printf("La edad debe ser positiva.\n");
        return FALSE;
    }
    return TRUE;
}

/**
 * Comprueba que la ciudad introducida no tenga números
 * @param city: Ciudad introducida
 * @return: Devuelve TRUE si la ciudad introducida no tiene números; FALSE si no es el caso
 */
int verify_ciudad_user(char* city) {
    int i = 0;
    while(city[i] != '\0'){
        if(isdigit(city[i])){
            printf("La ciudad no puede tener números.\n");
            return FALSE;
        }
        i++;
    }
    return TRUE;
}

/**
 * Comprueba que no se introduzca un gusto que se haya introducido con anterioridad
 * @param gustos: Lista de gustos elegidos
 * @param gusto: Gusto elegido
 * @return: Devuelve TRUE si el gusto recién elegido no coincide con un gusto anterior; FALSE si no es el caso
 */
int verify_gusto_user(char gustos[5][GUSTOS_LENGTH], char gusto[GUSTOS_LENGTH]) {
    for (int i = 0; i < 5; i++) {
        if (strcmp(gustos[i], gusto) == 0) {
            return FALSE;
        }
    }
    return TRUE;
}

/**
 * Funcion para contar el numero de amigos totales que tenemos
 * @param friends
 * @return numero de amigos totales
 */
int count_friends(int friends[MAX_FRIENDS]){
    int counter = 0;
    for (int i = 0; i < MAX_FRIENDS; ++i) {
        if (friends[i] != 0){
            counter++;
        }
    }
    return counter;
}