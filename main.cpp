#include <iostream>
#include <cstring>
#include <ncurses.h>

int main(int argc, char *argv[])
{
  std::string mesg("I can see you");
  char str[80];
  int row,col;				/* to store the number of rows and *
                             * the number of colums of the screen */
  initscr();				/* start the curses mode */
  start_color();
  init_pair(1, COLOR_CYAN, COLOR_RED);
  noecho();
  getmaxyx(stdscr,row,col);		/* get the number of rows and columns */
  int r = row/2;
  int c = (col-mesg.length())/2;
  mvprintw(r, c,"%s",mesg.c_str());
  mvprintw(r+1,c,"%d %d", row, col);
  /* print the message at the center of the screen */
  refresh();

  getch();
  mvchgat(r, c, mesg.length(), A_BOLD | A_ITALIC, 1, NULL);
  refresh();
  getch();
  endwin();
  
  return 0;
}
