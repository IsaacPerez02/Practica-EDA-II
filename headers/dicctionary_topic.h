#ifndef UNTITLED4_DICCTIONARY_TOPIC_H
#define UNTITLED4_DICCTIONARY_TOPIC_H
#define MAX_WORD_LENGHT 20

typedef struct {
    char word[MAX_WORD_LENGHT];
    int iteration;
} DictionaryEntry;

int SearchDictionaryWord(DictionaryEntry * dict, int numEntrys, char* word);
void addNewWord(DictionaryEntry * dict, int* numEntry, char* word);
void NewNumber(DictionaryEntry * dict, int index);
#endif //UNTITLED4_DICCTIONARY_TOPIC_H
