#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),app_name("Computer network model")
{
    ui->setupUi(this);
    srand(time(0));
    set_registry();
    set_textes();
    setWindowTitle(app_name);
    QIcon icon("Images/main-icon.ico");
    setWindowIcon(icon);
    server_is_selected(false);
    program_is_selected(false);
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


void MainWindow::on_pushButtonAddServer_clicked()
{
    QString text = QInputDialog::getText(this, "Create server", "Enter a server name");
    if(text.isEmpty()) return;
    if(cn::Servers::get_server(text)) return;
    auto item = new QTreeWidgetItem(ui->treeWidget);
    item->setText(0,text);
    ui->treeWidget->addTopLevelItem(item);
    cn::Servers::add_server(std::make_shared<cn::BasicServer>(text));
}

void MainWindow::on_pushButtonAddProgram_clicked()
{
    auto items = ui->treeWidget->selectedItems();
    if(items.size() == 1)
    {
        auto item = items[0];
        auto server = cn::Servers::get_server(item->text(0));
        if(!server) return;
        QString text = QInputDialog::getText(this, "Create program", "Enter a program name");
        if(text.isEmpty()) return;
        if(server->get_program(text)) return;
        auto new_item = new QTreeWidgetItem(item);
        new_item->setText(0,text);
        ui->treeWidget->addTopLevelItem(new_item);
        server->add_program(text,registry.get_prototype("RandomProgram"));
    }
}

void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    auto server = cn::Servers::get_server(item->text(column));
    if(server)
    {
        server_is_selected(true);
        program_is_selected(false);
    }
    else
    {
        server_is_selected(false);
        auto parent_server = cn::Servers::get_server(item->parent()->text(column));
        auto program = parent_server->get_program(item->text(column));
        if(program) program_is_selected(true);
        else program_is_selected(false);
    }

}
void MainWindow::server_is_selected(bool answer)
{
    ui->pushButtonAddProgram->setEnabled(answer);
    ui->pushButtonRemoveServer->setEnabled(answer);
}

void MainWindow::on_pushButtonRemoveServer_clicked()
{

}

void MainWindow::on_pushButtonRemoveProgram_clicked()
{

}
void MainWindow::program_is_selected(bool answer)
{
    ui->pushButtonRemoveProgram->setEnabled(answer);
}
