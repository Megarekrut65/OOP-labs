#ifndef PROGRAMWINDOW_H
#define PROGRAMWINDOW_H

#include <QDialog>
#include "../Computer-network/servers.h"
#include <QTimer>
#include "my_view_model.h"
#include "app_messages.h"
#include "messagetextwindow.h"

namespace Ui {
class ProgramWindow;
}
/*!
*   \brief Window to show information about program
*/
class ProgramWindow : public QDialog
{
    Q_OBJECT

public:
    /*!
    *   \brief Adds program information to labels
    */
    explicit ProgramWindow(std::shared_ptr<cnm::BasicProgram> program,
                           bool& is_paused, QWidget *parent = nullptr);
    ~ProgramWindow();

private slots:

    void on_pushButtonClear_clicked();

    void on_tableViewBuffer_doubleClicked(const QModelIndex &index);

private:
    Ui::ProgramWindow *ui;
    std::shared_ptr<cnm::BasicProgram> program;
    std::shared_ptr<QTimer> timer;
    std::shared_ptr<QStandardItemModel> model;
    MyViewModel view;
    std::size_t old_size;
    std::shared_ptr<MessageTextWindow> message_window;
    std::thread th;
    bool is_stop;
    bool& is_paused;
    void set_data();
    void set_messages_info();
    void set_timer();
    void receive_messages();
    void send_messages();
    void add_message_to_view(const cnm::Message& message);
    void set_model();
};

#endif // PROGRAMWINDOW_H
