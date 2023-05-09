#include <stdio.h>
#include "../headers/user.h"
#define ERROR -1
#define SUCCESS 1

User login_usuario(User* us) {
    char nombre_usuario[USERNAME_LENGTH];
    char contrasena[PASSWORD_LENGTH];

    printf("Introduce el nombre de usuario:\n");
    scanf("%s", &nombre_usuario);
    printf("Introduce la contrasena de este usuario:\n");
    scanf("%s", &contrasena);

    char f_usuario[USERNAME_LENGTH];
    char f_contrasena[PASSWORD_LENGTH];

    //WIP: Comprobar si existe el usuario en el archivo / lista dinámica


}

int main() {
    int opcion_menu = -1;
    int opcion_usuario = -1;
    int success = SUCCESS;
    int global_users = 0;

    FILE *fread = fopen("../resources/users.txt", "r");
    if (fread == NULL) success = ERROR;
    User* us = init_users(fread);

    while (opcion_menu != 0) {
        printf("1.- Crear nuevo usuario\n");
        printf("2.- Listar todos los usuarios\n");
        printf("3.- Operar como otro usuario\n");
        printf("0.- Salir del programa\n");
        printf("Elige una opcion:\n");
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
            User usuario = login_usuario(us);

            while(opcion_usuario != 0) {
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
        }
        else if (opcion_menu == 3) {

        }
        else if (opcion_menu == 0) {
            printf("\nSaliendo del programa...");
        }
        else {
            printf("Tienes que elegir una opcion correcta.\n");
        }
    }

}
