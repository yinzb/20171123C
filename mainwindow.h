#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
typedef struct packer
{
    int length;
    int ntype;
    char data[10];
}Message_info;



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QTcpSocket *tcpsocket;


private slots:
    void on_pushButton_clicked();
    void startt();

private:
    Ui::MainWindow *ui;
    Message_info message_info;
    QByteArray wdata;
    char sendBuf[1024];
};

#endif // MAINWINDOW_H
