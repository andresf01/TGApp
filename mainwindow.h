#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionAbout_triggered();

    void on_actionExit_triggered();

    void on_getParameters_clicked();

    void on_actionExport_as_sh_triggered();

    int get_codec_ui();

    int get_env_ui();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
