#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(0));
    Message message(ProgramInfo("bolivia", "Zoom"),
                    "Hello, everyone!",
                    MessageType::INFO, ProgramInfo("ukraine","Discord"), 3454353);
    std::cout << message << std::endl;
    QVector<QString> textes = {
        "Hello, wold!",
        "How are you doing?",
        "Mama Mia!",
        "Guten Tag!",
        "Are you creizy?"};
    std::shared_ptr<cn::Program> program1 = std::make_shared<cn::Program>(textes, ProgramInfo("ukraine","Google Drive")),
            program2 = std::make_shared<cn::Program>(textes, ProgramInfo("uk", "YouTube"));
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

