#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(0));
    set_registry();
    set_textes();
}
void MainWindow::set_textes()
{
    textes = {
            "Hello, wold!",
            "How are you doing?",
            "Mama Mia!",
            "Guten Tag!",
            "Are you creizy?",
            "Just do it!",
            "There is amazing weather today, isn't?",
            "Banana man...",
            "Go away!",
            "Potatos roal"};
}
void MainWindow::set_registry()
{
    registry.registry_type("PeriodicProgram",
                            std::make_shared<cn::PeriodicProgram>(textes));
    registry.registry_type("RandomProgram",
                            std::make_shared<cn::RandomProgram>(textes));
    registry.registry_type("AfterProgram",
                           std::make_shared<cn::AfterProgram>(textes));
    registry.registry_type("WaitProgram",
                            std::make_shared<cn::WaitProgram>(textes));
}
MainWindow::~MainWindow()
{
    delete ui;
}

