#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <QDialog>
#include "Computer-network/servers.h"
#include "app_messages.h"
namespace Ui {
/*!
*   \brief
*/
class ServerWindow;
}

class ServerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ServerWindow(QString& server_name,bool& is_added, QWidget *parent = nullptr);
    ~ServerWindow();

private slots:
    void on_pushButtonCreate_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::ServerWindow *ui;/*!< */
    QString& server_name;/*!< */
    bool& is_added;/*!< */
};

#endif // SERVERWINDOW_H
