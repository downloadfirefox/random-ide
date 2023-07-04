#include <stdlib.h>
#include <ncurses.h> // Do not need to include stdio.h as ncurses does that
#include "util.h"
#include <string.h>

/*
Printing using ncurses:
- printw() - equivalent to printf(), for variables
- addch() - prints a single char, equals putchar()
- addstr() - prints a specified string, equals puts(), strings only
*/

int main() {

    // Initialize ncurses
    initscr();
    // util.h: void clr()
    // Clears screen
    clr();
    addstr("Hello, world!\n");
    refresh(); // Refresh the screen to show the latest content

    // pause the screen output, wait for key input to continue
    getch();

    // deallocates memory and ends ncurses
    endwin();
    return EXIT_SUCCESS;
}