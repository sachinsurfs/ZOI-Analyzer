#ifndef VALUETABLE_H
#define VALUETABLE_H

#include <QMainWindow>

namespace Ui {
class ValueTable;
}

class ValueTable : public QMainWindow
{
    Q_OBJECT

public:
    explicit ValueTable(QWidget *parent = 0);
    ~ValueTable();

private:
    Ui::ValueTable *ui;
};

#endif // VALUETABLE_H
