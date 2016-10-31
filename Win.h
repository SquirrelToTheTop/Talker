#ifndef DEF_WIN
#define DEF_WIN

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QString>

/* test */ 
#include <QHostInfo>

class Win : public QWidget{

  Q_OBJECT

  public:
    Win();

  private slots:
    void send_msg();

  private:
    int Win_length, Win_width;
    int off_border_x, off_border_y;

    QString msg_in_logs;

    QPushButton *btn_send_msg;

    QTextEdit *logs;
    QTextEdit *msg_to_send;
    QTextEdit *people;
};

#endif
