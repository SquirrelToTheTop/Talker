#include <iostream>
#include "Win.h"

Win::Win() : QWidget(){
  Win_length = 650;
  Win_width = 500;
  off_border_y = 20;

  int width_ipaddress, height_ipaddress;
  int width_port, height_port;
  int width_people, height_people;
  int width_msg_to_send, height_msg_to_send;
  int width_logs = Win_length*2/3, height_logs;
  int inter_textEdit = 20;

  off_border_x = 10;

  width_ipaddress = 160;
  height_ipaddress = 30;
  width_port = 100;
  height_port = height_ipaddress;

  height_logs = 300;
  height_people = height_logs;
  width_people = Win_length/3 - off_border_x - inter_textEdit;  
  width_msg_to_send = width_logs;
  height_msg_to_send = 100;

  setFixedSize(Win_length, Win_width);
  
  btn_send_msg = new QPushButton("Send =)", this);
  btn_connect = new QPushButton("Connect !", this);

  /* test zone de text avec un QTextEdit read-only */
  logs = new QTextEdit("The quick brown ... ?", this);
  people = new QTextEdit("", this);
  msg_to_send = new QTextEdit("", this);
  ipAddress = new QTextEdit("127.0.0.1", this);
  port = new QTextEdit("24513", this);

  txt_serv = new QLabel("Server : ", this);

  logs->setReadOnly(true);
  people->setReadOnly(true);
  msg_to_send->setReadOnly(false);
  ipAddress->setReadOnly(false);
  port->setReadOnly(false);

  logs->setFixedWidth(width_logs);
  logs->setFixedHeight(height_logs);
  people->setFixedWidth(width_people);
  people->setFixedHeight(height_people);
  msg_to_send->setFixedWidth(width_msg_to_send);
  msg_to_send->setFixedHeight(height_msg_to_send);
  ipAddress->setFixedWidth(width_ipaddress);
  ipAddress->setFixedHeight(height_ipaddress);
  port->setFixedWidth(width_port);
  port->setFixedHeight(height_port);
  txt_serv->setFixedWidth(width_port);
  txt_serv->setFixedHeight(height_port);

  logs->move(off_border_x, off_border_y);
  people->move(width_logs+inter_textEdit, off_border_y);
  msg_to_send->move(off_border_x, height_logs + off_border_y + inter_textEdit);
  ipAddress->move(off_border_x+width_port+inter_textEdit, off_border_y+2*inter_textEdit+height_logs+height_msg_to_send);
  port->move(off_border_x+width_ipaddress+width_port+2*inter_textEdit, off_border_y+2*inter_textEdit+height_logs+height_msg_to_send);
  txt_serv->move(off_border_x,off_border_y+2*inter_textEdit+height_logs+height_msg_to_send);

  /* Boutons */
  btn_send_msg->setFixedWidth(width_people);
  btn_send_msg->setFixedHeight(height_msg_to_send);
  btn_send_msg->move(width_logs+inter_textEdit,height_logs + off_border_y + inter_textEdit);

  btn_connect->setFixedWidth(width_people);
  btn_connect->setFixedHeight(height_ipaddress);
  btn_connect->move(width_logs+inter_textEdit,height_logs + off_border_y + 2*inter_textEdit+height_msg_to_send);

  connect(btn_send_msg, SIGNAL(clicked()), this, SLOT(send_msg()));
  connect(btn_connect, SIGNAL(clicked()), this, SLOT(connect_to_server()));

  QString test_hostname;
  test_hostname = QHostInfo::localHostName();
  people->setText(test_hostname);  

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

void Win::connect_to_server(){

  ipAddress->setReadOnly(true);
  port->setReadOnly(true);

  /* setup socket - network part */
  socket = new QTcpSocket(this);
  socket->abort();
  QString serv_ip = QString(ipAddress->toPlainText());
  QString tmp = port->toPlainText();
  QTextStream ts(&tmp);
  qint16 serv_port = 0;
  ts >> serv_port;
  socket->connectToHost(serv_ip, serv_port);

}
