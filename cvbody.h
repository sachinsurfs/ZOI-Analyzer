#ifndef CVBODY_H
#define CVBODY_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include "sys/types.h"

namespace Ui {
class CvBody;
}

class CvBody : public QMainWindow
{
    Q_OBJECT

public:
    explicit CvBody(QWidget *parent = 0);
    ~CvBody();
    QSqlDatabase db;
    int cvMethod(QString s=NULL,QString *s1=NULL,int size=0);
    void decide(struct point [],int);

private:
    Ui::CvBody *ui;
};

#endif // CVBODY_H
