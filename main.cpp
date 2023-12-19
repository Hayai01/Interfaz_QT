#include "tasky.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    tasky w;
    w.show();
    return a.exec();
}
