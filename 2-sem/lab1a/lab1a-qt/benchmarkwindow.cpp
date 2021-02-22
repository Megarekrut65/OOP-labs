#include "benchmarkwindow.h"
#include "ui_benchmarkwindow.h"

BenchmarkWindow::BenchmarkWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BenchmarkWindow),ben_mode(nullptr)
{
    ui->setupUi(this);

}

BenchmarkWindow::~BenchmarkWindow()
{
    delete ben_mode;
    delete ui;
}
void BenchmarkWindow::on_pushButtonStart_clicked()
{
    ben_mode = new BenchmarkMode(ui->listWidget, 1000 );
    if(ui->radioButtonMemory->isChecked()) ben_mode->start_memory();
    if(ui->radioButtonText->isChecked()) ben_mode->start_text();
    if(ui->radioButtonBinary->isChecked()) ben_mode->start_binary();
}

void BenchmarkWindow::on_pushButtonStop_clicked()
{

}

void BenchmarkWindow::on_pushButtonBack_clicked()
{
    this->close();
}
