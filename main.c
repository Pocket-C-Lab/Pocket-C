#include <stdio.h>
#include "include/conio.h"

#define VERSION "0.0.1"

void log_warn(const char *str);

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
