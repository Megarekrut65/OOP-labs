#ifndef ADDINGTIMER_H
#define ADDINGTIMER_H

#include <QDialog>
#include "mytimer.h"
#include <QStandardItemModel>
#include "my_sounds.h"

namespace Ui {
class AddingTimer;
}

class AddingTimer : public QDialog
{
    Q_OBJECT

public:
    explicit AddingTimer( QVector<MyTimer*>* timers = nullptr,
    QStandardItemModel *model = nullptr, QWidget *parent = nullptr);
    ~AddingTimer();

private slots:
    void on_btnCreate_clicked();

    void on_btnCancel_clicked();

    void on_seletcSound_activated(const QString &arg1);

private:
    Ui::AddingTimer *ui;
    QVector<MyTimer*>* timers;
    QStandardItemModel *model;
    Type set_type();
    void add_sounds();
};

#endif // ADDINGTIMER_H
