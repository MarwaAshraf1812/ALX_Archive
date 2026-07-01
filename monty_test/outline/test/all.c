#include "all.h"

int count_lines(FILE* file)
{
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

char **tokenize_line(char *line, int *numwords)
{
    int len = strlen(line);
    if (len > 0 && line[len - 1] == '\n') {
        line[len - 1] = '\0';
    }
    char** words = (char**)malloc(MAX_WORDS_PER_LINE * sizeof(char*));
    int wordCount = 0;
    char* token = strtok(line, " ");
    while (token != NULL) {
        words[wordCount] = strdup(token);
        wordCount++;
        token = strtok(NULL, " ");
    }
    *numwords = wordCount;
    return (words);
}

void tokenize_file(const char* filepath) {
    FILE* file = fopen(filepath, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    int numwords = 0;
    linesCount = count_lines(file);
    lines = (char***)malloc(linesCount * sizeof(char**));
    wordsCount = (int*)malloc(linesCount * sizeof(int));
    int lineIndex = 0;
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        char **words = tokenize_line(buffer, &numwords);
        lines[lineIndex] = words;
        wordsCount[lineIndex] = numwords;
        lineIndex++;
    }
    fclose(file);
}


int main() {
    const char* filepath = "example.txt";
    tokenize_file(filepath);

    // Accessing elements
    int i;
    for ( i = 0; i < linesCount - 1; i++) {
        for (int j = 0; j < 2; j++) {
            printf("lines[%d][%d]: %s\n", i, j, lines[i][j]);
            free(lines[i][j]);
            printf("main: word freed\n");
        }
        printf("main: line freed\n");
        free(lines[i]);
    }
    free(lines[i]);
    printf("main: all freed, freeing lines.\n");
    free(lines);

    return 0;
}
