#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QIcon>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // стиль из ресурсов
    QFile file(":/style/style.css");
    file.open(QFile::ReadOnly);
    a.setStyleSheet(file.readAll());

    MainWindow w;
    w.show();
    return a.exec();
}
