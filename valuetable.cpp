#include "valuetable.h"
#include "ui_valuetable.h"
#include "QLabel"
#include "QGridLayout"
ValueTable::ValueTable(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ValueTable)
{
    ui->setupUi(this);
    QLabel* CAM111 = new QLabel("QLabel CAM 01");
    QLabel* CAM121 = new QLabel("QLabel CAM 02");
    QLabel* CAM131 = new QLabel("QLabel CAM 03");

    QLabel* CAM211 = new QLabel("QLabel CAM 04");
    QLabel* CAM221 = new QLabel("QLabel CAM 05");
    QLabel* CAM231 = new QLabel("QLabel CAM 06");

    QLabel* CAM311 = new QLabel("QLabel CAM 07");
    QLabel* CAM321 = new QLabel("QLabel CAM 08");
    QLabel* CAM331 = new QLabel("QLabel CAM 09");

    CAM111->setFixedSize(100,100);
    CAM121->setFixedSize(10,10);
    CAM131->setFixedSize(10,10);
    CAM211->setFixedSize(10,10);
    CAM221->setFixedSize(10,10);
    CAM231->setFixedSize(10,10);
    CAM311->setFixedSize(10,10);
    CAM321->setFixedSize(10,10);
    CAM331->setFixedSize(10,10);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(CAM111,0,0);
    //layout->addWidget(CAM121,0,1);
    //layout->addWidget(CAM131,0,2);

    layout->addWidget(CAM211,1,0);
   // layout->addWidget(CAM221,1,1);
    //layout->addWidget(CAM231,1,2);

    layout->addWidget(CAM311,2,0);
    //layout->addWidget(CAM321,2,1);
    //layout->addWidget(CAM331,2,2);

    setLayout(layout);
setWindowTitle("Camera Window");
    setFixedSize(1000, 800);
}

ValueTable::~ValueTable()
{
    delete ui;
}
