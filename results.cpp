#include "results.h"
#include "ui_results.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <stdlib.h>
using namespace std;

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

// RT Methods
QString Results::getRtHM(int what){
    QString value = "";
    switch(what){
        case 1:
            value = "TAppEncoderStatic -c /hm-4891/cfg/encoder_randomaccess_main.cfg";
            break;
        case 2:
            value = "TAppEncoderStatic -c /hm-4891/cfg/encoder_randomaccess_main10.cfg";
            break;
        case 3:
            value = "TAppEncoderStatic -c /hm-4891/cfg/encoder_randomaccess_main_rext.cfg";
            break;
        default:
            break;
    }
    return value;
}

QString Results::getRtVPX(int what){
    QString value = "";
    switch(what){
        case 1:
            value = "vpxenc --codec=vp9 -rt";
            break;
        case 2:
            value = "vpxenc --codec=vp9 -rt --kf-max-dist='16'";
            break;
        case 3:
            value = "vpxenc --codec=vp9 -rt --target-bitrate='3000' --max-q='32'";
            break;
        case 4:
            value = "vpxenc --codec=vp9 -rt --max-q='32' --kf-max-dist='8'";
            break;
        default:
            break;
    }
    return value;
}

QString Results::getRtTG(int what){
    QString value = "";
    switch(what){
        case 1:
            value = "turing --speed fast --max-gop-n 16 --rdoq";
            break;
        case 2:
            value = "turing --speed fast --bitrate 1000 --max-gop-n 64 --max-gop-m 1 --rdoq";
            break;
        case 3:
            value = "turing --speed fast --bitrate 2500 --qp 32";
            break;
        case 4:
            value = "turing --speed fast --max-gop-m 8 --max-gop-n 64";
            break;
        default:
            break;
    }

    return value;
}

// BWL methods
QString Results::getBwlHM(int what){
    QString value = "";
    switch(what){
        case 1:
            value = "TAppEncoderStatic";
            break;
        case 2:
            value = "TAppEncoderStatic";
            break;
        case 3:
            value = "TAppEncoderStatic";
            break;
        default:
            break;
    }

    return value;
}

QString Results::getBwlVPX(int what){
    QString value = "";
    switch(what){
        case 1:
            value = "vpxenc --codec=vp9 --end-usage=3 --cq-level=52 --kf-max-dist=100";
            break;
        case 2:
            value = "vpxenc --codec=vp9 --end-usage=2 --passes=2 --target-bitrate=300 --kf-max-dist=8";
            break;
        case 3:
            value = "vpxenc --codec=vp9 --target-bitrate=500 --best --min-q=16 --max-q=60";
            break;
        case 4:
            value = "vpxenc --codec=vp9 --end-usage=vbr --kf-min-dist=0 --kf-max-dist=360 --max-q=63";
            break;
        default:
            break;
    }

    return value;
}

QString Results::getBwlTG(int what){
    QString value = "";
    switch(what){
        case 1:
            value = "turing --speed medium --qp 16 --bitrate 500 --rdoq --min-cu 16";
            break;
        case 2:
            value = "turing --speed medium --qp 32 --bitrate 500 --rdoq";
            break;
        case 3:
            value = "turing --speed slow --qp 16 --bitrate 500 --tskip --min-cu 16";
            break;
        case 4:
            value = "turing --speed slow --qp 32 --bitrate 500 --tskip";
            break;
        default:
            break;
    }

    return value;
}

// UHD methods
QString Results::getUhdHM(int what){
    QString value = "";
    switch(what){
        case 1:
            value = "TAppEncoderStatic";
            break;
        case 2:
            value = "TAppEncoderStatic";
            break;
        default:
            break;
    }

    return value;
}

QString Results::getUhdVPX(int what){
    QString value = "VP9 settings in UHD are not available";
    return value;
}

QString Results::getUhdTG(int what){
    QString value = "";
    switch(what){
        case 1:
            value = "turing";
            break;
        case 2:
            value = "turing";
            break;
        default:
            break;
    }

    return value;
}

// LSS methods
QString Results::getLssHM(int what){
    QString value = "";
    switch(what){
        case 1:
            value = "TAppEncoderStatic";
            break;
        case 2:
            value = "TAppEncoderStatic";
            break;
        case 3:
            value = "TAppEncoderStatic";
            break;
        default:
            break;
    }

    return value;
}

QString Results::getLssVPX(int what){
    QString value = "";
    switch(what){
        case 1:
            value = "vpxenc --codec=vp9 ";
            break;
        case 2:
            value = "vpxenc --codec=vp9 ";
            break;
        case 3:
            value = "vpxenc --codec=vp9 ";
            break;
        default:
            break;
    }

    return value;
}

