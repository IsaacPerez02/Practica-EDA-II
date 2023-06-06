#include "../headers/friends_graph.h"

Friends* init_friends_user(User_list* list){
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

void print_friends_graph(Friends* friends){
    for (int i = 0; i < MAX_USERS; ++i) {
        if (friends[i].code_user != 0){
            printf("%d. ", friends[i].code_user);
            for (int j = 0; j < friends[i].num_friends; ++j) {
                printf("%d, ", friends[i].code_friends[j]);
            }
            printf("\n");
        }
    }
}
