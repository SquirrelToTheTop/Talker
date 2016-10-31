#include <iostream>
#include "Win.h"

Win::Win() : QWidget(){
  Win_length = 650;
  Win_width = 500;
  off_border_y = 20;

  int width_people, height_people;
  int width_msg_to_send, height_msg_to_send;
  int width_logs = Win_length*2/3, height_logs;
  int inter_textEdit = 20;

  off_border_x = 10;

  height_logs = 300;
  height_people = height_logs;
  width_people = Win_length/3 - off_border_x - inter_textEdit;  
  width_msg_to_send = width_logs;
  height_msg_to_send = 100;

  setFixedSize(Win_length, Win_width);
  
  btn_send_msg = new QPushButton("Send =)", this);

  /* test zone de text avec un QTextEdit read-only */
  logs = new QTextEdit("The quick brown ... ?", this);
  people = new QTextEdit("", this);
  msg_to_send = new QTextEdit("", this);

  logs->setReadOnly(true);
  people->setReadOnly(true);
  msg_to_send->setReadOnly(false);

  logs->setFixedWidth(width_logs);
  logs->setFixedHeight(height_logs);
  people->setFixedWidth(width_people);
  people->setFixedHeight(height_people);
  msg_to_send->setFixedWidth(width_msg_to_send);
  msg_to_send->setFixedHeight(height_msg_to_send);

  logs->move(off_border_x, off_border_y);
  people->move(width_logs+inter_textEdit, off_border_y);
  msg_to_send->move(off_border_x, height_logs + off_border_y + inter_textEdit);

  btn_send_msg->setFixedWidth(width_people);
  btn_send_msg->setFixedHeight(height_msg_to_send);
  btn_send_msg->move(width_logs+inter_textEdit,height_logs + off_border_y + inter_textEdit);

  connect(btn_send_msg, SIGNAL(clicked()), this, SLOT(send_msg()));

  QString test_hostname;
  test_hostname = QHostInfo::localHostName();
  people->setText(test_hostname);

  /* setup socket - network part */
  socket = new QTcpSocket(this);
  socket->abort();
  QString serv_ip = QString("127.0.0.1");
  qint16 serv_port = qint16(24513);
  socket->connectToHost(serv_ip, serv_port);

}

void Win::send_msg(){
    
  QString tmp_msg = msg_to_send->toPlainText();
  if( !tmp_msg.trimmed().isEmpty() ){
    msg_in_logs = logs->toPlainText();
    logs->clear();
    logs->setText(msg_in_logs+"\n"+tmp_msg);  
    msg_to_send->clear();
  }else{
    // Au cas ou le petit malin a mis des espaces ou des retour-charriots
    msg_to_send->clear();
  }
}
