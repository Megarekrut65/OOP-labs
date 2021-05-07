#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../Computer-network/servers.h"
#include "../Computer-network/program_registry.h"
#include "programbuilderwindow.h"
#include "programwindow.h"
#include <QTreeWidget>
#include <QInputDialog>
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
    QMap<QString, QMap<QString, std::shared_ptr<ProgramWindow>>> program_windows;//first key - server name, second - program name
    void set_registry();
    void set_textes();
    void server_is_selected(bool answer);
    void program_is_selected(bool answer);
    bool is_server(QTreeWidgetItem *item);
    void close_deleted_window(const QString& server_name);
    void after_removing();
};
#endif // MAINWINDOW_H
