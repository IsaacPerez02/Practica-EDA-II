#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/dicctionary_topic.h"
int SearchDictionaryWord(DictionaryEntry * dict, int numEntry, char* word) {
    for (int i = 0; i < numEntry; i++) {
        if (strcmp(dict[i].word, word) == 0) {
            return i;  // Si la palabra se encunetra en el diccionario devuelve la iteracion
        }
    }
    return -1;  // Devuelve -1 si no encuentra la palabra en el diccionario
}

void addNewWord(DictionaryEntry * dict, int* numEntry, char* word) {
    strcpy(dict[*numEntry].word, word);
    dict[*numEntry].iteration = 0;
    (*numEntry)++;
}

void NewNumber(DictionaryEntry * dict, int index) {
    dict[index].iteration++;
}
