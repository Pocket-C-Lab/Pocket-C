#include "scanner.h"


TOKENS tokenizer(FILE *file)
{
    // First take a source file and read it line by line
    // Then tokenize every line and store tokens and token positions in TOKENS
    // Create a file .tokens and open it in binary mode. Store the TOKENS in that file.
    char linebuffer[500];
    while (!feof(myFile)) {
        const char *line = readLine(myFile, linebuffer);
        printf("%s\n", line);
    }

}



const char *readLine(FILE *file, char* line) {

    if (file == NULL) {
        printf("Error: file pointer is null.");
        exit(1);
    }

    int maximumLineLength = 128;
    char *lineBuffer = (char *)malloc(sizeof(char) * maximumLineLength);

    if (lineBuffer == NULL) {
        printf("Error allocating memory for line buffer.");
        exit(1);
    }

    char ch = getc(file);


    for (int count = 0; (ch != '\n') && (ch != EOF); count++) {
        ch = getc(file);
        if (count == maximumLineLength) {
            maximumLineLength += 128;
            lineBuffer = realloc(lineBuffer, maximumLineLength);
            if (lineBuffer == NULL) {
                printf("Error reallocating space for line buffer.");
                exit(1);
            }
        }
        lineBuffer[count] = ch;
    }

    lineBuffer[count] = '\0';
    char line[count + 1];
    strncpy(line, lineBuffer, (count + 1));
    free(lineBuffer);
    return line;
}
