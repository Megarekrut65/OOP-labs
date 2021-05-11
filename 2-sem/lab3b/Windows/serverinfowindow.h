#ifndef SERVERINFOWINDOW_H
#define SERVERINFOWINDOW_H

#include <QDialog>
#include "Computer-network/basic_server.h"
namespace Ui {

class ServerInfoWindow;
}
/*!
*   \brief Window to show information about server
*/
class ServerInfoWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ServerInfoWindow(QWidget *parent = nullptr);
    ~ServerInfoWindow();
    /*!
    *   \brief Adds server information to labels
    */
    void set_data(std::shared_ptr<cnm::BasicServer> server);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ServerInfoWindow *ui;
};

#endif // SERVERINFOWINDOW_H
