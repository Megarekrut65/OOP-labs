#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QInputDialog>
#include <QDir>
#include "../Computer-network/servers.h"
#include "../Computer-network/program_registry.h"
#include "programbuilderwindow.h"
#include "programwindow.h"
#include "serverinfowindow.h"
#include "serverwindow.h"
#include "progress_bar_animation.h"

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

    void on_pushButtonSimulation_clicked();

    void on_pushButtonServerInfo_clicked();

    void on_pushButtonProgramInfo_clicked();

private:
    Ui::MainWindow *ui;
    cn::ProgramRegistry registry;
    QVector<QString> textes;
    QString app_name;
    QString servers_path;
    QString textes_path;
    QString folder_name;
    QMap<QString, QMap<QString, std::shared_ptr<ProgramWindow>>> program_windows;//first key - server name, second - program name
    bool is_paused;
    QColor server_color;
    std::shared_ptr<QTimer> bar_animation_timer;
    ProgressBarAnimation animation;
    std::shared_ptr<ServerInfoWindow> server_info_window;
    void show_server(std::shared_ptr<cn::BasicServer> server);
    void show_program(std::shared_ptr<cn::BasicProgram> program);
    void set_timer();
    void bar_animation();
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
