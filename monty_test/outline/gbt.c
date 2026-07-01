#include "monty.h"

int count_lines(FILE* file)
{
        // Count the number of lines in the file
    int linesCount = 0;
    int c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            linesCount++;
        }
    }
    if (c != '\n' && linesCount > 0) {
        linesCount++;
    }
    rewind(file);
    return (linesCount);
}

