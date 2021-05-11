#ifndef PROGRAMBUILDERWINDOW_H
#define PROGRAMBUILDERWINDOW_H

#include <QDialog>
#include "../Computer-network/basic_server.h"
#include "../Computer-network/program_registry.h"
#include "app_messages.h"

namespace Ui {
class ProgramBuilderWindow;
}
/*!
*   \brief
*/
class ProgramBuilderWindow : public QDialog
{
    Q_OBJECT

public:
    /*!
    *   \brief
    */
    explicit ProgramBuilderWindow(
            cnm::ProgramRegistry& registry,
            std::shared_ptr<cnm::BasicServer> server,
            bool& is_added,
            QString& program_name,
            QWidget *parent = nullptr);
    /*!
    *   \brief
    */
    ~ProgramBuilderWindow();

private slots:
    /*!
    *   \brief
    */
    void on_pushButtonCreate_clicked();
    /*!
    *   \brief
    */
    void on_pushButtonCancel_clicked();

private:
    Ui::ProgramBuilderWindow *ui;/*!< */
    cnm::ProgramRegistry& registry;/*!< */
    bool& is_added;/*!< */
    QString& program_name;/*!< */
    std::shared_ptr<cnm::BasicServer> server;/*!< */
    /*!
    *   \brief
    */
    void set_sending_types();
    /*!
    *   \brief
    */
    cnm::ProgramType get_type();
    /*!
    *   \brief
    */
    QString get_name();
    /*!
    *   \brief
    */
    std::size_t get_period();
};

#endif // PROGRAMBUILDERWINDOW_H
