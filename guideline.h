#ifndef GUIDELINE_H
#define GUIDELINE_H
#include <QtSql/QSqlDatabase>
#include <QMainWindow>
#include <QAbstractButton>
#include "sys/types.h"
#include "mainwindow.h"


namespace Ui {
class Guideline;
}

class Guideline : public QMainWindow
{
    Q_OBJECT

public:
    explicit Guideline(QWidget *parent = 0);
    ~Guideline();
     QSqlDatabase db;
     int cflag;
     const QString arg;
     //QSqlQuery query;
private slots:

    
    void on_comboBox_currentTextChanged(const QString &arg1);
    void on_buttonBox_clicked(QAbstractButton *button);

    void on_comboBox_2_currentTextChanged(const QString &arg1);

private:
    Ui::Guideline *ui;
    //MainWindow *m;
};

#endif // GUIDELINE_H
