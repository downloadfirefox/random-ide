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
    noecho();
    cbreak();
    clr();
    if (has_colors()) { // Check if the terminal can output colours
        if(start_color() == OK) { // Start color and see if it is ok
            init_pair(1, COLOR_BLACK, COLOR_WHITE); // Make a pair with an id of 1, text color of black and background of white
            // TODO: get things inside window, titlebar
            int xmax = xmaxsize(); // util.h: find width of screen
            int ymax = ymaxsize();
            WINDOW *titlebar = newwin(1, xmax, 0,0); // Create a window titlebar that is FULLSCREEN
            refresh();

            // Titlebar
            mvwhline(titlebar,0,0,' ',xmax);
            wprintw(titlebar,"Random Terminal IDE\n\n");
            mvwchgat(titlebar,0,0,-1,A_REVERSE,0,0);

            wrefresh(titlebar); // Refresh window

            /*
            attrset(COLOR_PAIR(1) | A_BOLD); // Set current pair to pair 1
            wprintw(titlebar,"Random Terminal IDE\n\n"); // print text
            refresh(); // refresh so that buffer gets onto screen
            attroff(COLOR_PAIR(1)); // discard so that other text looks normal
            attroff(A_BOLD); // discard so that other text looks normal
            */

            WINDOW *textEditor = newwin(ymax-1, xmax, 1,0); // Create a window titlebar that is FULLSCREEN
            wprintw(textEditor,"\nPress any key to exit.\n");
            wrefresh(textEditor);
            refresh();
            getch();
        }
    }

    return EXIT_SUCCESS;
}


int main() {
    initscr();
    use_default_colors(); // use the terminal's default colours to look natural
    //helloworld();
    colours();
    endwin();
    return EXIT_SUCCESS;
}