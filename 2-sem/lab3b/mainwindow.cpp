#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Message message(ObjectInfo("bolivia", "Zoom"),
                    "Hello, everyone!",
                    MessageType::INFO, ObjectInfo("ukraine","Discord"), 3454353);
    std::cout << message << std::endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}

