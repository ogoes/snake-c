#ifndef SCREEN_H
#define SCREEN_H
#include <sys/ioctl.h>

/**
 ** global variable that contains terminal width and height information
 **/
struct winsize TERMINAL_WINDOW_SIZE;
int HAS_BEEN_INITIALIZATED = 0;



/**
 * show_terminal_size()
 ** show in line the number of columns and rows of the terminal
 * @param: specific_row -> specific row to print the information about the terminal size
 **/
void show_terminal_size (unsigned int);


#endif
