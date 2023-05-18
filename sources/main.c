#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/user.h"
#include "../headers/user_list.h"
#define ERROR -1
#define SUCCESS 1

int main() {
    //Declaración de variables
    int opcion_menu = -1; //Opción del menú principal que el usuario escribirá por consola
    int opcion_usuario; //Opción de menú de operar como otro usuario
    int status = SUCCESS; //Variable para comprobar si el archivo de usuarios existe
    char gustos[6][GUSTOS] = {"A", "B", "C", "D", "E", "F"}; //Gustos disponibles
    User_list* list = NULL; //Lista de usuarios
    User* us; //Variable para la creación de un usuario

    //Comprobamos que el archivo existe
    FILE* init = fopen("../resources/users.txt", "r");
    if (init == NULL) status = ERROR; //
    if (status == SUCCESS){
        loading_users(init, &list);
    }
    if (status == SUCCESS) fclose(init);

    while (opcion_menu != 0) {
        printf("1.- Crear nuevo usuario\n");
        printf("2.- Listar todos los usuarios\n");
        printf("3.- Operar como otro usuario\n");
        printf("0.- Salir del programa\n");
        printf("Elige una opcion:\n");
        scanf("%d", &opcion_menu);

        if (opcion_menu == 1) {
            us = create_user(gustos);
            if (list == NULL) {
                first_user_created(&list, us);
            }
            else{
                add_user_created(&list, us);
            }
        }
        else if (opcion_menu == 2) {
            print_users(list);
        }
        else if (opcion_menu == 3) {
            char login_user[USERNAME_LENGTH];
            char login_pass[PASSWORD_LENGTH];
            User* check_us;
            printf("Introduce el nombre de usuario:\n");
            scanf("%s", login_user);
            printf("Introduce la contraseña:\n");
            scanf("%s", login_pass);
            check_us = check_user_password(list, login_user, login_pass);

            if (check_us != NULL) {
                opcion_usuario = -1;
                while(opcion_usuario != 0) {
                    printf("1.- Enviar solicitud de amistad\n");
                    printf("2.- Gestionar solicitudes pendientes\n");
                    printf("3.- Realizar una publicacion\n");
                    printf("4.- Listar las publicaciones de un usuario\n");
                    printf("5.- Revisar timeline\n");
                    printf("0.- Cerrar sesion y volver al menu principal\n");
                    printf("Elige una opcion:\n");
                    scanf("%d", &opcion_usuario);

                    if (opcion_usuario == 1) {
                        char check_friend_name[USERNAME_LENGTH];
                        User* friend;
                        printf("Introduce el nombre de usuario al que quieras agregar como amigo:\n");
                        scanf("%s", check_friend_name);

                        friend = search_user(list, check_friend_name);
                        if (friend != NULL) {
                            //Enviar solicitud a usuario
                        }
                        else {
                            printf("Ese usuario no existe\n");
                        }
                    }
                    else if (opcion_usuario == 2) {

                    }
                    else if (opcion_usuario == 3) {

                    }
                    else if (opcion_usuario == 4) {
                        char check_user_name[USERNAME_LENGTH];
                        User* user;
                        printf("Introduce el nombre de usuario al que quieras mirar sus publicaciones:\n");
                        scanf("%s", check_user_name);

                        user = search_user(list, check_user_name);
                        if (user != NULL) {
                            //Mostrar publicaciones del usuario seleccionado
                        }
                        else {
                            printf("Ese usuario no existe\n");
                        }
                    }
                    else if (opcion_usuario == 5) {
                        //Mostrar las publicaciones de todos los amigos
                    }
                    else if (opcion_usuario == 0) {
                        printf("Cerrando sesion...\n");
                    }
                    else {
                        printf("Tienes que elegir una opcion correcta.\n");
                    }
                }
            }
            else {
                printf("El nombre de usuario no existe o la contrasena no es correcta.\n");
            }
        }

        else if (opcion_menu == 0) {
            status = SUCCESS;
            FILE* finish = fopen("../resources/users.txt", "w");
            if (finish == NULL) status = ERROR;
            if (status == SUCCESS){
                save_all_users(list, finish);
            }
            if (status == SUCCESS) {
                fclose(finish);
            }
            printf("\nSaliendo del programa...");
        }
        else {
            printf("Tienes que elegir una opcion correcta.\n");
        }
    }
}