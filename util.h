#ifndef _STDIO_H
#include <stdio.h>
#endif
#ifndef _STDLIB_H
#include <stdlib.h>
#endif

void clr() { // Clears the screen
    system("clear");
}

int xmaxsize() {
    int x,y;
    getmaxyx(stdscr,y,x);
    return x;
}
int ymaxsize() {
    int x,y;
    getmaxyx(stdscr,y,x);
    return y;
}