#include <iostream>
#include "Win.h"

Win::Win() : QWidget(){

  setFixedSize(400,400);
  
  btn_load = new QPushButton("Load ?", this);
  btn_solve = new QPushButton("Solve ?", this);

  btn_load->move(100,200);
  btn_solve->move(200,200);

  connect(btn_load, SIGNAL(clicked()), this, SLOT(load_sudoku()));
  connect(btn_solve, SIGNAL(clicked()), this, SLOT(solve_sudoku()));

}

void Win::load_sudoku(){
  std::cout << "Ca fonctionne ou je peux aller me faire mettre ? " << std::endl;
}

void Win::solve_sudoku(){
  
}
