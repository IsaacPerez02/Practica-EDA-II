#include "../headers/friends_graph.h"

Friends* init_friends_user(){
    Friends* friends = (Friends*) malloc(MAX_USERS * sizeof (Friends));
    for (int i = 0; i < MAX_USERS; ++i) {
        friends[i].code_user = 0;
        friends[i].num_friends = 0;
        for (int j = 0; j < MAX_FRIENDS; ++j) {
            friends[i].code_friends[j] = 0;
        }
    }
    return friends;
}

void load_friends(Friends* friends, FILE* ff){
    int code, code_friend, num_friends, i = 0;
    while(fscanf(ff, "%d. %d,", &code, &num_friends) > 1){
        friends[i].code_user = code;
        friends[i].num_friends = num_friends;
        for (int j = 0; j < num_friends; ++j) {
            fscanf(ff, "%d,", &code_friend);
            friends[i].code_friends[j] = code_friend;
        }
        i++;
    }
}

void add_friend(Friends* friends, int new_friend){
    friends->code_friends[friends->num_friends] = new_friend;
    friends->num_friends++;
}

void delete_friend(Friends* friends, int delete_friend){
    int new_list[MAX_FRIENDS];
    for (int i = 0; i < MAX_FRIENDS; ++i) {
        new_list[i] = 0;
    }
    int j = 0;
    for (int i = 0; i < MAX_FRIENDS; ++i) {
        if(delete_friend != friends->code_friends[i]){
            new_list[j] = friends->code_friends[i];
            j++;
        }
    }
    for (int i = 0; i < MAX_FRIENDS; ++i) {
        friends->code_friends[i] = new_list[i];
    }
    friends->num_friends--;
}

Friends* search_user_friends(Friends* friends, int code_user){
    for (int i = 0; i < MAX_FRIENDS; ++i) {
        if(friends[i].code_user == code_user){
            return &friends[i];
        }
    }
    return NULL;
}

void save_friends(Friends* friends, FILE* ff){
    for (int i = 0; i < MAX_USERS; ++i) {
        if(friends[i].code_user != 0){
            fprintf(ff, "%d. %d, ", friends[i].code_user, friends[i].num_friends);
            for (int j = 0; j < friends[i].num_friends; ++j) {
                fprintf(ff, "%d, ", friends[i].code_friends[j]);
            }
        }
    }
}

void print_friends_graph(Friends* friends){
    printf("%d. ", friends->code_user);
    for (int j = 0; j < friends->num_friends; ++j) {
        printf("%d, ", friends->code_friends[j]);
    }
    printf("\n");
}
