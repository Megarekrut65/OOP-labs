#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../Computer-network/servers.h"
#include "../Computer-network/program_registry.h"
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

private:
    Ui::MainWindow *ui;
    cn::ProgramRegistry registry;
    QVector<QString> textes;
    QString app_name;
    void set_registry();
    void set_textes();
    void server_is_selected(bool answer);
    void program_is_selected(bool answer);
};
#endif // MAINWINDOW_H
