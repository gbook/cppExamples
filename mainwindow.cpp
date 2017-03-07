#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    /* declare final arrays containing R,G,B color values */
    const int gradientSize = 100;
    unsigned char colorR[gradientSize];
    unsigned char colorG[gradientSize];
    unsigned char colorB[gradientSize];

    QString colorText;

    colorText = GenerateColorGradient(255, 255, 255, 255, 0, 0, gradientSize, colorR, colorG, colorB);

    ui->txtOutput->setText(colorText);
}

/* -------------------------------------------------------------------- */
/* ------------ GenerateColorGradient --------------------------------- */
/* -------------------------------------------------------------------- */
QString MainWindow::GenerateColorGradient(unsigned char R1, unsigned char G1, unsigned char B1, unsigned char R2, unsigned char G2, unsigned char B2, int gradientSize, unsigned char colorR[], unsigned char colorG[], unsigned char colorB[]) {

    QString str;
    /* generate gradient of 0 - 255 */
    for (int i=0; i<gradientSize; i++) {
        double ratio = (double)i/(double)gradientSize;

        colorR[i] = (int)(((double)R2-(double)R1)*ratio)+R1;
        colorG[i] = (int)(((double)G2-(double)G1)*ratio)+G1;
        colorB[i] = (int)(((double)B2-(double)B1)*ratio)+B1;

        char buffer[50];
        int nChar = sprintf(buffer, "%d) %d, %d, %d\n", i, colorR[i], colorG[i], colorB[i]);
        str += buffer;
    }
    return str;
}
