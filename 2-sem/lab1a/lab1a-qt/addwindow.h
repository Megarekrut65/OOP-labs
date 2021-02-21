#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QDialog>
#include "Code/monster.h"
#include "Code/memory_opening_mode.h"
#include "Code/file_opening_mode.h"
#include <memory>
#include <QString>
#include <QMessageBox>

using namespace mon;
using namespace mmode;
using namespace fmode;
using namespace om;
namespace Ui {
class AddWindow;
}

class AddWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddWindow(QWidget *parent = nullptr,
                       std::shared_ptr<OpeningMode> open_mode = nullptr,
                       std::shared_ptr<Monster> monster = nullptr, bool edit = false);
    ~AddWindow();

private slots:
    void on_pushButtonSave_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::AddWindow *ui;
    std::shared_ptr<Monster> monster;
    std::shared_ptr<OpeningMode> open_mode;
    bool edit;
    AttackTypes get_type();
    void edit_monster();
    void set_data();
    void add_monster();
    bool check_empty();
    bool is_empty();
};

#endif // ADDWINDOW_H
