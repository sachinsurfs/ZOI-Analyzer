#include "newexp.h"
#include "ui_newexp.h"
#include "QFileDialog"
#include "errordialog.h"
#include "dataentry.h"
#include "cv.h"
#include "highgui.h"

NewExp::NewExp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NewExp)
{
    ui->setupUi(this);
    flag=false;
    QPixmap pix("/home/sachin/test2/new/image_placeholder.png");
    ui->label->setPixmap(pix);
    ui->label->setScaledContents( true );
    ui->label->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}

NewExp::~NewExp()
{
    delete ui;
}

void NewExp::on_pushButton_2_clicked()
{
    if (fileName==NULL)
    {
        errorDialog *e=new errorDialog(this);
        e->show();
        this->destroy();
    }
    else
    {
        DataEntry *d=new DataEntry(this,fileName);
        //CvBody *c=new CvBody(this,fileName);
        d->show();
        this->destroy();
        d->imgNum();

    }
}

void NewExp::on_pushButton_clicked()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"", tr("Files (*.*)"));
    QPixmap pix(fileName);
    ui->label->setPixmap(pix);
    ui->label->setScaledContents( true );
    ui->label->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );


}
/*Code for direct Camera Access
void NewExp::on_pushButton_3_clicked()
{
    if(!flag)
    {
    capture = cvCaptureFromCAM(0);
    frame=cvQueryFrame( capture );
    qimg= IplImage2QImage(frame);
    ui->label->setPixmap(QPixmap::fromImage(qimg));
    ui->label->setScaledContents( true );
    ui->label->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    while(1) {
    frame = cvQueryFrame( capture );
    qimg= IplImage2QImage(frame);
    ui->label->setPixmap(QPixmap::fromImage(qimg));
    ui->label->setScaledContents( true );
    ui->label->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    flag=true;
    QCoreApplication::processEvents();


    }}
    else
    {   QCoreApplication::
        QPixmap pix("/home/sachin/test2/new/image_placeholder.png");
        ui->label->setPixmap(pix);
        ui->label->setScaledContents( true );
        ui->label->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
        cvReleaseCapture(&capture);
    }
}
*/

QImage NewExp::IplImage2QImage(const IplImage *iplImage)
 {
           int height = iplImage->height;
           int width = iplImage->width;

           const uchar *qImageBuffer =(const uchar*)iplImage->imageData;
           QImage img(qImageBuffer, width, height, QImage::Format_RGB888);
           return img.rgbSwapped();
  }
