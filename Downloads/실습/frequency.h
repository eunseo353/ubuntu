#ifndef FREQUENCY_H
#define FREQUENCY_H

#include <stdio.h>

#define MAX_WORD_LEN 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordFreq;

int frequency(FILE *file, WordFreq *word_array);
void print_frequencies(WordFreq *word_array, int size);

#endif
