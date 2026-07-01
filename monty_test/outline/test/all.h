#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS_PER_LINE 100  // Adjust this value as needed

char*** lines;  // Declare the global variable for the 3D array
int linesCount;
int* wordsCount;

void tokenizeFile(const char* filepath);
