#ifndef BENCHMARKWINDOW_H
#define BENCHMARKWINDOW_H

#include <QDialog>
#include "Code/benchmark.h"

using namespace bm;
namespace Ui {
class BenchmarkWindow;
}

class BenchmarkWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BenchmarkWindow(QWidget *parent = nullptr);
    ~BenchmarkWindow();

private slots:
    void on_pushButtonStart_clicked();

    void on_pushButtonStop_clicked();

    void on_pushButtonBack_clicked();

private:
    Ui::BenchmarkWindow *ui;
    BenchmarkMode* ben_mode;

};

#endif // BENCHMARKWINDOW_H
