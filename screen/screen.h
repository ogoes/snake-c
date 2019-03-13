#ifndef SCREEN_H
#define SCREEN_H
#include <sys/ioctl.h>

/**
 ** global variable that contains terminal width and height information
 **/
struct winsize TERMINAL_WINDOW_SIZE;



/**
 ** show in line the number of columns and rows of the terminal
 **/
void show_terminal_size ();


#endif
