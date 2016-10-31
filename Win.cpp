#include <iostream>
#include "Win.h"

Win::Win() : QWidget(){
  Win_length = 600;
  Win_width = 400;
  off_border_y = 20;
  off_border_x = 10;

  setFixedSize(Win_length, Win_width);
  
  btn_load = new QPushButton("Load ?", this);
  btn_solve = new QPushButton("Solve ?", this);

  /* test zone de text avec un QLabel*/
  //log_area = new QLabel("Foo ?", this);
  //log_area->setFixedWidth(Win_length);

  /* test zone de text avec un QTextEdit read-only */
  logs = new QTextEdit("The quick brown ... ?", this);
  logs->setReadOnly(true);
  logs->setFixedWidth(Win_length-off_border_y);

  btn_load->move(100,350);
  btn_solve->move(200,350);

  //log_area->move(off_border_x,off_border_y);
  logs->move(off_border_x, off_border_y);

  connect(btn_load, SIGNAL(clicked()), this, SLOT(load_sudoku()));
  connect(btn_solve, SIGNAL(clicked()), this, SLOT(solve_sudoku()));

}

void Win::load_sudoku(){
  //log_area->setText("Tou as clicked on 'Load ?', don't you ?\n");
  msg_in_logs = logs->toPlainText() + "\nBlooop, t'as clicked sur 'Load ?' =)";
  logs->clear();
  logs->setText(msg_in_logs);
}

void Win::solve_sudoku(){
  //log_area->setText("Tou as clicked on 'Solve ?', don't you ?\n");
  msg_in_logs = logs->toPlainText() + "\nBlooop, t'as clicked sur 'Solve ?' =)";
  logs->clear();
  logs->setText(msg_in_logs);
}
