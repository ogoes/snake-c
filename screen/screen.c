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
  } // close if statement

  unsigned int columns_size = TERMINAL_WINDOW_SIZE.ws_col;

  //! 123 cols/123 rows - pattern (17 chars)

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
  
} // close function

int main () {

  /**
   * ioctl
   ** The ioctl() system call manipulates the underlying device parameters of special files.
   ** see in http://man7.org/linux/man-pages/man2/ioctl.2.html
   * Init
   */
  ioctl(0, TIOCGWINSZ, &TERMINAL_WINDOW_SIZE);
  HAS_BEEN_INITIALIZATED = 1; // iniatialization flag
  
  struct game_area area;
  area.top_row = 1;
  area.bottom_row = 20;
  area.left_col = 5;
  area.right_col = 100;

  for (int i = 0; i < TERMINAL_WINDOW_SIZE.ws_row; ++i) {
    for (int j = 0; j < TERMINAL_WINDOW_SIZE.ws_col; ++j) {
      if ((i == area.top_row || i == area.bottom_row) && (j >= area.left_col && j <= area.right_col)) {
        if (j == area.left_col || j == area.right_col) {
          printf("+");
        } else {
          printf("-");
        }
      } else if ((j == area.left_col || j == area.right_col) && (i >= area.top_row && i <= area.bottom_row)) {
        printf("|");
      } else {
        printf(" ");
      }
    }
  }
  
  printf("\33[10;10H");
  printf("asd");
  // show_terminal_size(22);
  
  return 0;
}
