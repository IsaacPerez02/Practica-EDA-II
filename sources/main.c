#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../headers/user.h"
#include "../headers/user_list.h"
#include "../headers/publications_users.h"
#include "../headers/requests_queue.h"
#include "../headers/requests_stack.h"
#include "../headers/dicctionary_topic.h"

int main() {
    printf("\n\n\t\t\tWork with friends\n\n");
    //Declaración de variables
    int option_menu = -1; //Opción del menú principal que el usuario escribirá por consola
    int option_usuario; //Opción de menú de operar como otro usuario
    int status = SUCCESS; //Variable para comprobar si el archivo de usuarios existe
    char gustos[MAX_GUSTOS][GUSTOS_LENGTH] = {"Deporte", "Arte", "Informatica", "Religion", "Animales", "Videojuegos",
                                              "Fiesta", "Estudiar", "Viajes", "Politica"}; //Gustos disponibles
    User_list* users_list = NULL; //Lista de usuarios
    Friends* friends_list; //Lista de amigos de los usuarios
    Requests* requests_list; //Lista de solicitudes de los usuarios
    Publications* publications_list; //Lista de publicaciones de los usuarios
    Dict* dict; //Diccionario que contiene todas las palabras distintas de todas las publicaciones y la cantidad de veces que aparecen
    User *us; //Variable para la creación de un usuario
    clock_t start, end; //Variables para medir el tiempo de ejecución
    double clock_time = 0.0;

    //Comprobación de que existan los archivos
    FILE *init = fopen("../resources/users.txt", "r");
    if (init == NULL) status = ERROR;
    FILE *fr = fopen("../resources/requests.txt", "r");
    if (fr == NULL) status = ERROR;
    FILE *ff = fopen("../resources/friends.txt", "r");
    if (ff == NULL) status = ERROR;
    FILE* fpub = fopen("../resources/publications.txt", "r");
    if (fpub == NULL) status = ERROR;
    if (status == SUCCESS) {
        //Cargamos la lista de usuarios mediante el archivo de usuarios
        start = clock();
        loading_users(init, &users_list);
        fclose(init);
        //Cargamos la lista de solicitudes mediante el archivo de solicitudes
        requests_list = init_requests_user();
        load_requests(requests_list, fr);
        fclose(fr);
        //Cargamos la lista de amigos mediante el archivo de amigos
        friends_list = init_friends_user();
        load_friends(friends_list, ff);
        fclose(ff);
        //Cargamos la lista de publicaciones mediante el archivo de publicaciones
        publications_list = init_publications();
        load_publications(publications_list, fpub);
        //Inicializamos el diccionario y cogemos todas las palabras de todas las publicaciones del sistema
        dict = initDict();
        load_dict(dict, publications_list);
        fclose(fpub);
        end = clock();
        clock_time = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Tiempo de ejecucion de la carga de datos de los archivos: %f segundos.\n", clock_time);
    } else {
        return -1;
    }
    //Menú de gestión del administrador. Opciones:
    //1: Crea un nuevo usuario y lo añade a la lista
    //2: Lista la información de todos los usuarios de la lista
    //3: Iniciamos sesión con un usuario. Para ello, necesitamos el nombre de usuario y su contraseña
    while (option_menu != 0) {
        printf("\n%s%s\n\n", LINEA_ASTERISCOS, LINEA_ASTERISCOS);
        printf("1.- Crear nuevo usuario\n");
        printf("2.- Listar todos los usuarios\n");
        printf("3.- Operar como otro usuario\n");
        printf("4.- Mostrar 10 palabras mas usadas\n");
        printf("5.- Imprimir la lista adyacente de requests por pantalla\n");
        printf("6.- Imprimir la lista adyacente de amigos por pantalla\n");
        printf("0.- Salir del programa\n");
        printf("\n%s%s\n\n", LINEA_ASTERISCOS, LINEA_ASTERISCOS);
        printf("\nElija una opcion:\n");
        scanf("%d", &option_menu);

        if (option_menu == 1) { //Crear nuevo usuario
            us = create_user(gustos);

            //Añadimos el usuario en la lista
            if (users_list == NULL) {
                //Si la lista está vacía
                first_user_created(&users_list, us);
            } else {
                //Si la lista no está vacía
                add_user_created(&users_list, us);
            }
            //Añadimos el código del usuario a la lista global de solicitudes y amigos
            new_user_friends(friends_list, us->code);
            new_user_requests(requests_list, us->code);
        } else if (option_menu == 2) { //Listar todos los usuarios
            print_users(users_list);
        } else if (option_menu == 3) { //Operar como otro usuario
            char login_user[MAX_ID_NAME_LENGHT]; //Nombre de usuario a introducir
            char login_pass[MAX_PASSWORD_LENGHT]; //Contraseña a introducir
            User *login_us; //Usuario logeado
            printf("\n%s%s\n\n", LINEA_ASTERISCOS, LINEA_ASTERISCOS);
            printf("Introduzca el nombre de usuario:\n");
            scanf("%s", login_user);
            printf("Introduzca la contrasena:\n");
            scanf("%s", login_pass);
            printf("\n%s%s\n\n", LINEA_ASTERISCOS, LINEA_ASTERISCOS);
            //Comprobamos si el nombre de usuario introducido se encuentra en la lista de usuarios
            login_us = check_user_password(users_list, login_user, login_pass);

            //Si el usuario se encuentra en la lista, abrimos el menú de gestión del usuario
            if (login_us != NULL) {
                start = clock();
                printf("Bienvenido, %s.\n", login_us->id_name);
                option_usuario = -1;
                //Menú de gestión del usuario. Opciones:
                //1: Envia una solicitud de amistad a un usuario que hemos introducido por consola
                //2: Muestra la lista de solicitudes de amistad del usuario. El usuario podrá aceptar o rechazar la solicitud
                //3: Escribe un mensaje por consola y lo añade al timeline
                //4: Muestra todas las publicaciones de un usuario específico
                //5: Muestra todas las publicaciones de todos tus amigos
                while (option_usuario != 0) {
                    printf("\n%s%s\n\n", LINEA_ASTERISCOS, LINEA_ASTERISCOS);
                    printf("1.- Enviar solicitud de amistad\n");
                    printf("2.- Conocer a usuarios desconocidos\n");
                    printf("3.- Gestionar solicitudes pendientes\n");
                    printf("4.- Listar amigos\n");
                    printf("5.- Realizar una publicacion\n");
                    printf("6.- Listar las publicaciones de un usuario\n");
                    printf("7.- Revisar timeline\n");
                    printf("0.- Cerrar sesion y volver al menu principal\n");
                    printf("\n%s%s\n\n", LINEA_ASTERISCOS, LINEA_ASTERISCOS);
                    printf("Elija una opcion:\n");
                    scanf("%d", &option_usuario);

                    if (option_usuario == 1) { //Enviar solicitud de amistad
                        char check_friend_name[MAX_ID_NAME_LENGHT];
                        Requests* requests_user; //Lista de solicitudes del usuario al que queremos enviar solicitud
                        User* user_requests; //Usuario al que queremos mandar la solicitud
                        printf("Introduzca el nombre de usuario al que quiera agregar como amigo:\n");
                        scanf("%s", check_friend_name);

                        //Cogemos la lista de solicitudes del usuario introducido
                        user_requests = search_user_id_name(users_list, check_friend_name);

                        //Comprobamos que la lista de solicitudes exista
                        if (user_requests != NULL) {
                            if (user_requests != login_us) {
                                //Coge la lista de solicitudes del usuario al que mandamos solicitud y le agregamos nuestro código
                                requests_user = search_user_requests(requests_list, user_requests->code);
                                add_requests(requests_user, login_us->code);
                            }
                            else {
                                printf("No puedes enviarte una solicitud a ti mismo.\n");
                            }

                        } else {
                            printf("Ese usuario no existe.\n");
                        }
                    }
                    else if (option_usuario == 2) { //Conocer a usuarios desconocidos
                        Requests_stack requests_stack; //Stack de solicitudes
                        //Cogemos la lista de solicitudes y amigos del usuario logeado
                        Requests* requests_user = search_user_requests(requests_list, login_us->code);
                        Friends* friends_user = search_user_friends(friends_list, login_us->code);
                        //Insertamos a 3 usuarios del sistema al azar y decidimos si querer enviarles solicitud o no
                        requests_stack = add_users_to_stack(users_list, requests_user, friends_user, login_us->code);
                        manage_stack(users_list, requests_list, requests_stack, login_us->code, publications_list);
                    }
                    else if (option_usuario == 3) { //Gestionar solicitudes pendientes
                        //Coge nuestra lista de solicitudes
                        Requests* requests_loged_user = search_user_requests(requests_list, login_us->code);
                        //Comprobamos que tengamos solicitudes
                        if (requests_loged_user != NULL){
                            //Muestra por consola nuestras solicitudes pendientes y las gestionamos
                            print_requests_graph(users_list, requests_loged_user);
                            manage_requests(users_list, requests_loged_user, friends_list);
                        }
                        else{
                            printf("El usuario no tiene inicializados los requests!!!\n");
                        }
                    }
                    else if (option_usuario == 4) { //Listar amigos
                        //Coge nuestra lista de amigos
                        Friends* friends_user = search_user_friends(friends_list, login_us->code);
                        //Comprobamos que tengamos amigos
                        if(friends_user != NULL){
                            //Lista a todos nuestros amigos
                            print_friends_graph(users_list, friends_user);
                        }
                        else {
                            printf("El usuario no tiene inicializados los amigos!!!\n");
                        }
                    }
                    else if (option_usuario == 5) { //Realizar una publicación
                        char text_publications[MAX_TEXT_LENGTH]; //Texto a introducir
                        printf("Escriba su publicación (120 MAX): \n");
                        while (getchar() !=
                        '\n');
                        //Coge el texto introducido y le quita el salto de línea
                        fgets(text_publications, sizeof(text_publications), stdin);
                        text_publications[strcspn(text_publications, "\n")] = '\0'; // Eliminar salto de línea del final

                        //Comprobamos que el texto introducido no contenga más de MAX_TEXT_LENGTH
                        if (strlen(text_publications) <= MAX_TEXT_LENGTH) {
                            //Añadimos la publicación en la lista de publicaciones del usuario logeado y gestionamos
                            //cada palabra de la publicación por el diccionario
                            create_publication(publications_list, login_us->code, text_publications);
                            manage_words_dict(dict, text_publications);
                            printf("Publicacion realizada\n");
                        } else {
                            printf("Tu publicacion excede %d caracteres.\n", MAX_TEXT_LENGTH);
                        }
                    }
                    else if (option_usuario == 6) { //Listar las publicaciones de un usuario
                        //Introducimos al usuario que queramos listar sus publicaciones
                        char check_user_name[MAX_ID_NAME_LENGHT];
                        User *user;
                        printf("Introduzca el nombre de usuario al que quiera mirar sus publicaciones:\n");
                        scanf("%s", check_user_name);

                        //Buscamos al usuario por su nombre
                        user = search_user_id_name(users_list, check_user_name);
                        //Si existe el usuario en el sistema, mostramos por consola sus publicaciones
                        if (user != NULL) {
                            print_publications(publications_list, *user);
                        } else {
                            printf("Ese usuario no existe.\n");
                        }
                    } else if (option_usuario == 7) { //Revisar timeline: Muestra las publicaciones de todos los amigos
                        clock_t start2, end2;
                        start2 = clock();
                        show_timeline(publications_list, friends_list, users_list, *login_us);
                        end2 = clock();
                        clock_time = ((double) (end2 - start2)) / CLOCKS_PER_SEC;
                        printf("Tiempo de ejecucion para mostrar el timeline: %f segundos.\n", clock_time);
                    } else if (option_usuario == 0) {
                        printf("Cerrando sesion...\n");
                    } else {
                        printf("Tiene que elegir una opcion correcta.\n");
                    }
                }
            } else {
                printf("El nombre de usuario no existe o la contrasena no es correcta.\n");
            }
            end = clock();
            clock_time = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("Tiempo de ejecucion durante la sesion de %s: %f segundos.\n", login_us->id_name, clock_time);
        }
        else if (option_menu == 4) { //Mostrar 10 palabras más usadas
            start = clock();
            order_selection_sort_dict(dict); //Ordenamos el diccionario de manera descendente
            end = clock();
            clock_time = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("Tiempo de ejecucion para ordenar el diccionario: %f segundos.\n", clock_time);
            print_words_10(dict); //Mostramos por consola las 10 palabras más usadas
        }
        else if (option_menu == 5){ //Imprimir la lista adyacente de requests por pantalla
            //Por cada usuario, imprimimos todas sus solicitudes pendientes
            for (int i = 0; i < MAX_FRIENDS; ++i) {
                if(requests_list[i].code_user != 0){
                    User* user_graph_friends = search_user_code(users_list, requests_list[i].code_user);
                    printf("Los amigos de %s son: \n", user_graph_friends->id_name);
                    print_requests_graph(users_list, &requests_list[i]);
                }
            }
        }
        else if (option_menu == 6){ //Imprimir la lista adyacente de amigos por pantalla
            //Por cada usuario, imprimimos todos sus amigos
            for (int i = 0; i < MAX_FRIENDS; ++i) {
                if(friends_list[i].code_user != 0){
                    User* user_graph_friends = search_user_code(users_list, friends_list[i].code_user);
                    printf("Los amigos de %s son: \n", user_graph_friends->id_name);
                    print_friends_graph(users_list, friends_list);
                }
            }
        }
        else if (option_menu == 0) { //Salir del programa
            start = clock();
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
                //Guardamos la lista de usuarios del sistema al archivo de usuarios
                save_all_users(users_list, finish);
                fclose(finish);
                //Guardamos la lista de solicitudes del sistema al archivo de solicitudes
                save_requests(requests_list, requests_save);
                fclose(requests_save);
                //Guardamos la lista de amigos del sistema al archivo de amigos
                save_friends(friends_list, friends_save);
                fclose(friends_save);
                //Guardamos la lista de publicaciones del sistema al archivo de publicaciones
                save_publications(publications_list, fpub_save);
                fclose(fpub_save);
                free_dict(dict); //Liberamos de la memoria el diccionario
            } else {
                printf("¡¡No se han encontrado los archivos!! ¡¡Los usuarios agregados NO van a ser guardados y sus respectivas acciones tampoco!!\n");
            }
            printf("\n%s%s\n", LINEA_ASTERISCOS, LINEA_ASTERISCOS);
            printf("\t\t\tSaliendo del programa...\n");
            printf("\n%s%s\n", LINEA_ASTERISCOS, LINEA_ASTERISCOS);
            end = clock();
            clock_time = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("Tiempo de ejecucion para guardar los datos de los archivos: %f segundos.\n", clock_time);
            return 1;
        } else {
            printf("Tiene que elegir una opcion correcta.\n");
        }
    }
    return 0;
}