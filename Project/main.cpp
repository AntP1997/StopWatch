/**
@authr Antoine Price
Date 12/25/2021
**/


#include <iostream>
#include <curses.h>
#include <iomanip>
#include <unistd.h>
using namespace std;



 int main(void)
 {
  int hold=60;
  initscr();
  start_color();
  int seconds=0,minute=0,hour=0;
  init_pair(1,COLOR_MAGENTA,COLOR_YELLOW);
  init_pair(2,COLOR_GREEN,COLOR_WHITE);
  bkgd(COLOR_PAIR(2));
  attron(COLOR_PAIR(1));
  nodelay(stdscr,true);

  while(getch() == -1)
 {
  if(seconds <60)
  {//seconds

    refresh();


    mvprintw(17,40,"<<< hour:%d | minute:%d |seconds:%d >>",hour,minute,seconds);
    seconds++;
    refresh();
    napms(100);
     //sleep(1);

  }
  else if(seconds==60)
  {//minute

     seconds=0;

     minute++;
     refresh();
    if(minute == 59 )
    { //hour
      hour++;
      minute=0;
      refresh();

    }
  }





  refresh();
 }



  endwin();

 return 0;
}

