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
namespace Ui {
class MainWindow; }
QT_END_NAMESPACE
/*!
*   \brief Main window for server management
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
    *   \brief Sets all parameters and settings
    */
    MainWindow(QWidget *parent = nullptr);
    /*!
    *   \brief Clears all servers from memory
    */
    ~MainWindow();

private slots:
    /*!
    *   \brief Adds server to tree widget
    */
    void on_pushButtonAddServer_clicked();
    /*!
    *   \brief Adds program to selected server
    */
    void on_pushButtonAddProgram_clicked();
    /*!
    *   \brief Hides and shows buttons to work with program or server
    */
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);
    /*!
    *   \brief Removes selected server from tree widget
    */
    void on_pushButtonRemoveServer_clicked();
    /*!
    *   \brief Removes selected program from tree widget
    */
    void on_pushButtonRemoveProgram_clicked();
    /*!
    *   \brief If item is program than open program window
    */
    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);
    /*!
    *   \brief Removes all programs from selected server
    */
    void on_pushButtonClearServer_clicked();
    /*!
    *   \brief Removes all servers from tree widget
    */
    void on_pushButtonRemoveAllServers_clicked();
    /*!
    *   \brief Starts of pauses computer network simulation
    */
    void on_pushButtonSimulation_clicked();
    /*!
    *   \brief Opens window with information about server
    */
    void on_pushButtonServerInfo_clicked();
    /*!
    *   \brief Opens window with information about program
    */
    void on_pushButtonProgramInfo_clicked();
    /*!
    *   \brief Edits acceleration factor
    */
    void on_pushButtonSetFactor_clicked();

private:
    Ui::MainWindow *ui;/*!< Pointer to all ui */
    cnm::ProgramRegistry registry;/*!< Registry to add and get program prototypes */
    QVector<QString> textes;/*!< List with phrases */
    QString app_name;/*!< Name of this application */
    QString servers_path;/*!< Path to file with servers names */
    QString textes_path;/*!< Path to file with phrases */
    QString setting_path;/*!< Path to file with settings */
    QString folder_name;/*!< Name of folder where are all data files*/
    QMap<QString, QMap<QString, std::shared_ptr<ProgramWindow>>> program_windows;/*! Map to get pointer to info window of program by server and programs names. <*/
    bool is_paused;/*!< If simulation is paused than it will be true else false */
    QColor server_color;/*!< Color of servert item in tree widget */
    std::shared_ptr<QTimer> bar_animation_timer;/*!< Timer for play animation of progress bar */
    ProgressBarAnimation animation;/*!< Class with animation of progress bar */
    std::shared_ptr<ServerInfoWindow> server_info_window;/*!< Pointer to window with information about selected server */
    /*!
    *   \brief Opens window with information about server
    */
    void show_server(std::shared_ptr<cnm::BasicServer> server);
    /*!
    *   \brief Opens window with information about program
    */
    void show_program(std::shared_ptr<cnm::BasicProgram> program);
    /*!
    *   \brief Sets all animation timer parameters
    */
    void set_timer();
    /*!
    *   \brief set acceleration factor parameters
    */
    void set_factor();
    /*!
    *   \brief Calls bar animation
    */
    void bar_animation();
    /*!
    *   \brief Creates folder if it is not exist
    */
    void set_folder();
    /*!
    *   \brief Adds all servers from file to tree widget
    */
    void read_servers_from_file();
    /*!
    *   \brief Sets all types of program
    */
    void set_registry();
    /*!
    *   \brief Reads phrases from file
    */
    void set_textes();
    /*!
    *   \brief Shows/Hides buttons if server is selected/not
    */
    void server_is_selected(bool answer);
    /*!
    *   \brief Shows/Hides buttons if program is selected/not
    */
    void program_is_selected(bool answer);
    /*!
    *   \brief Returns true if item is server
    *   \param item - pointer to item in tree widget
    */
    bool is_server(QTreeWidgetItem *item);
    /*!
    *   \brief Closes all program windows after removing server
    */
    void close_deleted_window(const QString& server_name);
    /*!
    *   \brief Sets tree widget parameters after removing servers or programs
    */
    void after_removing();
    /*!
    *   \brief Removes all servers from tree widget
    */
    void remove_all_servers();
    /*!
    *   \brief Adds server to tree
    *
    *   \param name - name of server
    *   \returns - pointer to new item if server was created
    *   \returns - nullptr else
    */
    QTreeWidgetItem* add_server_to_tree(const QString& name);
    /*!
    *   \brief Adds program to tree
    *
    *   \param server_item - item of server of program
    *   \param program_name - name of new program
    */
    void add_program_to_tree(QTreeWidgetItem* server_item, const QString& program_name);
};
#endif // MAINWINDOW_H
