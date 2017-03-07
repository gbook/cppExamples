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
QString GenerateColorGradient(unsigned char R1, unsigned char G1, unsigned char B1, unsigned char R2, unsigned char G2, unsigned char B2, int gradientSize, unsigned char colorR[], unsigned char colorG[], unsigned char colorB[]) {

    QString str;
    /* generate gradient of 0 - 255 */
    for (int i=0; i<100; i++) {
        double percentSR = ((double)i/(double)gradientSize)*(double)R1;
        double percentER = (1.0-((double)i/(double)gradientSize))*(double)R2;
        colorR[i] = (int)percentSR + (int)percentER;

        double percentSG = ((double)i/(double)gradientSize)*(double)G1;
        double percentEG = (1.0-((double)i/(double)gradientSize))*(double)G2;
        colorG[i] = (int)percentSG + (int)percentEG;

        double percentSB = ((double)i/(double)gradientSize)*(double)B1;
        double percentEB = (1.0-((double)i/(double)gradientSize))*(double)B2;
        colorB[i] = (int)percentSB + (int)percentEB;

        char buffer[50];
        int nChar = sprintf(buffer, "%d, %d, %d, 255", colorR[i], colorG[i], colorB[i]);
        str += buffer;
    }
    return str;
}
