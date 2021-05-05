#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(0));
    std::shared_ptr<cn::BasicServer> server1 = std::make_shared<cn::BasicServer>("uk"),
            server2= std::make_shared<cn::BasicServer>("ukraine"),
            server3= std::make_shared<cn::BasicServer>("germany");
    server1->create_new_periodic_program(cn::ProgramType::ALL, "Google Drive", 10);
    server1->create_new_wait_program(cn::ProgramType::ALL, "Telegram", 12);
    server2->create_new_after_program(cn::ProgramType::ALL,"Instagram",1);
    server3->create_new_random_program(cn::ProgramType::ALL,"Contacts",9);
    cn::Servers::add_server(server1);
    cn::Servers::add_server(server2);
    cn::Servers::add_server(server3);
    std::cout << cn::Servers::get_server("ukraine")->get_name() << std::endl;

}

MainWindow::~MainWindow()
{
    delete ui;
}

