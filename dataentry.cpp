#include "dataentry.h"
#include "ui_dataentry.h"
#include "qlabel.h"
#include "qlayout.h"
#include "qcombobox.h"
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include "newexp.h"
#include "cvbody.h"
#include <cv.h>
#include <highgui.h>
#include <iostream>
#include <fstream>
#define CVX_RED		CV_RGB(0xff,0x00,0x00)
#define CVX_GREEN	CV_RGB(0x00,0xff,0x00)
#define CVX_BLUE	CV_RGB(0x00,0x00,0xff)
struct point {
    int x;
    int y;
    double area;
};

//CvCapture* g_capture = NULL;


DataEntry::DataEntry(QWidget *parent,QString s) :
    QMainWindow(parent),
    ui(new Ui::DataEntry)
{
    ui->setupUi(this);
    fileName =s;
    count=0;
    ///
    /// Db Connection
    ///
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("CLSI");
    db.setUserName("root");
    db.setPassword("root");
    bool ok=db.open();
    flag=false;
    ///
    ///Cv stuff(tread lightly)
    ///
    QByteArray ba = s.toLocal8Bit();
    const char *s1 = ba.data();
      IplImage* img_8uc1 = cvLoadImage(s1);
//Danger

      int  img_thresh  = 137;
      CvFont * font = new CvFont;
      cvInitFont(font, CV_FONT_VECTOR0, 0.5f, 1.0f, 0, 2, 8);
      IplImage* img_edge = cvCreateImage( cvGetSize(img_8uc1), 8, 1 );
      cvCvtColor( img_8uc1, img_edge, CV_BGR2GRAY );
      cvThreshold( img_edge, img_edge, img_thresh, 255, CV_THRESH_BINARY );
      CvMemStorage* storage = cvCreateMemStorage();
      CvSeq* first_contour = NULL;
      int Nc = cvFindContours(
         img_edge,
         storage,
         &first_contour,
         sizeof(CvContour),
         CV_RETR_LIST
      );
      double area;
    //  char text[8];

      for( CvSeq* c1=first_contour; c1!=NULL; c1=c1->h_next ) {
          area = cvContourArea(c1);
               if(area > 500 && area < 7000)
                 count++;
            }

//Danger



    ///
    /// Getting bacteria & agent
    ///
    QSqlQuery query;
    query.exec("select distinct TestB from ZOI");
    ui->comboBox->addItem("");
    while (query.next()) {
        QString name = query.value(0).toString();
        ui->comboBox->addItem(name);
    }

    }

DataEntry::~DataEntry()
{
    delete ui;
}


void DataEntry::on_backb_clicked()
{
    NewExp *n=new NewExp(this);
    n->show();
    this->destroy();
}

void DataEntry::on_nextb_clicked()
{
    CvBody *cv=new CvBody(this);
    cv->show();
    this->destroy();
    int i;
    QString s[12];
    s[0]=ui->comboBox->currentText();
    for(i=1;i<=count;i++)
    {
        s[i]=c[i-1]->currentText();
}
    cv->cvMethod(fileName,s,count+1);
}

void DataEntry::on_comboBox_currentTextChanged(const QString &arg1)
{
    int i;
    QSqlQuery q2;
    //QLabel *qq=new QLabel(this);
    //qq->setText(QString("%1").arg(count));
    QLayout *ql=ui->formLayout;
    clearLayout(ql,true);
    for(i=0;i<count;i++)
    {
    t[i] = new QLabel(this);
    c[i]= new QComboBox(this);
    h[i]=new QHBoxLayout(this);
    t[i]->setText(QString("Enter Anti-Microbial Agent %1").arg(i+1));

//    q2.exec("select distinct AntiMicrobialAgent from ZOI");
    q2.exec("select distinct AntiMicrobialAgent from ZOI where TestB ='"+ui->comboBox->currentText()+"'");
    c[i]->clear();
    c[i]->addItem("");
    while (q2.next()) {
        QString name = q2.value(0).toString();
        c[i]->addItem(name);
    }

    ui->formLayout->insertRow(i,h[i]);
    h[i]->insertWidget(0,t[i]);
    h[i]->insertWidget(1,c[i]);
    //flag=true;
}

}

void DataEntry::clearLayout(QLayout* layout, bool deleteWidgets = true)
{
    while (QLayoutItem* item = layout->takeAt(0))
    {
        if (deleteWidgets)
        {
            if (QWidget* widget = item->widget())
                delete widget;
        }
        if (QLayout* childLayout = item->layout())
            clearLayout(childLayout, deleteWidgets);
        delete item;
    }
}

