#include "mainwindow.h"
#include "guideline.h"
#include "ui_guideline.h"
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QRadioButton>
#include <QPushButton>



QString bact,a_agent;
Guideline::Guideline(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Guideline)
{
    ui->setupUi(this);
    ui->label_2->hide();
    cflag=0;
    /*DataBase Connection*/
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("CLSI");
    db.setUserName("root");
    db.setPassword("root");
    bool ok=db.open();
    QSqlQuery query;
    query.exec("select  distinct AntiMicrobialAgent from ZOI");
    ui->comboBox->addItem("");
    while (query.next()) {
        QString name = query.value(0).toString();
        ui->comboBox->addItem(name);
    }
}

Guideline::~Guideline()
{
    delete ui;
}


void Guideline::on_comboBox_currentTextChanged(const QString &arg1)
{

    a_agent=arg1;
    if(cflag<1)
        cflag++;
    else if(cflag==1)
    {
        this->setFixedHeight(this->height()*1.5);
        cflag++;
    }
    if(!arg1.compare(""))
    {
        cflag=1;
        this->setFixedHeight(this->height()/1.5);
    }
    QSqlQuery q2;
    q2.exec("select  distinct TestB from ZOI where AntiMicrobialAgent='"+arg1+"'");
    ui->comboBox_2->clear();
    ui->comboBox_2->addItem("");
    while (q2.next()) {
        QString name = q2.value(0).toString();
                ui->comboBox_2->addItem(name);
    }
    QRadioButton *r1;
   // ui->verticalLayout->addWidget(r1);






}

void Guideline::on_buttonBox_clicked(QAbstractButton *button)
{
           MainWindow *m=new MainWindow(this);
            m->show();
            this->destroy();
}

void Guideline::on_comboBox_2_currentTextChanged(const QString &arg2)
{
    bact=arg2;
    QSqlQuery q3;
    q3.exec("select DiscContent from ZOI where AntiMicrobialAgent='"+a_agent+"' and TestB='"+arg2+"'");
    while (q3.next()) {
        QString value = q3.value(0).toString();
                ui->label_2->setText("You must use "+value+" mg.");
                ui->label_2->show();
 }


}
