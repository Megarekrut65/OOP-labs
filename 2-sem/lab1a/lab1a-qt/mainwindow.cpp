#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    info = std::make_shared<InfoWindow>();
    open_mode = nullptr;
    text_path = "monsters.txt";
    binary_path = "monsters.bin";
    ui->setupUi(this);
    this->setWindowTitle("Forest of monsters");
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
void MainWindow::open_interactive_mode()
{
    InteractiveWindow interactive(open_mode);
    interactive.setModal(true);
    interactive.exec();
}
void MainWindow::on_pushButtonMemory_clicked()
{
    open_mode = std::make_shared<MemoryMode>();
    open_interactive_mode();
}
void MainWindow::on_pushButtonText_clicked()
{
    open_mode = std::make_shared<FileMode>(text_path, omode::Mode::TEXT);
    open_interactive_mode();
}
void MainWindow::on_pushButtonBinary_clicked()
{
    open_mode = std::make_shared<FileMode>(binary_path, omode::Mode::BINARY);
    open_interactive_mode();
}
