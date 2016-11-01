#ifndef DEF_WIN
#define DEF_WIN

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QString>
#include <QLabel>
#include <QtNetwork>
#include <QTextStream>

/* test */ 
#include <QHostInfo>

class Win : public QWidget{

  Q_OBJECT

  public:
    Win();

  private slots:
    void send_msg();
    void connect_to_server();

  private:
    int Win_length, Win_width;
    int off_border_x, off_border_y;

    QString msg_in_logs;

    QPushButton *btn_send_msg;
    QPushButton *btn_connect;

    QTextEdit *logs;
    QTextEdit *msg_to_send;
    QTextEdit *people;
    QTextEdit *ipAddress, *port;

    QLabel *txt_serv;

    QTcpSocket *socket;
};

#endif
