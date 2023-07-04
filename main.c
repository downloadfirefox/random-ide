#include <stdlib.h>
#include <ncurses.h>
#include "util.h"
#include <string.h>

int main() {

    // Initialize ncurses
    initscr();
    // util.h: void clr()
    // Clears screen
    clr();
    printw("Hello, world!\n");
    refresh();

    // pause the screen output
    getch();

    // deallocates memory and ends ncurses
    endwin();
    return EXIT_SUCCESS;
}