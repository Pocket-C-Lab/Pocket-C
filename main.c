#include <stdio.h>
#include <regex.h>
#include "include/conio.h"

#define VERSION "0.0.1"

// https://www.educative.io/edpresso/how-to-write-regular-expressions-in-c
// http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf
// https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/
// https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm
// https://stackoverflow.com/questions/10325565/tokenize-a-source-code
// https://www.geeksforgeeks.org/c-program-detect-tokens-c-program/

void log_warn(const char *str);
void log_info(const char *str);
void log_danger(const char *str);

void log_warn(const char *str)
{
    printf("\n");
    textcolor(BLACK);
    textbackground(YELLOW);
    printf(str);
    textcolor(WHITE);
    textbackground(BLACK);
    printf("\n");
}

void log_info(const char *str)
{
    printf("\n");
    textcolor(WHITE);
    textbackground(BLUE);
    printf(str);
    textcolor(WHITE);
    textbackground(BLACK);
    printf("\n");
}

void log_danger(const char *str)
{
    printf("\n");
    textcolor(WHITE);
    textbackground(RED);
    printf(str);
    textcolor(WHITE);
    textbackground(BLACK);
    printf("\n");
}

int main() {
    printf("Pocket-C version : %s", VERSION);

    log_warn("Test Warn");
    log_info("Test Info");
    log_danger("Test Danger");

    getch();
    return 0;
}
