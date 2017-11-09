#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stdio.h"
#include "results.h"
#include "ui_results.h"
#include "about.h"
#include "ui_about.h"

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

void MainWindow::on_actionAbout_triggered()
{
    // Show Dialog about research
    About *about = new About;
    about->show();
}

void MainWindow::on_actionExit_triggered()
{
    delete ui;
    exit(0);
}

// Binary model to represent three options choose
// Seven possibilites (001,010,011,100,101,110,111) for codec
// Four possibilities (0,1,2,3) for environment
void MainWindow::on_getParameters_clicked()
{
    int input = 0;
    int env = 0;
    if (ui->isVP9->isChecked())
    {
        input += 100;
    }
    if (ui->isTuring->isChecked())
    {
        input += 10;
    }
    if (ui->isHM->isChecked())
    {
        input += 1;
    }

    if (ui->isRT->isChecked())
    {
        env = 0;
    }
    if (ui->isBWL->isChecked())
    {
        env = 1;
    }
    if (ui->isLSS->isChecked())
    {
        env = 2;
    }
    if (ui->isUHD->isChecked())
    {
        env = 3;
    }

    // QString a = QString::number(input);
    // ui->getParameters->setText(a);
    Results *results = new Results;
    results->getParameters(input, env);
    results->show();
}
