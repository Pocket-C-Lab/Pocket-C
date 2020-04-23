#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// dependencies
#include "tiny-regex-c/re.h"
#include "conio/conio.h"

#define VERSION "0.1.0"

enum Options {P, o, r, t, U, g, u, E, s, e};
enum Features {test, verbose, help, quite};

// Options available globally
char OPTIONS[10], FEATURES[4];
FILE *file;
bool is_file_open = false;

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
    textcolor(BLACK);
    textbackground(YELLOW);
    printf(str);
    textcolor(WHITE);
    textbackground(BLACK);
}

void log_info(const char *str)
{
    textcolor(WHITE);
    textbackground(BLUE);
    printf(str);
    textcolor(WHITE);
    textbackground(BLACK);
}

void log_danger(const char *str)
{
    textcolor(WHITE);
    textbackground(RED);
    printf(str);
    textcolor(WHITE);
    textbackground(BLACK);
}

int main(int argc, char *argv[]) {
    printf("Pocket-C version : %s\n", VERSION);

    // Do this if arguments were provided.
    if (argc > 1) {
        // Checks if file exists or not.
        if ( access( argv[1], F_OK ) != -1 ) {
            log_info("\nusing "); printf("%s\n", argv[1]);
            file = fopen(argv[1], "r");
            if (file == NULL) {
                log_danger("Error opening the file : "); printf("%s\n", argv[1]);
                exit(EXIT_FAILURE);
            } else {
                is_file_open = true;
            }
        } else {
            printf("\n%s ", argv[1]); log_danger("does not exist or not readable\n");
            exit(EXIT_FAILURE);
        }

        // OPTIONS count block
        char options_count = 0;
        {
            char temp[11];
            for (int i = 2; i < argc; ++i)
            {
                strcpy(temp, argv[i]);
                if (temp[0] == '-' && temp[1] != '-') {
                    options_count++;
                } else if (temp[0] == '-' && temp[1] == '-') {
                    break;
                } else {
                    printf("Invalid option : %s\n", argv[i]);
                    exit(EXIT_FAILURE);
                }
            }
        }

        // FEATURES count block
        char features_count = 0;
        {
            char temp[11];
            for (int i = options_count+2; i < argc; ++i)
            {
                strcpy(temp, argv[i]);
                if (temp[0] == '-' && temp[1] == '-') {
                    features_count++;
                } else {
                    printf("Invalid feature : %s\n", argv[i]);
                    exit(EXIT_FAILURE);
                }
            }
        }


        // will contain the options provided through arguments
        // options start from 2nd argument
        char buffer[12];

        // Convert arguments to string buffer
        for (char i = 2; i < options_count+2; ++i)
        {
            int len = strlen(argv[i]);

            if (len > 11) {
                printf("%s exceeds the option's allowed length!\n", argv[i]);
                exit(EXIT_FAILURE);
            } else {
                // Enable OPTIONS
                strcpy(buffer, argv[i]);
                for (int i = 1; i < len; ++i)
                {
                    switch (buffer[i])
                    {
                    case 'P':
                        OPTIONS[P] = 1;
                        break;
                    case 'o':
                        OPTIONS[o] = 1;
                        break;
                    case 'r':
                        OPTIONS[r] = 1;
                        break;
                    case 't':
                        OPTIONS[t] = 1;
                        break;
                    case 'U':
                        OPTIONS[U] = 1;
                        break;
                    case 'g':
                        OPTIONS[g] = 1;
                        break;
                    case 'u':
                        OPTIONS[u] = 1;
                        break;
                    case 'E':
                        OPTIONS[E] = 1;
                        break;
                    case 's':
                        OPTIONS[s] = 1;
                        break;
                    case 'e':
                        OPTIONS[e] = 1;
                        break;

                    default:
                        printf("Not an Option %c, ", buffer[i]);
                    }
                } printf("\n");
            }
        }


        // Enable the features provided to the program.
        for (char i = options_count+2; i < argc; i++)
        {
            if (!strcmp(argv[i], "--test")) {
                FEATURES[test] = 1;
            } else if (!strcmp(argv[i], "--verbose")) {
                FEATURES[verbose] = 1;
            } else if (!strcmp(argv[i], "--help")) {
                FEATURES[help] = 1;
            } else if (!strcmp(argv[i], "--quite")) {
                FEATURES[quite] = 1;
            } else
                printf("%s not a feature! \n", argv[i]);
        }
        printf("\n");
    }

    // Do this if arguments weren't provided.
    else {
        log_info("\nYou didn't provide any arguments.\nFinding \"main.pc\" file\n");

        if ( access( "main.pc", F_OK ) != -1 ) {
            printf("\nusing \"main.pc\"\n");
            file = fopen("main.pc", "r");
            if (file == NULL) {
                printf("Error opening the file : %s\n", argv[1]);
                exit(EXIT_FAILURE);
            } else {
                is_file_open = true;
            }
        } else {
            log_danger("\nmain.pc does not exist or not readable\n");
            exit(EXIT_FAILURE);
        }

    }


    /**
     * From here the application logic starts
     *
    */
    char str[100], str2[100];
    fscanf(file, "%s %s", str, str2);
    printf("%s %s", str, str2);
    tokenizer(file);


    // closing the file
    fclose(file);

    // To be removed after the implementation of pack.c and unpack.c
    for (char i = 0; i < 10; i++)
    {
        printf("%d ", OPTIONS[i]);
    } printf(" ");
    for (char i = 0; i < 4; i++)
    {
        printf("%d ", FEATURES[i]);
    } printf("\n");

    getch();
    return 0;
}
