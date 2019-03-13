#include <stdio.h>
#include "screen.h"


/**
 * show_terminal_size()
 ** show in line the number of columns and rows of the terminal
 * @param: specific_row -> specific row to print the information about the terminal size
 **/
void show_terminal_size (unsigned int specific_row) {
  
  /**
   *! TERMINAL_WINDOW_SIZE wasn't been initialized, error
   **/
  if (!HAS_BEEN_INITIALIZATED) {
    perror("TERMINAL_WINDOW_SIZE wasn't been initialized");
    return;
  }

  unsigned int columns_size = TERMINAL_WINDOW_SIZE.ws_col;

  //! 1234 cols/1234 rows - pattern (19 chars)
  int pattern_chars = 17;
  unsigned int blank_chars = columns_size - pattern_chars;


  /**
   ** ANSI Code
   * move cursor to daterminated position
   ** "\33[line;columnsH"
   */

  //* Using a specific row to print the information
  printf("\33[%u;%uH", specific_row, blank_chars);

  // Show the terminal informations
  printf("%3u rows/%3u cols\n", TERMINAL_WINDOW_SIZE.ws_row, TERMINAL_WINDOW_SIZE.ws_col);
}
