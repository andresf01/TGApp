#ifndef RESULTS_H
#define RESULTS_H

#include <QDialog>

namespace Ui {
class Results;
}

class Results : public QDialog
{
    Q_OBJECT

public:
    explicit Results(QWidget *parent = 0);
    ~Results();
    void setParameters(int input, int env);
    void getParametersFile(int input, int env);
    QString getLssHM(int what);
    QString getLssVPX(int what);
    QString getLssTG(int what);
    QString getUhdHM(int what);
    QString getUhdVPX(int what);
    QString getUhdTG(int what);
    QString getRtHM(int what);
    QString getRtVPX(int what);
    QString getRtTG(int what);
    QString getBwlHM(int what);
    QString getBwlVPX(int what);
    QString getBwlTG(int what);
    void writeFile(QString filename, QString data);


private:
    Ui::Results *ui;
};

#endif // RESULTS_H
