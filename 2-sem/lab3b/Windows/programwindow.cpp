#include "programwindow.h"
#include "ui_programwindow.h"

ProgramWindow::ProgramWindow(std::shared_ptr<cn::BasicProgram> program, bool& is_paused,
                             QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProgramWindow),program(program), timer(nullptr),
    model(std::make_shared<QStandardItemModel>()), view(nullptr),old_size(0),
    message_window(std::make_shared<MessageTextWindow>()),is_stop(false),is_paused(is_paused)
{
    ui->setupUi(this);
    if(program)
    {
        setWindowTitle(program->get_info().get_string());
        QIcon icon("Images/program-window-icon.ico");
        setWindowIcon(icon);
        set_data();
        set_timer();
        set_model();
        th = std::thread([&](){send_messages();});
        th.detach();
    }
}
void ProgramWindow::set_model()
{
    ui->tableViewBuffer->setModel(model.get());
    ui->tableViewBuffer->setEditTriggers(QAbstractItemView::NoEditTriggers);
    view = MyViewModel(model);
    ui->tableViewBuffer->setColumnWidth(model->columnCount() - 1, 200);
}
void ProgramWindow::set_timer()
{
    timer = std::make_shared<QTimer>(this);
    connect(timer.get(), &QTimer::timeout, this, &ProgramWindow::receive_messages);
    timer->start(200);
}

ProgramWindow::~ProgramWindow()
{
    timer->stop();
    is_stop = true;
    delete ui;
}
void ProgramWindow::set_data()
{
    ui->labelName->setText(program->get_info().program_name);
    ui->labelType->setText(cn::program_type_to_string(program->get_type()));
    ui->labelSendingType->setText(program->get_sending_type());
    ui->labelPeriod->setText(QString::number(program->get_period())+"ms");
}
void ProgramWindow::add_message_to_view(const Message& message)
{
    view.add_message(message);
}
void ProgramWindow::send_messages()
{
    while (true)
    {
       for(std::size_t i = 0; i < program->get_period();i++)
        if(!is_stop) std::this_thread::sleep_for(std::chrono::milliseconds(1));
       else return;
       if(is_paused) continue;
       if(program) program->update();
    }
}
void ProgramWindow::receive_messages()
{
    if(is_paused) return;
    if(!program) return;
    auto messages = program->get_messages();
    if(old_size == messages.size()) return;
    for(std::size_t i = 0; i < messages.size() - old_size; i++)
        add_message_to_view(messages[i + old_size]);
    if(!ui->checkBoxFixedPosition->isChecked()) ui->tableViewBuffer->scrollToBottom();
    old_size = messages.size();
}

void ProgramWindow::on_pushButtonClear_clicked()
{
    bool answer = AppMessages::question_message(this,
                                  "Clearing",
                                  "Do you realy want to clear all messages?");
    if(answer)
    {
        view.clear();
        program->clear_buffer();
        old_size = 0;
        ui->tableViewBuffer->setColumnWidth(model->columnCount() - 1, 200);
        message_window->hide();
    }
}

void ProgramWindow::on_tableViewBuffer_doubleClicked(const QModelIndex &index)
{
    auto messages = program->get_messages();
    if(index.row() < messages.size()) message_window->set_message(messages[index.row()]);
    message_window->hide();
    message_window->show();
}
