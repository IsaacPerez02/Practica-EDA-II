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
    int status = SUCCESS;
    char gustos[6][GUSTOS] = {"A", "B", "C", "D", "E", "F"}; //Gustos disponibles
    User_list* list = NULL;
    User* us;

    FILE* init = fopen("../resources/users.txt", "r");
    if (init == NULL) status = ERROR;
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
                first_user_created(us, &list);
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
            User check_us;
            printf("Introduce el nombre de usuario:\n");
            scanf("%s", &login_user);
            check_us = *search_user(list, login_user);

            if (strcmp(check_us.id_name, '\0') == 0) {
                printf("Ese usuario no existe.\n");
            }
            else {
                printf("Introduce la contrasena de este usuario:\n");
                scanf("%s", &login_pass);
                if (strcmp(check_us.contrasena, login_pass) == 0) {
                    printf("Bienvenido, %s\n", check_us.id_name);
                    opcion_usuario = -1;
                    while(opcion_usuario != 0) {
                        printf("1.- Enviar solicitud de amistad\n");
                        printf("2.- Gestionar solicitudes pendientes\n");
                        printf("3.- Realizar una publicacion\n");
                        printf("4.- Listar las publicaciones de un usuario\n");
                        printf("0.- Cerrar sesion y volver al menu principal\n");
                        printf("Elige una opcion:\n");
                        scanf("%d", &opcion_usuario);

                        if (opcion_usuario == 1) {
                            char check_friend_name[USERNAME_LENGTH];
                            User friend;
                            printf("Escribe el nombre de usuario al que quieras agregar como amigo:\n");
                            scanf("%s", &check_friend_name);

                            friend = *search_user(list, check_friend_name);
                            if (strcmp(friend.id_name, '\0') == 0) {
                                printf("Ese usuario no existe\n");
                            }
                            else {

                            }
                        }
                        else if (opcion_usuario == 2) {

                        }
                        else if (opcion_usuario == 3) {

                        }
                        else if (opcion_usuario == 4) {

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
                    printf("Contrasena incorrecta.\n");
                }
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