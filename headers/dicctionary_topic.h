#ifndef UNTITLED4_DICCTIONARY_TOPIC_H
#define UNTITLED4_DICCTIONARY_TOPIC_H

#include "defines.h"
#include "user_list.h"
#include "publications_users.h"

typedef struct {
    char word[MAX_WORD_LENGHT];
    int num_words;
}Words;

typedef struct {
    int size;
    int count;
    Words* words;
} Dict;

Dict* initDict();
void load_dict (Dict* dict, Publications* publications);
void add_value(Dict* dict, char word[MAX_WORD_LENGHT]);
void modify_value(Dict* dict, char word[MAX_WORD_LENGHT]);
void realloc_dict(Dict* dict);
void manage_words_dict(Dict* dict, char text[MAX_WORD_LENGHT]);
int search_by_value(Dict* dict, char word[MAX_WORD_LENGHT]);
#endif //UNTITLED4_DICCTIONARY_TOPIC_H
