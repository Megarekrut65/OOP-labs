#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(0));
    cn::ProgramFactory factory;
    std::shared_ptr<cn::BasicProgram> program1 =
            factory.create_periodic_program(cn::ProgramType::ALL, ProgramInfo("ukraine","Google Drive")),
            program2 = factory.create_random_program(cn::ProgramType::ALL, ProgramInfo("uk", "YouTube"));
    program1->send(program2, MessageType::ERROR);
    program1->send(program2, MessageType::INFO);
    program1->send(program2, MessageType::WARNING);
    program1->send(program2);
    program2->send(program1);
    std::cout << *program1 <<std::endl << *program2 << std::endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}

