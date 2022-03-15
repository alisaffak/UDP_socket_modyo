#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sendUdpData(QString data, QString ip, int port)
{
    m_socket.writeDatagram(data.toUtf8(),QHostAddress(ip), port);
}

void MainWindow::on_button_add_clicked()
{
    QString str = ui->StationName->text();
    if(str == "")
        return;

    ui->listWidget->addItem(str);
}

void MainWindow::on_button_remove_clicked()
{
    if(m_Selected != -1){
    QListWidgetItem *item = ui->listWidget->takeItem(m_Selected);
    delete item;
    ui->listWidget->setCurrentRow(0);
    }

    if(ui->listWidget->count()==1)
        ui->listWidget->setCurrentRow(-1);
    }

void MainWindow::on_listWidget_currentRowChanged(int currentRow)
{
   m_Selected = currentRow;
}

void MainWindow::on_button_send_list_clicked()
{
    QStringList items;
    for(int i =0; i < ui->listWidget->count(); i++){
        items.append(ui->listWidget->item(i)->text());
    }

    QString item_str = "$ARCDSNG372$TASKSTOPLIST="+items.join("|");
    sendUdpData(item_str, "192.168.0.105", 8002);
}


void MainWindow::on_button_giris_clicked()
{
    int stValue = ui->spinBox->value();
    QString DurakIndex = "$ARCDSNG109$TASKINFO=0#LineId#Unnamed#DurakId##G#G#" + QString::number(stValue) +"#0,0";
    sendUdpData(DurakIndex,"192.168.0.105", 8002);
}


void MainWindow::on_button_cikis_clicked()
{
    int stValue = ui->spinBox->value();
    QString DurakIndex = "$ARCDSNG109$TASKINFO=0#LineId#Unnamed#DurakId##G#C#" + QString::number(stValue) +"#0,0";
    sendUdpData(DurakIndex,"192.168.0.105", 8002);
}


void MainWindow::on_button_endofline_clicked()
{
    QString DurakSonu = "$ARCDSNG109$TASKENDEVENT=0";
    sendUdpData(DurakSonu.toUtf8(),"192.168.0.105", 8002);
}

