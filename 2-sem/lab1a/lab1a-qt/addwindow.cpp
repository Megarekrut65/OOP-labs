#include "addwindow.h"
#include "ui_addwindow.h"

AddWindow::AddWindow(QWidget *parent, QStandardItemModel* model,
                     std::shared_ptr<OpeningMode> open_mode,
                     std::shared_ptr<Monster> monster, bool edit) :
    QDialog(parent),
    ui(new Ui::AddWindow), model(model), monster(monster), open_mode(open_mode),
    edit(edit)
{
    ui->setupUi(this);
    if(!open_mode ||!model||(edit && !monster)) this->close();
    this->setWindowTitle("Edit the monster");
    if(edit) set_data();
    else this->setWindowTitle("Create new monster");
}

AddWindow::~AddWindow()
{
    model = nullptr;
    open_mode = nullptr;
    monster = nullptr;
    delete ui;
}
AttackTypes AddWindow::get_type()
{
    if(ui->radioButtonRepeat->isChecked()) return AttackTypes::REPEAT;
    if(ui->radioButtonCure->isChecked()) return AttackTypes::CURE;
    if(ui->radioButtonParalize->isChecked()) return AttackTypes::PARALYZE;

    return AttackTypes::INCREASE;
}
void AddWindow::on_pushButtonSave_clicked()
{
    if(check_empty()) return;
    if(edit) edit_monster();
    else add_monster();
    this->close();
}
void AddWindow::set_data()
{
    ui->lineEditName->setText(monster->get_name().c_str());
    ui->spinBoxHP->setValue(monster->get_hp());
    ui->spinBoxDamage->setValue(monster->get_damage());
    ui->spinBoxChance->setValue(monster->get_chance());
    switch (monster->get_type())
    {
    case AttackTypes::INCREASE: ui->radioButtonIncrease->setChecked(true);
        break;
    case AttackTypes::REPEAT: ui->radioButtonRepeat->setChecked(true);
        break;
    case AttackTypes::CURE: ui->radioButtonCure->setChecked(true);
        break;
    case AttackTypes::PARALYZE: ui->radioButtonParalize->setChecked(true);
        break;
    }
}
void AddWindow::edit_monster()
{
    monster->set_name(ui->lineEditName->text().toStdString());
    monster->set_hp(ui->spinBoxHP->value());
    monster->set_damage(ui->spinBoxDamage->value());
    monster->set_chance(ui->spinBoxChance->value());
    monster->set_type(get_type());
    open_mode->save_edited_monster(*monster);
    ModelFunctions::edit_monster_in_table(model, monster);
}
void AddWindow::add_monster()
{
    Monster new_monster = Monster(ui->lineEditName->text().toStdString(),
                                        ui->spinBoxHP->value(),
                                        ui->spinBoxDamage->value(),
                                        ui->spinBoxChance->value(),
                                        get_type(),
                                        open_mode->get_time_now(),
                                        open_mode->get_id());
    open_mode->append_monster(new_monster);
    ModelFunctions::add_monster_to_table(model, std::make_shared<Monster>(new_monster));
}
bool AddWindow::is_empty()
{
    if(ui->lineEditName->text().size() == 0) return true;
    if(ui->spinBoxHP->text().size() == 0) return true;
    if(ui->spinBoxDamage->text().size() == 0) return true;
    if(ui->spinBoxChance->text().size() == 0) return true;
    return false;
}
bool AddWindow::check_empty()
{
    if(is_empty())
    {
        MyMessage::error_message(this, "Error","There is empty field!");
        return true;
    }
    return false;
}
void AddWindow::on_pushButtonCancel_clicked()
{
    this->close();
}
