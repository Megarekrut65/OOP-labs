#include "findtypetimewindow.h"
#include "ui_findtypetimewindow.h"

FindTypeTimeWindow::FindTypeTimeWindow(std::shared_ptr<OpeningMode> open_mode, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindTypeTimeWindow),open_mode(open_mode)
{
    ui->setupUi(this);
    this->setWindowTitle("Find by type and time");
    if(!open_mode) this->close();
    QIcon icon("images/find.ico");
    this->setWindowIcon(icon);
}

FindTypeTimeWindow::~FindTypeTimeWindow()
{
    delete ui;
}
AttackTypes FindTypeTimeWindow::get_type()
{
    if(ui->radioButtonRepeat->isChecked()) return AttackTypes::REPEAT;
    if(ui->radioButtonCure->isChecked()) return AttackTypes::CURE;
    if(ui->radioButtonParalize->isChecked()) return AttackTypes::PARALYZE;

    return AttackTypes::INCREASE;
}
std::vector<int> FindTypeTimeWindow::get_time()
{
    QDateTime date_time = ui->dateTimeEdit->dateTime();
    return {date_time.date().year(),
            date_time.date().month(),
            date_time.date().day(),
            date_time.time().hour(),
            date_time.time().minute(),
            date_time.time().second()};
}
void FindTypeTimeWindow::on_pushButtonOK_clicked()
{
    ShowMonsters show(open_mode->find_types_time(get_type(),get_time()));
    show.setModal(true);
    this->hide();
    show.exec();
    this->close();
}

void FindTypeTimeWindow::on_pushButtonCancel_clicked()
{
    this->close();
}
