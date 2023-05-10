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
    User_list *list;
    User* us;

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
                list = first_user(us);
                printf("%s\n", list->us->id_name);
            }
            else{
                add_user(list, us);
                printf("%s\n", list->us->id_name);
            }
        } else if (opcion_menu == 2) {
            print_users(list);
        }
        else if (opcion_menu == 3) {
            /*
            User check_us;
            printf("Introduce el nombre de usuario:\n");
            scanf("%s", &check_us.nombre_usuario);
            printf("Introduce la contrasena de este usuario:\n");
            scanf("%s", &check_us.contrasena);
            check_us = search_user(list, check_us);

            if (strcmp(check_us.id_name, '\0')) {
                printf("Nombre de usuario o contrasena incorrectos.");
            }
            else {
                opcion_usuario = -1;
                while(opcion_usuario != 0) {
                    printf("Debes introducir una de las opciones\n");
                    printf("1.- Enviar solicitud de amistad\n");
                    printf("2.- Gestionar solicitudes pendientes\n");
                    printf("3.- Realizar una publicacion\n");
                    printf("4.- Listar las publicaciones de un usuario\n");
                    printf("0.- Cerrar sesion y volver al menu principal\n");
                    printf("Elige una opcion:\n");
                    scanf("%d", &opcion_usuario);

                    if (opcion_usuario == 1) {

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
            }*/
        }

        else if (opcion_menu == 0) {
            printf("\nSaliendo del programa...");
        }
        else {
            printf("Tienes que elegir una opcion correcta.\n");
        }
    }


}