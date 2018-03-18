#include "mainwindow.h"
#include "ui_mainwindow.h"

int start_flag=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    memset(&message_info,0,sizeof(Message_info));
    qDebug()<< sizeof(Message_info)<<endl;
    strncpy(message_info.data,"Yzhongbao",sizeof("Yzhongbao"));
    message_info.length=sizeof(Message_info);
    message_info.ntype=3;
    //memset(sendBuf,0,1024);
   // memcpy(sendBuf,&message_info,sizeof(Message_info));

    wdata=QByteArray::fromRawData((char*)&message_info,sizeof(Message_info));

    tcpsocket=new QTcpSocket;

  connect(tcpsocket,SIGNAL(connected()),this,SLOT(startt()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->label->setText(tr("。。。连接中。。。"));
    tcpsocket->connectToHost("localhost",6666);
}


void MainWindow::startt()
{
    tcpsocket->write(wdata);
}
