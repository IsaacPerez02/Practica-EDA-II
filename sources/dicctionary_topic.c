#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/dicctionary_topic.h"

Dict* initDict(){
    Dict* dict = (Dict*) malloc(sizeof (Dict));
    dict->count = 0;
    dict->size = MAX_NUM_WORDS;
    dict->words = (Words*) malloc(sizeof (Words) * MAX_NUM_WORDS);
    for (int i = 0; i < MAX_NUM_WORDS; ++i) {
        strcpy(dict->words[i].word, " ");
    }
    return dict;
}

void load_dict (Dict* dict, Publications* publications){
    for (int i = 0; i < MAX_PUBLICATIONS; ++i) {
        if(publications[i].code_user != 0){
            manage_words_dict(dict, publications[i].publication);
        }
    }
}

void realloc_dict(Dict* dict){
    dict->words = realloc(dict, sizeof (Dict) * MAX_NUM_WORDS);
    dict->size = dict->size + dict->size;
}

void add_value(Dict* dict, char word[MAX_WORD_LENGHT]){
    if(dict->count < dict->size){
        strcpy(dict->words[dict->count].word, word);
        dict->words[dict->count].num_words = 1;
    }
    else{
        realloc_dict(dict);
        strcpy(dict->words[dict->count].word, word);
        dict->words[dict->count].num_words = 1;
    }
    dict->count++;
}

void modify_value(Dict* dict, char word[MAX_WORD_LENGHT]){
    for (int i = 0; i < MAX_NUM_WORDS; ++i) {
        if (strcmp(word, dict->words[i].word) == 0){
            dict->words[i].num_words++;
        }
    }
}

void manage_words_dict(Dict* dict, char text[MAX_WORD_LENGHT]){
    int election;
    char *word = strtok(text, " ");
    add_value(dict, word);
    election = search_by_value(dict, word);
    if(election == TRUE){
        modify_value(dict, word);
    }
    else{
        add_value(dict, word);
    }
    while (word != NULL) {
        word = strtok(NULL, " ");
        if(word != NULL){
            election = search_by_value(dict, word);
            if(election == TRUE){
                modify_value(dict, word);
            }
            else{
                add_value(dict, word);
            }
        }
    }
}

int search_by_value(Dict* dict, char word[MAX_WORD_LENGHT]){
    for (int i = 0; i < MAX_NUM_WORDS; ++i) {
        if (strcmp(word, dict->words[i].word) == 0){
            return TRUE;
        }
    }
    return FALSE;
}