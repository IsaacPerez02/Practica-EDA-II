#ifndef UNTITLED4_DICCTIONARY_TOPIC_H
#define UNTITLED4_DICCTIONARY_TOPIC_H

#include "defines.h"
#include "user_list.h"
#include "publications_users.h"

/**
 * Palabra en una publicación
 * word: palabra que guardamos
 * num_words: número de veces que aparece la palabra
 */
typedef struct {
    char word[MAX_WORD_LENGHT];
    int num_words;
}Words;

/**
 * Diccionario donde guardaremos las diferentes palabras de todas las publicaciones del sistema y la cantidad de
 * veces que aparecen
 * size: tamaño del diccionario
 * count: número de palabras que contiene el diccionario
 * words: lista de palabras
 */
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
int len_word(char word[MAX_WORD_LENGHT]);
void order_selection_sort_dict(Dict* dict);
void print_words_10(Dict* dict);
void free_dict(Dict* dict);
#endif //UNTITLED4_DICCTIONARY_TOPIC_H