QString Results::getLssTG(int what){
    QString value = "HEVC Turing Codec settings in Lossles are not available";
    return value;
}

void Results::writeFile(QString filename, QString data){
    QFile file( filename );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );
        stream << data << endl;
    }
}

void Results::getParametersFile(int input, int env){
    QString header = "";
    QString footer = "";
    QString buff = "";
    // Write specific settings for an environment
//    writeFile("archivo.txt","datos");
    if (input == 1)
    {
        if (env == 0){
            for (int var = 0; var < 3; ++var) {
                writeFile("hmrt"+QString::number(var)+".sh",header+getRtHM(var + 1)+footer);
            }
            // ui->textHM->setText(hmrt);
        }
        if (env == 1){
            for (int var = 0; var < 3; ++var) {
                writeFile("hmbwl"+QString::number(var)+".sh",header+getBwlHM(var + 1)+footer);
            }
            // ui->textHM->setText(hmbwl);
        }
        if (env == 2){
            for (int var = 0; var < 3; ++var) {
                writeFile("hmlss"+QString::number(var)+".sh",header+getLssHM(var + 1)+footer);
            }
            // ui->textHM->setText(hmlss);
        }
        if (env == 3){
            for (int var = 0; var < 2; ++var) {
                writeFile("hmuhd"+QString::number(var)+".sh",header+getUhdHM(var + 1)+footer);
            }
            // ui->textHM->setText(hmuhd);
        }
    }
    if (input == 10)
    {
        if (env == 0){
            for (int var = 0; var < 4; ++var) {
                writeFile("tgrt"+QString::number(var)+".sh",header+getRtTG(var + 1)+footer);
            }
            // ui->textTuring->setText(tgrt);
        }
        if (env == 1){
            for (int var = 0; var < 4; ++var) {
                writeFile("tgbwl"+QString::number(var)+".sh",header+getBwlTG(var + 1)+footer);
            }
            // ui->textTuring->setText(tgbwl);
        }
        if (env == 2){
            // No results for LSS
            // ui->textTuring->setText(tglss);
        }
        if (env == 3){
            for (int var = 0; var < 2; ++var) {
                writeFile("tguhd"+QString::number(var)+".sh",header+getUhdTG(var + 1)+footer);
            }
            // ui->textTuring->setText(tguhd);
        }
    }
    if (input == 11)
    {
        if (env == 0)
        {
            for (int var = 0; var < 3; ++var) {
                writeFile("hmrt"+QString::number(var)+".sh",header+getRtHM(var + 1)+footer);
            }
            for (int var = 0; var < 4; ++var) {
                writeFile("tgrt"+QString::number(var)+".sh",header+getRtTG(var + 1)+footer);
            }
            // ui->textHM->setText(hmrt);
            // ui->textTuring->setText(tgrt);
        }
        if (env == 1)
        {
            for (int var = 0; var < 3; ++var) {
                writeFile("hmbwl"+QString::number(var)+".sh",header+getBwlHM(var + 1)+footer);
            }
            for (int var = 0; var < 4; ++var) {
                writeFile("tgbwl"+QString::number(var)+".sh",header+getBwlTG(var + 1)+footer);
            }
            // ui->textHM->setText(hmbwl);
            // ui->textTuring->setText(tgbwl);
        }
        if (env == 2)
        {
            for (int var = 0; var < 3; ++var) {
                writeFile("hmlss"+QString::number(var)+".sh",header+getLssHM(var + 1)+footer);
            }
            // ui->textHM->setText(hmlss);
            // ui->textTuring->setText(tglss);
        }
        if (env == 3)
        {
            for (int var = 0; var < 2; ++var) {
                writeFile("hmuhd"+QString::number(var)+".sh",header+getUhdHM(var + 1)+footer);
            }
            for (int var = 0; var < 2; ++var) {
                writeFile("tguhd"+QString::number(var)+".sh",header+getUhdTG(var + 1)+footer);
            }
            // ui->textHM->setText(hmuhd);
            // ui->textTuring->setText(tguhd);
        }

    }
    if (input == 100)
    {
        if (env == 0){
            for (int var = 0; var < 4; ++var) {
                writeFile("vpxrt"+QString::number(var)+".sh",header+getRtVPX(var + 1)+footer);
            }
            // ui->textVP9->setText(vp9rt);
        }
        if (env == 1){
            for (int var = 0; var < 4; ++var) {
                writeFile("vpxbwl"+QString::number(var)+".sh",header+getBwlVPX(var + 1)+footer);
            }
            // ui->textVP9->setText(vp9bwl);
        }
        if (env == 2){
            for (int var = 0; var < 3; ++var) {
                writeFile("vpxlss"+QString::number(var)+".sh",header+getLssVPX(var + 1)+footer);
            }
            // ui->textVP9->setText(vp9lss);
        }
        if (env == 3){
            // VPX is not available for UHD
            // ui->textVP9->setText(vp9uhd);
        }
    }
    if (input == 101)
    {
        if (env == 0)
        {
            for (int var = 0; var < 3; ++var) {
                writeFile("hmrt"+QString::number(var)+".sh",header+getRtHM(var + 1)+footer);
            }
            for (int var = 0; var < 4; ++var) {
                writeFile("vpxrt"+QString::number(var)+".sh",header+getRtVPX(var + 1)+footer);
            }
            // ui->textHM->setText(hmrt);
            // ui->textVP9->setText(vp9rt);
        }
        if (env == 1)
        {
            for (int var = 0; var < 3; ++var) {
                writeFile("hmbwl"+QString::number(var)+".sh",header+getBwlHM(var + 1)+footer);
            }
            for (int var = 0; var < 4; ++var) {
                writeFile("vpxbwl"+QString::number(var)+".sh",header+getBwlVPX(var + 1)+footer);
            }
            // ui->textHM->setText(hmbwl);
            // ui->textVP9->setText(vp9bwl);
        }
        if (env == 2)
        {
            for (int var = 0; var < 3; ++var) {
                writeFile("hmlss"+QString::number(var)+".sh",header+getLssHM(var + 1)+footer);
            }
            for (int var = 0; var < 3; ++var) {
                writeFile("vpxlss"+QString::number(var)+".sh",header+getLssVPX(var + 1)+footer);
            }
            // ui->textHM->setText(hmlss);
            // ui->textVP9->setText(vp9lss);
        }
        if (env == 3)
        {
            for (int var = 0; var < 2; ++var) {
                writeFile("hmuhd"+QString::number(var)+".sh",header+getUhdHM(var + 1)+footer);
            }
            // ui->textHM->setText(hmuhd);
            // ui->textVP9->setText(vp9uhd);
        }

    }
    if (input == 110)
    {
        if (env == 0)
        {
            for (int var = 0; var < 4; ++var) {
                writeFile("tgrt"+QString::number(var)+".sh",header+getRtTG(var + 1)+footer);
            }
            for (int var = 0; var < 4; ++var) {
                writeFile("vpxrt"+QString::number(var)+".sh",header+getRtVPX(var + 1)+footer);
            }
            // ui->textTuring->setText(tgrt);
            // ui->textVP9->setText(vp9rt);
        }
        if (env == 1)
        {
            for (int var = 0; var < 4; ++var) {
                writeFile("tgbwl"+QString::number(var)+".sh",header+getBwlTG(var + 1)+footer);
            }
            for (int var = 0; var < 4; ++var) {
                writeFile("vpxbwl"+QString::number(var)+".sh",header+getBwlVPX(var + 1)+footer);
            }
            // ui->textTuring->setText(tgbwl);
            // ui->textVP9->setText(vp9bwl);
        }
        if (env == 2)
        {
            // TG is not available for LSS
            for (int var = 0; var < 3; ++var) {
                writeFile("vpxlss"+QString::number(var)+".sh",header+getLssVPX(var + 1)+footer);
            }
            // ui->textTuring->setText(tglss);
            // ui->textVP9->setText(vp9lss);
        }
        if (env == 3)
        {
            for (int var = 0; var < 2; ++var) {
                writeFile("tguhd"+QString::number(var)+".sh",header+getUhdTG(var + 1)+footer);
            }
            // VPX for UHD is not available
            // ui->textTuring->setText(tguhd);
            // ui->textVP9->setText(vp9uhd);
        }

    }
    if (input == 111)
    {
        if (env == 0)
        {
            for (int var = 0; var < 3; ++var) {
                writeFile("hmrt"+QString::number(var)+".sh",header+getRtHM(var + 1)+footer);
            }
            for (int var = 0; var < 4; ++var) {
                writeFile("tgrt"+QString::number(var)+".sh",header+getRtTG(var + 1)+footer);
            }
            for (int var = 0; var < 4; ++var) {
                writeFile("vpxrt"+QString::number(var)+".sh",header+getRtVPX(var + 1)+footer);
            }
            // ui->textHM->setText(hmrt);
            // ui->textTuring->setText(tgrt);
            // ui->textVP9->setText(vp9rt);
        }
        if (env == 1)
        {
            for (int var = 0; var < 3; ++var) {
                writeFile("hmbwl"+QString::number(var)+".sh",header+getBwlHM(var + 1)+footer);
            }
            for (int var = 0; var < 4; ++var) {
                writeFile("tgbwl"+QString::number(var)+".sh",header+getBwlTG(var + 1)+footer);
            }
            for (int var = 0; var < 4; ++var) {
                writeFile("vpxbwl"+QString::number(var)+".sh",header+getBwlVPX(var + 1)+footer);
            }
            // ui->textHM->setText(hmbwl);
            // ui->textTuring->setText(tgbwl);
            // ui->textVP9->setText(vp9bwl);
        }
        if (env == 2)
        {
            for (int var = 0; var < 3; ++var) {
                writeFile("hmlss"+QString::number(var)+".sh",header+getLssHM(var + 1)+footer);
            }
            for (int var = 0; var < 3; ++var) {
                writeFile("vpxlss"+QString::number(var)+".sh",header+getLssVPX(var + 1)+footer);
            }
            // ui->textHM->setText(hmlss);
            // ui->textTuring->setText(tglss);
            // ui->textVP9->setText(vp9lss);
        }
        if (env == 3)
        {
            for (int var = 0; var < 2; ++var) {
                writeFile("hmuhd"+QString::number(var)+".sh",header+getUhdHM(var + 1)+footer);
            }
            for (int var = 0; var < 2; ++var) {
                writeFile("tguhd"+QString::number(var)+".sh",header+getUhdTG(var + 1)+footer);
            }
            // ui->textHM->setText(hmuhd);
            // ui->textTuring->setText(tguhd);
            // ui->textVP9->setText(vp9uhd);
        }
    }
}

