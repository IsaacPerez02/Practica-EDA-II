#include <stdio.h>
#include <string.h>
#include "../headers/user.h"
#include "../headers/user_list.h"
#include "../headers/publications_users.h"
#include "../headers/friends_graph.h"

#define ERROR -1
#define SUCCESS 1
#define LINEA_ASTERISCOS "******************************"

int main() {
    //Declaración de variables
    int option_menu = -1; //Opción del menú principal que el usuario escribirá por consola
    int option_usuario; //Opción de menú de operar como otro usuario
    int status = SUCCESS; //Variable para comprobar si el archivo de usuarios existe
    char gustos[MAX_GUSTOS][GUSTOS_LENGTH] = {"Deporte", "Arte", "Informática", "Religión", "Animales", "Videojuegos",
                                              "Fiesta", "Estudiar", "Viajes", "Política"}; //Gustos disponibles
    User_list* users_list = NULL; //Lista de usuarios
    Friends* friends;
    Publications* publications_list;
    User *us; //Variable para la creación de un usuario

    //Comprobamos que el archivo existe. Si existe, cargamos la lista de usuarios del archivo y mostramos el menú
    //Si no existe el archivo, cerramos el programa
    FILE *init = fopen("../resources/users.txt", "r");
    if (init == NULL) status = ERROR;
    if (status == SUCCESS) {
        loading_users(init, &users_list);
        fclose(init);
    } else {
        return -1;
    }

    FILE *ff = fopen("../resources/friends.txt", "r");
    if (init == NULL) status = ERROR;
    if (status == SUCCESS) {
        friends = init_friends_user(users_list);
        publications_list = init_publications();
        load_friends(friends, ff);
        fclose(ff);
    } else {
        return -3;
    }

    //Menú de gestión del administrador. Opciones:
    //1: Crea un nuevo usuario y lo añade a la lista
    //2: Lista la información de todos los usuarios de la lista
    //3: Iniciamos sesión con un usuario. Para ello, necesitamos el nombre de usuario y su contraseña
    while (option_menu != 0) {
        printf("\n%s\n", LINEA_ASTERISCOS);
        printf("1.- Crear nuevo usuario\n");
        printf("2.- Listar todos los usuarios\n");
        printf("3.- Operar como otro usuario\n");
        printf("0.- Salir del programa\n");
        printf("Elija una opcion:\n");
        scanf("%d", &option_menu);

        if (option_menu == 1) {
            us = create_user(gustos);

            //Añadimos el usuario en la lista
            if (users_list == NULL) {
                first_user_created(&users_list, us);
            } else {
                add_user_created(&users_list, us);
            }

        } else if (option_menu == 2) {
            print_users(users_list);
        } else if (option_menu == 3) {
            char login_user[USERNAME_LENGTH];
            char login_pass[PASSWORD_LENGTH];
            User *login_us;
            printf("\n%s\n", LINEA_ASTERISCOS);
            printf("Introduzca el nombre de usuario:\n");
            scanf("%s", login_user);
            printf("Introduzca la contraseña:\n");
            scanf("%s", login_pass);
            //Comprobamos si el nombre de usuario introducido se encuentra en la lista de usuarios
            login_us = check_user_password(users_list, login_user, login_pass);

            //Si el usuario se encuentra en la lista, abrimos el menú de gestión del usuario
            if (login_us != NULL) {
                printf("Bienvenido, %s.\n", login_us->id_name);
                option_usuario = -1;
                //Menú de gestión del usuario. Opciones:
                //1: Envia una solicitud de amistad a un usuario que hemos introducido por consola
                //2: Muestra la lista de solicitudes de amistad del usuario. El usuario podrá aceptar o rechazar la solicitud
                //3: Escribe un mensaje por consola y lo añade al timeline
                //4: Muestra todas las publicaciones de un usuario específico
                //5: Muestra todas las publicaciones de todos tus amigos
                while (option_usuario != 0) {
                    printf("\n%s\n", LINEA_ASTERISCOS);
                    printf("1.- Enviar solicitud de amistad\n");
                    printf("2.- Gestionar solicitudes pendientes\n");
                    printf("3.- Listar amigos\n");
                    printf("4.- Realizar una publicacion\n");
                    printf("5.- Listar las publicaciones de un usuario\n");
                    printf("6.- Revisar timeline\n");
                    printf("0.- Cerrar sesion y volver al menu principal\n");
                    printf("Elija una opcion:\n");
                    scanf("%d", &option_usuario);

                    if (option_usuario == 1) {
                        char check_friend_name[USERNAME_LENGTH];
                        User *friend;
                        printf("Introduzca el nombre de usuario al que quiera agregar como amigo:\n");
                        scanf("%s", check_friend_name);

                        friend = search_user_id_name(users_list, check_friend_name);
                        if (friend != NULL) {
                            add_request_to_user_list(&users_list, friend->id_name, login_us->code);
                            printf("Solicitud enviada.\n");
                        } else {
                            printf("Ese usuario no existe.\n");
                        }
                    }
                    else if (option_usuario == 2) {
                        manage_requests(&users_list, login_us->code, friends);
                    }
                    else if (option_usuario == 3) {
                        Friends* friends_user = search_user_friends(friends, login_us->code);
                        print_friends_graph(friends_user);
                    }
                    else if (option_usuario == 4) {
                        char text[MAX_TEXT_LENGTH];
                        printf("Escriba su publicacion (120 MAX): \n");
                        while (getchar() != '\n');
                        fgets(text, sizeof(text), stdin);
                        text[strcspn(text, "\n")] = '\0'; // Eliminar salto de línea del final

                        if (strlen(text) <= 120) {
                            create_publication(&publications_list, login_us->code, text);
                            printf("Publicacion realizada\n");
                        } else {
                            printf("Tu publicacion excede 120 caracteres.\n");
                        }
                    }
                    else if (option_usuario == 5) {
                        char check_user_name[USERNAME_LENGTH];
                        User *user;
                        printf("Introduzca el nombre de usuario al que quiera mirar sus publicaciones:\n");
                        scanf("%s", check_user_name);

                        user = search_user_id_name(users_list, check_user_name);
                        if (user != NULL) {
                            print_publications(publications_list, *user);
                        } else {
                            printf("Ese usuario no existe.\n");
                        }
                    } else if (option_usuario == 6) {
                        //printTimeline(timeline);
                    } else if (option_usuario == 0) {
                        printf("Cerrando sesion...\n");
                    } else {
                        printf("Tiene que elegir una opcion correcta.\n");
                    }
                }
            } else {
                printf("El nombre de usuario no existe o la contrasena no es correcta.\n");
            }
        } else if (option_menu == 0) {
            status = SUCCESS;
            FILE *finish = fopen("../resources/users.txt", "w");
            //Comprobamos que el archivo existe. Si existe, guardamos todos los usuarios que hayamos agregado en el
            //archivo y salimos del programa
            //En caso de que el archivo no exista, saldrá un mensaje de error
            if (finish == NULL) status = ERROR;
            if (status == SUCCESS) {
                save_all_users(users_list, finish);
                fclose(finish);
            } else {
                printf("¡¡No se ha encontrado el archivo!! ¡¡Los usuarios agregados NO van a ser guardados!!\n");
            }
            printf("\n%s\n", LINEA_ASTERISCOS);
            printf("Saliendo del programa...");
            return 1;
        } else {
            printf("Tiene que elegir una opcion correcta.\n");
        }
    }
    return 0;
}