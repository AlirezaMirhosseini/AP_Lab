#include "sign_in_up.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    sign_in_up w;
    w.show();
    return a.exec();
}
