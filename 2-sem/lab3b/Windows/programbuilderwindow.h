#ifndef PROGRAMBUILDERWINDOW_H
#define PROGRAMBUILDERWINDOW_H

#include <QDialog>
#include "../Computer-network/basic_server.h"
#include "../Computer-network/program_registry.h"
#include "app_messages.h"

namespace Ui {
class ProgramBuilderWindow;
}

class ProgramBuilderWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ProgramBuilderWindow(
            cn::ProgramRegistry& registry,
            std::shared_ptr<cn::BasicServer> server,
            bool& is_added,
            QString& program_name,
            QWidget *parent = nullptr);
    ~ProgramBuilderWindow();

private slots:
    void on_pushButtonCreate_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::ProgramBuilderWindow *ui;
    cn::ProgramRegistry& registry;
    bool& is_added;
    QString& program_name;
    std::shared_ptr<cn::BasicServer> server;
    void set_sending_types();
    cn::ProgramType get_type();
    QString get_name();
    std::size_t get_period();
};

#endif // PROGRAMBUILDERWINDOW_H
