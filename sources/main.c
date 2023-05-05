#include <stdio.h>

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
            FILE *fa = fopen("../resources/users.txt", "r");
            if (fa == NULL) return ERROR;
            ord_user(fa);
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
