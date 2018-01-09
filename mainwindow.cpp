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
    // QString a = QString::number(input);
    // ui->getParameters->setText(a);
    Results *results = new Results;
    results->setParameters(get_codec_ui(), get_env_ui());
    results->show();
}

int MainWindow::get_codec_ui(){
    int input = 0;
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
    return input;
}

int MainWindow::get_env_ui(){
    int env = -1;
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
    return env;
}

void MainWindow::on_actionExport_as_sh_triggered()
{
    Results *results = new Results;
    results->getParametersFile(get_codec_ui(), get_env_ui());
}
