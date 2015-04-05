#include "errordialog.h"
#include "ui_errordialog.h"
#include "newexp.h"

errorDialog::errorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::errorDialog)
{
    ui->setupUi(this);
    ui->label_2->setPixmap(QPixmap("/home/sachin/test2/new/error2.png"));
    ui->label_2->setScaledContents( true );
    ui->label_2->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}

errorDialog::~errorDialog()
{
    delete ui;
}

void errorDialog::on_buttonBox_accepted()
{
    NewExp *n=new NewExp(this);
    n->show();
    this->destroy();
}
