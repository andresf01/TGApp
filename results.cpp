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
    // Set of all settings
    // rt settings
    QString vp9rt1 = "vpxenc --codec=vp9 -rt";
    QString vp9rt2 = "vpxenc --codec=vp9 -rt --kf-max-dist='16'";
    QString vp9rt3 = "vpxenc --codec=vp9 -rt --target-bitrate='3000' --max-q='32'";
    QString vp9rt4 = "vpxenc --codec=vp9 -rt --max-q='32' --kf-max-dist='8'";

    QString hmrt1 = "TAppEncoderStatic -c /hm-4891/cfg/encoder_randomaccess_main.cfg";
    QString hmrt2 = "TAppEncoderStatic -c /hm-4891/cfg/encoder_randomaccess_main10.cfg";
    QString hmrt3 = "TAppEncoderStatic -c /hm-4891/cfg/encoder_randomaccess_main_rext.cfg";

    QString tgrt1 = "turing --speed fast --max-gop-n 16 --rdoq";
    QString tgrt2 = "turing --speed fast --bitrate 1000 --max-gop-n 64 --max-gop-m 1 --rdoq";
    QString tgrt3 = "turing --speed fast --bitrate 2500 --qp 32";
    QString tgrt4 = "turing --speed fast --max-gop-m 8 --max-gop-n 64";

    // bwl settings
    QString vp9bwl1 = "vpxenc --codec=vp9 --end-usage=3 --cq-level=52 --kf-max-dist=100";
    QString vp9bwl2 = "vpxenc --codec=vp9 --end-usage=2 --passes=2 --target-bitrate=300 --kf-max-dist=8";
    QString vp9bwl3 = "vpxenc --codec=vp9 --target-bitrate=500 --best --min-q=16 --max-q=60";
    QString vp9bwl4 = "vpxenc --codec=vp9 --end-usage=vbr --kf-min-dist=0 --kf-max-dist=360 --max-q=63";

    QString tgbwl1 = "turing --speed medium --qp 16 --bitrate 500 --rdoq --min-cu 16";
    QString tgbwl2 = "turing --speed medium --qp 32 --bitrate 500 --rdoq";
    QString tgbwl3 = "turing --speed slow --qp 16 --bitrate 500 --tskip --min-cu 16";
    QString tgbwl4 = "turing --speed slow --qp 32 --bitrate 500 --tskip";

    // Show specific settings for an environment
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
        ui->textVP9->setText(vp9rt1);
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