int DataEntry::imgNum()
{
    int xc[100],yc[100];
        int xcc=0,ycc=0;

    //cvNamedWindow( "Image", 1 );
    QByteArray ba = fileName.toLocal8Bit();
    const char *s1 = ba.data();
      IplImage* img_8uc1 = cvLoadImage(s1);

      int  img_thresh  = 137;
      CvFont * font = new CvFont;
      cvInitFont(font, CV_FONT_VECTOR0, 0.5f, 1.0f, 0, 2, 8);
      IplImage* img_edge = cvCreateImage( cvGetSize(img_8uc1), 8, 1 );
      IplImage* img_8uc3 = cvCreateImage( cvGetSize(img_8uc1), 8, 3 );
      IplImage* img_8uc5 = cvCreateImage( cvGetSize(img_8uc1), 8, 3 );
    cvCvtColor( img_8uc1, img_edge, CV_BGR2GRAY );
      cvThreshold( img_edge, img_edge, img_thresh, 255, CV_THRESH_BINARY );
      CvMemStorage* storage = cvCreateMemStorage();
      CvSeq* first_contour = NULL;
      int Nc = cvFindContours(
         img_edge,
         storage,
         &first_contour,
         sizeof(CvContour),
         CV_RETR_LIST
      );
      int n=0,k;
      double area;
      char text[8];
        struct point a[100];
     // printf( "Total Contours Detected: %d\n", Nc );
     // QString temp=QString("Total Contours Detected: %1\n").arg(Nc);

      //cvCvtColor( img_8uc1, img_8uc3, CV_GRAY2BGR );
int count=0;
double svalue=0,rvalue=0;
QString temp="";
      for( CvSeq* c=first_contour; c!=NULL; c=c->h_next ) {
          area = cvContourArea(c);
               if(area <= 1000 || area >= 10000)
                 continue;
         cvDrawContours(
            img_8uc3,
            c,
            CVX_RED,
            CVX_BLUE,
            0,
            2,
            100
         );
         CvPoint* p = CV_GET_SEQ_ELEM( CvPoint, c, 1 );
         //printf("    (%d,%d)\n", p->x, p->y );
         //temp.append(QString("    (%1,%2)\n").arg(p->x).arg(p->y));

         ///Getting range values
         ///


         ///


                  a[count].x=p->x;
                  a[count].y=p->y;
                  a[count].area=area;
                  count++;



             n++;
              }
              int i;
              decide(a,count);
              int pos;
              for(i=0;i<count;i++)
              {

         //CvPoint* p = CV_GET_SEQ_ELEM( CvPoint, c, 1 );
         pos=a[i].y+25;
              sprintf(text,"%d", i+1);
              cvPutText(img_8uc3, text, cvPoint(a[i].x,pos), font, CVX_GREEN);
          }
          cvShowImage("Contour Image" , img_8uc3 );

               cvSaveImage("work1.jpg",img_8uc5);

      //cvCvtColor( img_8uc1, img_8uc3, CV_GRAY2BGR );
      cvWaitKey(0);
      cvDestroyWindow("Image");
      cvReleaseImage( &img_8uc1 );
      cvReleaseImage( &img_8uc3 );
      cvReleaseImage( &img_edge );
      return 0;
}


void DataEntry::decide(struct point p[],int n) {

    struct point centroid;
    centroid.x=centroid.y=0;
    int i;
    for(i=0;i<n;i++) {
        centroid.x+=p[i].x;
        centroid.y+=p[i].y;
    }

    centroid.x=(int)(centroid.x/n);
    centroid.y=(int)(centroid.y/n);
    //printf("Centroid:x:%d y:%d\n",centroid.x,centroid.y);
    struct point shift[n];
    for(i=0;i<n;i++) {
        shift[i].x=p[i].x-centroid.x;
        shift[i].y=p[i].y-centroid.y;
    }
    /*for(i=0;i<n;i++) {
        printf("Shift:x:%d y:%d\n",shift[i].x,shift[i].y);
    }*/
    float degrees[n][2];
    for(i=0;i<n;i++) {
        degrees[i][0]=i;
        degrees[i][1]=asin(shift[i].y/sqrt(pow(shift[i].x,2)+pow(shift[i].y,2)))*180/3.14;
        if(shift[i].x<0)
            degrees[i][1]=180-degrees[i][1];
    }
    int j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-1; j++)
        {
            if(degrees[j][1]>degrees[j+1][1])
            {
                int temp0 = degrees[j][0];
                int temp1 = degrees[j][1];
                degrees[j][0] = degrees[j+1][0];
                degrees[j][1] = degrees[j+1][1];
                degrees[j+1][0] = temp0;
                degrees[j+1][1] = temp1;
            }
        }
    }
    struct point dummy[n];
    for(i=0;i<n;i++) {
        dummy[i].x=p[(int)degrees[i][0]].x;
        dummy[i].y=p[(int)degrees[i][0]].y;
        dummy[i].area=p[(int)degrees[i][0]].area;
    }

    for(i=0;i<n;i++) {
        p[i].x=dummy[i].x;
        p[i].y=dummy[i].y;
        p[i].area=dummy[i].area;
    }
}
