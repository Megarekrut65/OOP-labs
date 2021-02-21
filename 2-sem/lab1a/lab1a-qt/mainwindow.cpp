#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    info = std::make_shared<InfoWindow>();
    open_mode = nullptr;
    text_path = "Data/monsters.txt";
    binary_path = "Data/monsters.bin";
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_5_clicked()
{
    info->show();
}

void MainWindow::on_pushButton_clicked()
{
    this->close();
}

void MainWindow::on_pushButtonMemory_clicked()
{
    open_mode = std::make_shared<MemoryMode>();
}

void MainWindow::on_pushButtonText_clicked()
{
    open_mode = std::make_shared<FileMode>(text_path, omode::Mode::TEXT);
}

void MainWindow::on_pushButtonBinary_clicked()
{
    open_mode = std::make_shared<FileMode>(binary_path, omode::Mode::BINARY);
}
