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
    registry.registry_type(std::make_shared<cn::PeriodicProgram>(textes));
    registry.registry_type(std::make_shared<cn::RandomProgram>(textes));
    registry.registry_type(std::make_shared<cn::AfterProgram>(textes));
    registry.registry_type(std::make_shared<cn::WaitProgram>(textes));
}
MainWindow::~MainWindow()
{
    program_windows.clear();
    cn::Servers::clear();
    delete ui;
}


void MainWindow::on_pushButtonAddServer_clicked()
{
    QString text = QInputDialog::getText(this, "Create server", "Enter a server name");
    if(text.isEmpty()) return;
    if(cn::Servers::get_server(text))
    {
        AppMessages::error_message(this,"CNM","The server " + text+" has already been created!");
        return;
    }
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
        bool is_added = false;
        QString program_name = "";
        ProgramBuilderWindow window(registry, server,is_added,program_name, this);
        window.exec();
        if(!is_added) return;
        auto new_item = new QTreeWidgetItem(item);
        new_item->setText(0, program_name);
        ui->treeWidget->addTopLevelItem(new_item);
        program_windows[server->get_name()][program_name] =
                std::make_shared<ProgramWindow>(server->get_program(program_name));
    }
}

void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    if(is_server(item))
    {
        server_is_selected(true);
        program_is_selected(false);
    }
    else
    {
        server_is_selected(false);
        program_is_selected(true);
    }

}
void MainWindow::server_is_selected(bool answer)
{
    ui->pushButtonAddProgram->setEnabled(answer);
    ui->pushButtonRemoveServer->setEnabled(answer);
    ui->pushButtonClearServer->setEnabled(answer);
}
void MainWindow::program_is_selected(bool answer)
{
    ui->pushButtonRemoveProgram->setEnabled(answer);
}
void MainWindow::close_deleted_window(const QString& server_name)
{
    if(program_windows.contains(server_name))
    {
        program_windows[server_name].clear();
    }
}
void MainWindow::on_pushButtonRemoveServer_clicked()
{
    auto items = ui->treeWidget->selectedItems();
    if(items.size() == 1 &&
            is_server(items[0]))
    {
        bool answer = AppMessages::question_message(this,
                                      "Removing",
                                      "Do you realy want to remove server "+items[0]->text(0)+" ?");
        if(answer)
        {
            close_deleted_window(items[0]->text(0));
            cn::Servers::remove_server(items[0]->text(0));
            delete items[0];
            after_removing();
        }
    }
}

void MainWindow::on_pushButtonRemoveProgram_clicked()
{
    auto items = ui->treeWidget->selectedItems();
    if(items.size() == 1 &&
            !is_server(items[0])&&
            program_windows.contains(items[0]->parent()->text(0))&&
            program_windows[items[0]->parent()->text(0)].contains(items[0]->text(0)))
    {
        bool answer = AppMessages::question_message(this,
                                      "Removing",
                                      "Do you realy want to remove program "+items[0]->text(0)+" ?");
        if(answer)
        {
            program_windows[items[0]->parent()->text(0)][items[0]->text(0)] = nullptr;
            cn::Servers::get_server(items[0]->parent()->text(0))->remove_program(items[0]->text(0));
            delete items[0];
            after_removing();
        }
    }
}
void MainWindow::after_removing()
{
    program_is_selected(false);
    server_is_selected(false);
    ui->treeWidget->clearSelection();
}
bool MainWindow::is_server(QTreeWidgetItem *item)
{
    return (item->parent() == nullptr);
}
void MainWindow::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    if(!is_server(item))
    {
        QString name = item->text(column);
        if(program_windows.contains(item->parent()->text(0))&&
                program_windows[item->parent()->text(0)].contains(name))
        {
            server_is_selected(false);
            program_is_selected(true);
            program_windows[item->parent()->text(0)][name]->show();
        }
    }
}

void MainWindow::on_pushButtonClearServer_clicked()
{
    auto items = ui->treeWidget->selectedItems();
    if(items.size() == 1 &&
            is_server(items[0]))
    {
        bool answer = AppMessages::question_message(this,
                                      "Clearing",
                                      "Do you realy want to clear server "+items[0]->text(0)+" ?"+
                                      "\nAll programs in this server will be removed!");
        if(answer)
        {
            close_deleted_window(items[0]->text(0));
            int size = items[0]->childCount();
            for(int i = 0; i < size;i++)
            {
                items[0]->removeChild(items[0]->child(0));
            }
            cn::Servers::get_server(items[0]->text(0))->clear();
        }
    }
}

void MainWindow::on_pushButtonRemoveAllServers_clicked()
{
    bool answer = AppMessages::question_message(this,
                                  "Removing",
                                  "Do you realy want to remove all servers?");
    if(answer)
    {
        program_windows.clear();
        ui->treeWidget->clear();
        cn::Servers::clear();
        after_removing();
    }
}
