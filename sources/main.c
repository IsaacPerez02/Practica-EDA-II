#include <stdio.h>
#include <string.h>
#include "../headers/user.h"
#include "../headers/user_list.h"
#include "../headers/publications_users.h"
#include "../headers/requests_queue.h"
#include "../headers/requests_stack.h"

#define MAX_FRIENDS 10
#define MAX_USERS 20

#define ERROR -1
#define SUCCESS 1
#define LINEA_ASTERISCOS "******************************"

int main() {
    //Declaración de variables
    int option_menu = -1; //Opción del menú principal que el usuario escribirá por consola
    int option_usuario; //Opción de menú de operar como otro usuario
    int status = SUCCESS; //Variable para comprobar si el archivo de usuarios existe
    char gustos[MAX_GUSTOS][GUSTOS_LENGTH] = {"Deporte", "Arte", "Informatica", "Religion", "Animales", "Videojuegos",
                                              "Fiesta", "Estudiar", "Viajes", "Politica"}; //Gustos disponibles
    User_list* users_list = NULL; //Lista de usuarios
    Friends* friends_list;
    Requests* requests_list;
    Publications* publications_list;
    Requests_stack requests_stack;
    User *us; //Variable para la creación de un usuario

    //Comprobamos que el archivo existe. Si existe, cargamos la lista de usuarios del archivo y mostramos el menú
    //Si no existe el archivo, cerramos el programa
    FILE *init = fopen("../resources/users.txt", "r");
    if (init == NULL) status = ERROR;
    FILE *fr = fopen("../resources/requests.txt", "r");
    if (fr == NULL) status = ERROR;
    FILE *ff = fopen("../resources/friends.txt", "r");
    if (ff == NULL) status = ERROR;
    FILE* fpub = fopen("../resources/publications.txt", "r");
    if (fpub == NULL) status = ERROR;
    if (status == SUCCESS) {
        //users
        loading_users(init, &users_list);
        fclose(init);
        //requests
        requests_list = init_requests_user();
        //requests_stack = init_stack();
        load_requests(requests_list, fr);
        fclose(fr);
        //friends
        friends_list = init_friends_user();
        load_friends(friends_list, ff);
        fclose(ff);
        //publicaciones
        /*publications_list = init_publications();
        load_publications(publications_list, fpub);*/
        fclose(fpub);
    } else {
        return -1;
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
        printf("%s\n", LINEA_ASTERISCOS);
        printf("\nElija una opcion:\n");
        scanf("%d", &option_menu);

        if (option_menu == 1) {
            us = create_user(gustos);

            //Añadimos el usuario en la lista
            if (users_list == NULL) {
                first_user_created(&users_list, us);
            } else {
                add_user_created(&users_list, us);
            }
            new_user_friends(friends_list, us->code);
            new_user_requests(requests_list, us->code);
        } else if (option_menu == 2) {
            print_users(users_list);
        } else if (option_menu == 3) {
            char login_user[MAX_ID_NAME_LENGHT];
            char login_pass[MAX_PASSWORD_LENGHT];
            User *login_us;
            printf("\n%s\n", LINEA_ASTERISCOS);
            printf("Introduzca el nombre de usuario:\n");
            scanf("%s", login_user);
            printf("Introduzca la contrasena:\n");
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
                    printf("2.- Conocer a usuarios desconocidos\n");
                    printf("3.- Gestionar solicitudes pendientes\n");
                    printf("4.- Listar amigos\n");
                    printf("5.- Realizar una publicacion\n");
                    printf("6.- Listar las publicaciones de un usuario\n");
                    printf("7.- Revisar timeline\n");
                    printf("0.- Cerrar sesion y volver al menu principal\n");
                    printf("Elija una opcion:\n");
                    scanf("%d", &option_usuario);

                    if (option_usuario == 1) {
                        char check_friend_name[MAX_ID_NAME_LENGHT];
                        Requests* requests_user;
                        User* user_requests;
                        printf("Introduzca el nombre de usuario al que quiera agregar como amigo:\n");
                        scanf("%s", check_friend_name);

                        user_requests = search_user_id_name(users_list, check_friend_name);

                        if (user_requests != NULL) {
                            if (user_requests != login_us) {
                                requests_user = search_user_requests(requests_list, user_requests->code);
                                if(requests_user != NULL){}
                                add_requests(requests_user, login_us->code);
                                printf("Solicitud enviada.\n");
                            }
                            else {
                                printf("No puedes enviarte una solicitud a ti mismo.\n");
                            }

                        } else {
                            printf("Ese usuario no existe.\n");
                        }
                    }
                    else if (option_usuario == 2) {
                        requests_stack = add_users_to_stack(users_list, requests_list, friends_list, login_us->code);
                    }
                    else if (option_usuario == 3) {
                        Requests* requests_loged_user = search_user_requests(requests_list, login_us->code);
                        if (requests_loged_user != NULL){
                            print_requests_graph(users_list, requests_loged_user);
                            manage_requests(users_list, requests_loged_user, friends_list);
                        }
                        else{
                            printf("El usuario no tiene inicializados los requests!!!\n");
                        }
                    }
                    else if (option_usuario == 4) {
                        Friends* friends_user = search_user_friends(friends_list, login_us->code);
                        if(friends_user != NULL){
                            print_friends_graph(users_list, friends_user);
                        }
                        else{
                            printf("El usuario no tiene inicializados los amigos!!!\n");
                        }
                    }
                    else if (option_usuario == 5) {
                        char text_publications[MAX_TEXT_LENGTH], text_title[MAX_TITLE_LENGTH];
                        printf("Escriba el titulo de la publicación: \n");
                        while (getchar() !='\n');
                        fgets(text_title, sizeof(text_title), stdin);
                        text_publications[strcspn(text_title, "\n")] = '\0'; // Eliminar salto de línea del final
                        printf("Escriba su publicación (120 MAX): \n");
                        while (getchar() !='\n');
                        fgets(text_publications, sizeof(text_publications), stdin);
                        text_publications[strcspn(text_publications, "\n")] = '\0'; // Eliminar salto de línea del final

                        if (strlen(text_title) <= MAX_TITLE_LENGTH && strlen(text_publications) <= MAX_TEXT_LENGTH) {
                            create_publication(publications_list, login_us->code, text_publications, text_title);
                            printf("Publicacion realizada\n");
                        } else {
                            printf("Tu publicacion excede 120 caracteres.\n");
                        }
                    }
                    else if (option_usuario == 6) {
                        char check_user_name[MAX_ID_NAME_LENGHT];
                        User *user;
                        printf("Introduzca el nombre de usuario al que quiera mirar sus publicaciones:\n");
                        scanf("%s", check_user_name);

                        user = search_user_id_name(users_list, check_user_name);
                        if (user != NULL) {
                            print_publications(publications_list, *user);
                        } else {
                            printf("Ese usuario no existe.\n");
                        }
                    } else if (option_usuario == 7) {
                        show_timeline(publications_list, friends_list, users_list, *login_us);
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
            //Comprobamos que el archivo existe. Si existe, guardamos todos los usuarios que hayamos agregado en el
            //archivo y salimos del programa
            //En caso de que el archivo no exista, saldrá un mensaje de error
            FILE *finish = fopen("../resources/users.txt", "w");
            if (finish == NULL) status = ERROR;
            FILE* requests_save = fopen("../resources/requests.txt", "w");
            if(requests_save == NULL) status = ERROR;
            FILE* friends_save = fopen("../resources/friends.txt", "w");
            if(friends_save == NULL) status = ERROR;
            FILE* fpub_save = fopen("../resources/publications.txt", "w");
            if(fpub_save == NULL) status = ERROR;
            if (status == SUCCESS) {
                //users
                save_all_users(users_list, finish);
                fclose(finish);
                //requests
                save_requests(requests_list, requests_save);
                fclose(requests_save);
                //friends
                save_friends(friends_list, friends_save);
                fclose(friends_save);
                //publications
                //save_publications(publications_list, fpub_save);
                fclose(fpub_save);
            } else {
                printf("¡¡No se han encontrado los archivos!! ¡¡Los usuarios agregados NO van a ser guardados y sus respectivas acciones tampoco!!\n");
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