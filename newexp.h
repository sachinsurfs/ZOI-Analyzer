#ifndef NEWEXP_H
#define NEWEXP_H

#include <QMainWindow>
#include "cv.h"
#include "highgui.h"

namespace Ui {
class NewExp;
}

class NewExp : public QMainWindow
{
    Q_OBJECT

public:
    explicit NewExp(QWidget *parent = 0);
    ~NewExp();
    QString fileName=NULL;
    bool flag;
    CvCapture* capture;
    IplImage* frame;
    QImage qimg;
    QImage IplImage2QImage(const IplImage *);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::NewExp *ui;
};

#endif // NEWEXP_H
