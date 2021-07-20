#include "textedttor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TextEdttor w;
    w.show();
    return a.exec();
}
