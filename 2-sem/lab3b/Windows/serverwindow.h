#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <QDialog>
#include "Computer-network/servers.h"
#include "app_messages.h"
namespace Ui {
class ServerWindow;
}
/*!
*   \brief Window to build server
*/
class ServerWindow : public QDialog
{
    Q_OBJECT

public:
    /*!
    *   \brief Parametrized constructor
    *   \param server_name - reference to name of server
    *   \param is_added - true is server was added else false
    */
    explicit ServerWindow(QString& server_name,bool& is_added, QWidget *parent = nullptr);
    ~ServerWindow();

private slots:
    void on_pushButtonCreate_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::ServerWindow *ui;
    QString& server_name;
    bool& is_added;
};

#endif // SERVERWINDOW_H
