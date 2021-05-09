#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../Computer-network/servers.h"
#include "../Computer-network/program_registry.h"
#include "programbuilderwindow.h"
#include "programwindow.h"
#include <QTreeWidget>
#include <QInputDialog>
#include <QDir>
#include "serverwindow.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonAddServer_clicked();

    void on_pushButtonAddProgram_clicked();

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_pushButtonRemoveServer_clicked();

    void on_pushButtonRemoveProgram_clicked();

    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void on_pushButtonClearServer_clicked();

    void on_pushButtonRemoveAllServers_clicked();

private:
    Ui::MainWindow *ui;
    cn::ProgramRegistry registry;
    QVector<QString> textes;
    QString app_name;
    QString path;
    QString folder_name;
    QMap<QString, QMap<QString, std::shared_ptr<ProgramWindow>>> program_windows;//first key - server name, second - program name
    void set_folder();
    void read_servers_from_file();
    void set_registry();
    void set_textes();
    void server_is_selected(bool answer);
    void program_is_selected(bool answer);
    bool is_server(QTreeWidgetItem *item);
    void close_deleted_window(const QString& server_name);
    void after_removing();
    void remove_all_servers();
    QTreeWidgetItem* add_server_to_tree(const QString& name);
    void add_program_to_tree(QTreeWidgetItem* server_item, const QString& program_name);
};
#endif // MAINWINDOW_H