void Results::setParameters(int input, int env)
{
    cout << env;
    // Set of all settings
    // rt settings
    QString vp9rt1 = getRtVPX(1);
    QString vp9rt2 = getRtVPX(2);
    QString vp9rt3 = getRtVPX(3);
    QString vp9rt4 = getRtVPX(4);

    QString vp9rt  = vp9rt1 + "\n" + vp9rt2 + " (*)\n" + vp9rt3 + "\n" + vp9rt4;

    QString hmrt1 = getRtHM(1);
    QString hmrt2 = getRtHM(2);
    QString hmrt3 = getRtHM(3);

    QString hmrt = hmrt1 + "\n" + hmrt2 + "\n" + hmrt3;

    QString tgrt1 = getRtTG(1);
    QString tgrt2 = getRtTG(2);
    QString tgrt3 = getRtTG(3);
    QString tgrt4 = getRtTG(4);

    QString tgrt = tgrt1 + "\n" + tgrt2 + "\n" + tgrt3 + "\n" + tgrt4;

    // bwl settings
    QString vp9bwl1 = getBwlVPX(1);
    QString vp9bwl2 = getBwlVPX(2);
    QString vp9bwl3 = getBwlVPX(3);
    QString vp9bwl4 = getBwlVPX(4);

    QString vp9bwl = vp9bwl1 + "\n" + vp9bwl2 + "\n" + vp9bwl3 + "\n" + vp9bwl4;

    QString hmbwl1 = getBwlHM(1);
    QString hmbwl2 = getBwlHM(2);
    QString hmbwl3 = getBwlHM(3);

    QString hmbwl = hmbwl1 + "\n" + hmbwl2 + "\n" + hmbwl3;

    QString tgbwl1 = getBwlTG(1);
    QString tgbwl2 = getBwlTG(2);
    QString tgbwl3 = getBwlTG(3);
    QString tgbwl4 = getBwlTG(4);

    QString tgbwl = tgbwl1 + "\n" + tgbwl2 + "\n" + tgbwl3 + "\n" + tgbwl4;

    // lss settings

    QString vp9lss1 = getLssVPX(1);
    QString vp9lss2 = getLssVPX(2);
    QString vp9lss3 = getLssVPX(3);

    QString vp9lss = vp9lss1 + "\n" + vp9lss2 + "\n" + vp9lss3;

    QString hmlss1 = getLssHM(1);
    QString hmlss2 = getLssHM(2);
    QString hmlss3 = getLssHM(3);

    QString hmlss = hmlss1 + "\n" + hmlss2 + "\n" + hmlss3;

    QString tglss = getLssTG(0);

    // uhd settings

    QString vp9uhd = getUhdVPX(0);

    QString hmuhd1 = getUhdHM(1);
    QString hmuhd2 = getUhdHM(2);

    QString hmuhd = hmuhd1 + "\n" + hmuhd2;

    QString tguhd1 = getUhdTG(1);
    QString tguhd2 = getUhdTG(2);

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
