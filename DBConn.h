#ifndef DBCONN_H
#define DBCONN_H

#endif // DBCONN_H
void Conn(void);
void Conn(void){
QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("localhost");
     db.setDatabaseName("CLSI");
     db.setUserName("root");
     db.setPassword("root");
     db.open();
}
