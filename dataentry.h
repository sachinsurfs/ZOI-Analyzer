#ifndef DATAENTRY_H
#define DATAENTRY_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include "sys/types.h"
#include "QLabel"
#include "QHBoxLayout"
#include "QComboBox"

namespace Ui {
class DataEntry;
}

class DataEntry : public QMainWindow
{
    Q_OBJECT

public:
    explicit DataEntry(QWidget *parent = 0,QString s=NULL);
    ~DataEntry();
    QSqlDatabase db;
    QString fileName;
    QLabel *t[50];
    QHBoxLayout *h[50];
    QComboBox *c[50];
    int count;
    bool flag;
    void clearLayout(QLayout*, bool);
    void decide(struct point [],int);
    int imgNum();


private slots:

    void on_backb_clicked();

    void on_nextb_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::DataEntry *ui;
};

#endif // DATAENTRY_H
