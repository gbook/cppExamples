#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <QString>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString GenerateColorGradient(unsigned char R1, unsigned char G1, unsigned char B1, unsigned char R2, unsigned char G2, unsigned char B2, int gradientSize, unsigned char colorR[], unsigned char colorG[], unsigned char colorB[]);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
