#include "../headers/user.h"
#include <stdio.h>
#define MAX_USERS 2 //

//inicializamos el usuario nuevo
void init_user (){

}

//ordenamos todos los usuarios
void ord_user(FILE * fa){
    int success, i = 0;
    User users[MAX_USERS];
    printf("1");
    success = fscanf(fa, "%s·%s·%s·%d·%s·%s·%s/%s/%s/%s/%s", &users[i].id_name, &users[i].nombre, &users[i].contrasena, &users[i].edad, &users[i].correo, &users[i].ubicacion, &users[i].gustos[0], &users[i].gustos[1], &users[i].gustos[2], &users[i].gustos[3], &users[i].gustos[4]);
    printf("1");
    while (success > 10){
        i++;
        success = fscanf(fa, "%s·%s·%s·%d·%s·%s·%s/%s/%s/%s/%s", &users[i].id_name, &users[i].nombre, &users[i].contrasena, &users[i].edad, &users[i].correo, &users[i].ubicacion, &users[i].gustos[0], &users[i].gustos[1], &users[i].gustos[2], &users[i].gustos[3], &users[i].gustos[4]);
    }
    for (int j = 0; j < MAX_USERS; j++){
        printf("%d\n", users[j].edad);
    }
}