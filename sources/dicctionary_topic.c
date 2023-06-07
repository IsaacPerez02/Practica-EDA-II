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
        dict->words[i].num_words = 0;
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
    char delimiters[] = ",. ?=|!';:-_";
    char *word = strtok(text, delimiters);
    election = search_by_value(dict, word);
    if(election == TRUE){
        modify_value(dict, word);
    }
    else{
        add_value(dict, word);
    }
    while (word != NULL) {
        word = strtok(NULL, delimiters);
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

void order_selection_sort_dict(Dict* dict){
    int min, count_word_aux;
    char aux_word[MAX_WORD_LENGHT];
    for (int i = 0; i < MAX_NUM_WORDS - 1; ++i) {
        min = i;
        for (int j = i+1; j < MAX_NUM_WORDS; ++j) {
            if (dict->words[j].num_words < dict->words[min].num_words){
                min = j;
            }
        }
        count_word_aux = dict->words[i].num_words;
        strcpy(aux_word,dict->words[i].word);
        dict->words[i].num_words = dict->words[min].num_words;
        strcpy(dict->words[i].word,dict->words[min].word);
        dict->words[min].num_words = count_word_aux;
        strcpy(dict->words[min].word, aux_word);
    }
}

void print_words_10(Dict* dict){
    int count = 0;
    for (int i = dict->size - 1; i > -1; i--) {
        if(dict->words[i].num_words != 0 && count < 10){
            printf("%d. %s\n", dict->words[i].num_words ,dict->words[i].word);
            count++;
        }
    }
}