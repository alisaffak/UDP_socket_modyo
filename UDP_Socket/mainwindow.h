#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QUdpSocket m_socket;
    void sendUdpData(QString data, QString ip, int port);

private slots:
    void on_button_add_clicked();

    void on_button_remove_clicked();

    void on_listWidget_currentRowChanged(int currentRow);



    void on_button_send_list_clicked();

    void on_button_giris_clicked();

    void on_button_cikis_clicked();

    void on_button_endofline_clicked();

private:
    Ui::MainWindow *ui;
    int m_Selected = -1;

};
#endif // MAINWINDOW_H
