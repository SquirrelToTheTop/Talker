#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <iostream>

#include "Win.h"

int main(int argc, char *argv[]){

  QApplication app(argc, argv);

  Win win_grid;
  
  win_grid.show();
  
  return app.exec();
}
