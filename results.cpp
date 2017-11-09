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

void Results::getParameters(int input, int env)
{
    // Set of all settings
    // rt settings
    QString vp9rt1 = "vpxenc --codec=vp9 -rt";
    QString vp9rt2 = "vpxenc --codec=vp9 -rt --kf-max-dist='16'";
    QString vp9rt3 = "vpxenc --codec=vp9 -rt --target-bitrate='3000' --max-q='32'";
    QString vp9rt4 = "vpxenc --codec=vp9 -rt --max-q='32' --kf-max-dist='8'";

    QString vp9rt  = vp9rt1 + "\n" + vp9rt2 + " (*)\n" + vp9rt3 + "\n" + vp9rt4;

    QString hmrt1 = "TAppEncoderStatic -c /hm-4891/cfg/encoder_randomaccess_main.cfg";
    QString hmrt2 = "TAppEncoderStatic -c /hm-4891/cfg/encoder_randomaccess_main10.cfg";
    QString hmrt3 = "TAppEncoderStatic -c /hm-4891/cfg/encoder_randomaccess_main_rext.cfg";

    QString hmrt = hmrt1 + "\n" + hmrt2 + "\n" + hmrt3;

    QString tgrt1 = "turing --speed fast --max-gop-n 16 --rdoq";
    QString tgrt2 = "turing --speed fast --bitrate 1000 --max-gop-n 64 --max-gop-m 1 --rdoq";
    QString tgrt3 = "turing --speed fast --bitrate 2500 --qp 32";
    QString tgrt4 = "turing --speed fast --max-gop-m 8 --max-gop-n 64";

    QString tgrt = tgrt1 + "\n" + tgrt2 + "\n" + tgrt3 + "\n" + tgrt4;

    // bwl settings
    QString vp9bwl1 = "vpxenc --codec=vp9 --end-usage=3 --cq-level=52 --kf-max-dist=100";
    QString vp9bwl2 = "vpxenc --codec=vp9 --end-usage=2 --passes=2 --target-bitrate=300 --kf-max-dist=8";
    QString vp9bwl3 = "vpxenc --codec=vp9 --target-bitrate=500 --best --min-q=16 --max-q=60";
    QString vp9bwl4 = "vpxenc --codec=vp9 --end-usage=vbr --kf-min-dist=0 --kf-max-dist=360 --max-q=63";

    QString vp9bwl = vp9bwl1 + "\n" + vp9bwl2 + "\n" + vp9bwl3 + "\n" + vp9bwl4;

    QString hmbwl1;
    QString hmbwl2;
    QString hmbwl3;

    QString hmbwl = hmbwl1 + "\n" + hmbwl2 + "\n" + hmbwl3;

    QString tgbwl1 = "turing --speed medium --qp 16 --bitrate 500 --rdoq --min-cu 16";
    QString tgbwl2 = "turing --speed medium --qp 32 --bitrate 500 --rdoq";
    QString tgbwl3 = "turing --speed slow --qp 16 --bitrate 500 --tskip --min-cu 16";
    QString tgbwl4 = "turing --speed slow --qp 32 --bitrate 500 --tskip";

    QString tgbwl = tgbwl1 + "\n" + tgbwl2 + "\n" + tgbwl3 + "\n" + tgbwl4;

    // lss settings

    QString vp9lss1;
    QString vp9lss2;
    QString vp9lss3;

    QString vp9lss = vp9lss1 + "\n" + vp9lss2 + "\n" + vp9lss3;

    QString hmlss1;
    QString hmlss2;
    QString hmlss3;

    QString hmlss = hmlss1 + "\n" + hmlss2 + "\n" + hmlss3;

    QString tglss;

    // uhd settings

    QString vp9uhd;

    QString hmuhd1;
    QString hmuhd2;

    QString hmuhd = hmuhd1 + "\n" + hmuhd2;

    QString tguhd1;
    QString tguhd2;

    QString tguhd = tguhd1 + "\n" + tguhd2;


    // Show specific settings for an environment
    if (input == 1)
    {
        if (env == 0)
            ui->textHM->setText(hmrt);
        if (env == 1)
            ui->textHM->setText(hmbwl);
        if (env == 2)
            ui->textHM->setText(hmlss);
        if (env == 3)
            ui->textHM->setText(hmuhd);
    }
    if (input == 10)
    {
        if (env == 0)
            ui->textTuring->setText(tgrt);
        if (env == 1)
            ui->textTuring->setText(tgbwl);
        if (env == 2)
            ui->textTuring->setText(tglss);
        if (env == 3)
            ui->textTuring->setText(tguhd);
    }
    if (input == 11)
    {
        if (env == 0)
        {
            ui->textHM->setText(hmrt);
            ui->textTuring->setText(tgrt);
        }
        if (env == 1)
        {
            ui->textHM->setText(hmbwl);
            ui->textTuring->setText(tgbwl);
        }
        if (env == 2)
        {
            ui->textHM->setText(hmlss);
            ui->textTuring->setText(tglss);
        }
        if (env == 3)
        {
            ui->textHM->setText(hmuhd);
            ui->textTuring->setText(tguhd);
        }

    }
    if (input == 100)
    {
        if (env == 0)
            ui->textVP9->setText(vp9rt);
        if (env == 1)
            ui->textVP9->setText(vp9bwl);
        if (env == 2)
            ui->textVP9->setText(vp9lss);
        if (env == 3)
            ui->textVP9->setText(vp9uhd);
    }
    if (input == 101)
    {
        if (env == 0)
        {
            ui->textHM->setText(hmrt);
            ui->textVP9->setText(vp9rt);
        }
        if (env == 1)
        {
            ui->textHM->setText(hmbwl);
            ui->textVP9->setText(vp9bwl);
        }
        if (env == 2)
        {
            ui->textHM->setText(hmlss);
            ui->textVP9->setText(vp9lss);
        }
        if (env == 3)
        {
            ui->textHM->setText(hmuhd);
            ui->textVP9->setText(vp9uhd);
        }

    }
    if (input == 110)
    {
        if (env == 0)
        {
            ui->textTuring->setText(tgrt);
            ui->textVP9->setText(vp9rt);
        }
        if (env == 1)
        {
            ui->textTuring->setText(tgbwl);
            ui->textVP9->setText(vp9bwl);
        }
        if (env == 2)
        {
            ui->textTuring->setText(tglss);
            ui->textVP9->setText(vp9lss);
        }
        if (env == 3)
        {
            ui->textTuring->setText(tguhd);
            ui->textVP9->setText(vp9uhd);
        }

    }
    if (input == 111)
    {
        if (env == 0)
        {
            ui->textHM->setText(hmrt);
            ui->textTuring->setText(tgrt);
            ui->textVP9->setText(vp9rt);
        }
        if (env == 1)
        {
            ui->textHM->setText(hmbwl);
            ui->textTuring->setText(tgbwl);
            ui->textVP9->setText(vp9bwl);
        }
        if (env == 2)
        {
            ui->textHM->setText(hmlss);
            ui->textTuring->setText(tglss);
            ui->textVP9->setText(vp9lss);
        }
        if (env == 3)
        {
            ui->textHM->setText(hmuhd);
            ui->textTuring->setText(tguhd);
            ui->textVP9->setText(vp9uhd);
        }

    }

}
