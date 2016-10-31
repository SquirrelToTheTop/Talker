#include <iostream>
#include "Win.h"

Win::Win() : QWidget(){
  Win_length = 650;
  Win_width = 500;
  off_border_y = 20;
  int width_people;
  int width_logs = Win_length*2/3;
  int inter_textEdit = 20;

  off_border_x = 10;

  width_people = Win_length/3 - off_border_x - inter_textEdit;

  setFixedSize(Win_length, Win_width);
  
  btn_load = new QPushButton("Load ?", this);
  btn_solve = new QPushButton("Solve ?", this);

  /* test zone de text avec un QTextEdit read-only */
  logs = new QTextEdit("The quick brown ... ?", this);
  people = new QTextEdit("", this);

  logs->setReadOnly(true);
  people->setReadOnly(true);

  logs->setFixedWidth(width_logs);
  people->setFixedWidth(width_people);

  btn_load->move(100,350);
  btn_solve->move(200,350);

  logs->move(off_border_x, off_border_y);
  people->move(width_logs+inter_textEdit, off_border_y);

  //msg_to_send->move(off_border_x,200);

  connect(btn_load, SIGNAL(clicked()), this, SLOT(load_sudoku()));
  connect(btn_solve, SIGNAL(clicked()), this, SLOT(solve_sudoku()));

  QString test_hostname;
  test_hostname = QHostInfo::localHostName();
  people->setText(test_hostname);

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
