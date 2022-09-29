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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_res_clicked();

    void on_slozhenie_clicked();

    void on_vichitanie_clicked();

    void on_umnozhenie_clicked();

    void on_delenie_clicked();

    void on_sin_clicked();

    void on_cos_clicked();

    void on_tg_clicked();

    void on_ctg_clicked();

    void on_asin_clicked();

    void on_acos_clicked();

    void on_atg_clicked();

    void on_actg_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
