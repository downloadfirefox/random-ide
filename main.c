#include <stdlib.h>
#include <ncurses.h> // Do not need to include stdio.h as ncurses does that
#include "util.h"
#include <string.h>

// READ if you do not know ncurses: https://medium.com/programming-in-c/an-introduction-to-ncurses-in-c-d977efd706f8


/*
Printing using ncurses:
- printw() - equivalent to printf(), for variables
- addch() - prints a single char, equals putchar()
- addstr() - prints a specified string, equals puts(), strings only
*/

int main() {
    initscr();
    helloworld();
    colours();
    endwin();
    return EXIT_SUCCESS;
}

int helloworld() {

    // Initialize ncurses
    // util.h: void clr()
    // Clears screen
    clr();
    addstr("Hello, world!\n");
    refresh(); // Refresh the screen to show the latest content
    addstr("Press any key to exit.");
    // pause the screen output, wait for key input to continue
    getch();

    // deallocates memory and ends ncurses
    return EXIT_SUCCESS;
}

/*
This is a full list of ncurses colour constants:

COLOR_BLACK
COLOR_RED
COLOR_GREEN
COLOR_YELLOW
COLOR_BLUE
COLOR_MAGENTA
COLOR_CYAN
COLOR_WHITE
*/
int colours() {
    clr();
    if (has_colors()) { // Check if the terminal can output colours
        if(start_color() == OK) { // Start color and see if it is ok

        }
    }
    return EXIT_SUCCESS;
}