#include <stdio.h>
#include "../headers/user.h"
#define ERROR -1

int main() {
    int opcion_menu = -1;
    int opcion_usuario = -1;
    while (opcion_menu != 0) {
        printf("1.- Crear nuevo usuario\n");
        printf("2.- Listar todos los usuarios\n");
        printf("3.- Operar como otro usuario\n");
        printf("0.- Salir del programa\n");
        printf("Elige una opcion: \n");
        scanf("%d", &opcion_menu);

        if (opcion_menu == 1) {
            User u;
            FILE *fa = fopen("../resources/users.txt", "a");
            if (fa == NULL) success = ERROR;
            if (success = SUCCESS) {
                create_user(&us);

                fprintf(fa, "%s %s %s %d %s %s %s %s %s %s %s", u[global_users].id_name, u[global_users].nombre, u[global_users].contrasena, u[global_users].edad, u[global_users].correo, u[global_users].ubicacion, u[global_users].gustos1, u[global_users].gustos2, u[global_users].gustos3, u[global_users].gustos4, users[i].gustos5));

                global_users = global_users + 1;

            }
        }
        else if (opcion_menu == 2) {
            //Añadir función para escribir un nombre de usuario y contraseña para logearse
            //Comprobar si el usuario existe
        }
        else if (opcion_menu == 3) {

        }
    }

    printf("\nSaliendo del programa...");

}
