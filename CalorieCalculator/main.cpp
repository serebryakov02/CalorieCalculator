#include "dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/files/icons/calories-calculator.png"));
    Dialog w;
    w.show();
    return a.exec();
}
