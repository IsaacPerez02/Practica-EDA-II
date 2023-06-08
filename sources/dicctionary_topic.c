#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/dicctionary_topic.h"

/**
 * Inicialización del diccionario
 * @return: devuelve el diccionario creado e inicializado en esta función
 */
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

/**
 * Carga el diccionario. Coge todas las palabras de la lista de publicaciones y se inserta en el diccionario
 * @param dict: diccionario de palabras
 * @param publications: lista de publicaciones de los usuarios
 */
void load_dict (Dict* dict, Publications* publications){
    char aux_text[MAX_TEXT_LENGTH];
    for (int i = 0; i < MAX_PUBLICATIONS; ++i) {
        if(publications[i].code_user != 0){
            strcpy(aux_text, publications[i].publication);
            manage_words_dict(dict, publications[i].publication);
            strcpy(publications[i].publication, aux_text);
        }
    }
}

/**
 * Aumenta el tamaño del diccionario en caso de que la cantidad de palabras la sobrepase
 * @param dict: diccionario de palabras
 */
void realloc_dict(Dict* dict){
    dict->words = realloc(dict, sizeof (Dict) * MAX_NUM_WORDS);
    dict->size = dict->size + dict->size;
}

/**
 * Añade una palabra nueva al diccionario
 * @param dict: diccionario de palabras
 * @param word: palabra a añadir al diccionario
 */
void add_value(Dict* dict, char word[MAX_WORD_LENGHT]){
    //Miramos que el tamaño del diccionario no se sobrepase
    if(dict->count < dict->size){
        strcpy(dict->words[dict->count].word, word);
        dict->words[dict->count].num_words = 1;
    }
    else{ //Si es así, aumentamos el tamaño
        realloc_dict(dict);
        strcpy(dict->words[dict->count].word, word);
        dict->words[dict->count].num_words = 1;
    }
    dict->count++;
}

/**
 * Aumenta +1 la cantidad de veces que aparece una palabra ya introducida en el diccionario
 * @param dict: diccionario de palabras
 * @param word: palabra a añadir
 */
void modify_value(Dict* dict, char word[MAX_WORD_LENGHT]){
    for (int i = 0; i < MAX_NUM_WORDS; ++i) {
        if (strcmp(word, dict->words[i].word) == 0){
            dict->words[i].num_words++;
        }
    }
}

/**
 * Gestión de palabras. Coge el texto y comprueba si ya está en el diccionario o no
 * @param dict: diccionario de palabras
 * @param text: texto a comprobar
 */
void manage_words_dict(Dict* dict, char text[MAX_WORD_LENGHT]){
    int election;
    char delimiters[] = ",. ?=|!';:-_";
    char *word = strtok(text, delimiters); //Divide la palabra si contiene alguno de los caracteres definidos
    //Comprobamos si la palabra está repetida o no en el diccionario
    election = search_by_value(dict, word);
    if(election == TRUE){
        modify_value(dict, word);
    }
    else{
        add_value(dict, word);
    }
    //Ahora comprobamos todas las palabras
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

/**
 * Comprueba si la palabra a introducir ya se encuentra en el diccionario o no
 * @param dict: diccionario de palabras
 * @param word: palabra a añadir
 * @return: TRUE si la palabra ya se encuentra en el diccionario; FALSE si no está
 */
int search_by_value(Dict* dict, char word[MAX_WORD_LENGHT]){
    for (int i = 0; i < MAX_NUM_WORDS; ++i) {
        if (strcmp(word, dict->words[i].word) == 0){
            return TRUE;
        }
    }
    return FALSE;
}

/**
 * Ordena el diccionario de mayor cantidad de veces que aparece a menor. Se usa el algoritmo de ordenación selection_sort
 * @param dict: diccionario de palabras
 */
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

/**
 * Imprime las 10 palabras más repetidas del diccionario
 * @param dict: diccionario de palabras
 */
void print_words_10(Dict* dict){
    int count = 0;
    for (int i = dict->size - 1; i > -1; i--) {
        if(dict->words[i].num_words != 0 && count < 10){
            printf("%d. La palabra %s se utiliza %d veces\n", count + 1,dict->words[i].word, dict->words[i].num_words);
            count++;
        }
    }
    printf("\n%s%s\n\n", LINEA_ASTERISCOS, LINEA_ASTERISCOS);
}

/**
 * Libera de la memoria el diccionario de palabras al finalizar el programa
 * @param dict
 */
void free_dict(Dict* dict) {
    free(dict->words);
    free(dict);
}