#include "results.h"
#include "ui_results.h"

Results::Results(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Results)
{
    ui->setupUi(this);
}

Results::~Results()
{
    delete ui;
}

void Results::getParameters(int input)
{
    if (input == 1)
    {
        ui->textHM->setText("Tiki");
    }
    if (input == 10)
    {
        ui->textTuring->setText("Tiki");
    }
    if (input == 11)
    {
        ui->textHM->setText("Tiki");
        ui->textTuring->setText("Tiki");
    }
    if (input == 100)
    {
        ui->textVP9->setText("Tiki");
    }
    if (input == 101)
    {
        ui->textHM->setText("Tiki");
        ui->textVP9->setText("Tiki");
    }
    if (input == 110)
    {
        ui->textTuring->setText("Tiki");
        ui->textVP9->setText("Tiki");
    }
    if (input == 111)
    {
        ui->textHM->setText("Tiki");
        ui->textTuring->setText("Tiki");
        ui->textVP9->setText("Tiki");
    }

}
