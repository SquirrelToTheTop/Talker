#ifndef DEF_WIN
#define DEF_WIN

#include <QApplication>
#include <QWidget>
#include <QPushButton>

class Win : public QWidget{

  Q_OBJECT
  
 public:
  Win();
  
 private slots:
    void load_sudoku();
    void solve_sudoku();

 private:
  QPushButton *btn_load;
  QPushButton *btn_solve;
};

#endif
