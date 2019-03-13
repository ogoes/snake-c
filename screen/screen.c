#include <stdio.h>
#include "screen.h"


/**
 ** show in line the number of columns and rows of the terminal
 **/
void show_terminal_size () {
  
  /**
   *! TERMINAL_WINDOW_SIZE hasn't been initialized error
   **/
  // if (!TERMINAL_WINDOW_SIZE) {
  //   perror("TERMINAL_WINDOW_SIZE hasn't been initialized, call the initialize() function");
  //   return;
  // }

  unsigned int columns_size = TERMINAL_WINDOW_SIZE.ws_col;

  //! 1234 cols/1234 rows - pattern (19 chars)
  int pattern_chars = 19;
  unsigned int blank_chars = columns_size - pattern_chars;


  /**
   ** ANSI Code
   * move cursor to daterminated position
   ** "\33[line;columnsH"
   */
  printf("\33[0;%uH", blank_chars);

  // Show the terminal informations
  printf("%4u rows/%4u cols", TERMINAL_WINDOW_SIZE.ws_row, TERMINAL_WINDOW_SIZE.ws_col);
}

int main () {

  /**
   * ioctl
   ** The ioctl() system call manipulates the underlying device parameters of special files.
   ** see in http://man7.org/linux/man-pages/man2/ioctl.2.html
   * Init
   */


  ioctl(0, TIOCGWINSZ, &TERMINAL_WINDOW_SIZE);
  show_terminal_size();
  
  return 0;
}
