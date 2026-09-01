#include "calculation.h"
#include <QStringList>
#include <QDebug>
#include <QFile>
#include <QTextStream>

Calculation::Calculation(QObject *parent)
    : QObject{parent}
{

}

void Calculation::onCalculation(QString expression)
{
    expression.replace(",", ".");

    if (expression.contains("/0")) {
        qDebug() << "Ошибка: деление на ноль";
        return;
    }

    float result = 0.0;

    if (expression.contains("+")) {
        QStringList parts = expression.split("+");
        if (parts.size() == 2)
            result = parts[0].toFloat() + parts[1].toFloat();
    }
    else if (expression.contains("-")) {
        QStringList parts = expression.split("-");
        if (parts.size() == 2)
            result = parts[0].toFloat() - parts[1].toFloat();
    }
    else if (expression.contains("*")) {
        QStringList parts = expression.split("*");
        if (parts.size() == 2)
            result = parts[0].toFloat() * parts[1].toFloat();
    }
    else if (expression.contains("/")) {
        QStringList parts = expression.split("/");
        if (parts.size() == 2 && parts[1].toFloat() != 0)
            result = parts[0].toFloat() / parts[1].toFloat();
    }
    else {
        result = expression.toFloat();
    }

    qDebug() << "Результат вычисления:" << result;

    QFile file("history.txt"); // 6 lab

    // Проверяем существование файла
    if (file.exists()) {
        qDebug() << "Файл существует";
    }

    // Открываем файл для дописывания текста
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Ошибка при открытии файла";
        return;
    }

    // Создаем поток для записи текста
    QTextStream writeStream(&file);

    // Записываем в файл выражение и результат
    writeStream << expression << " = " << result << "\n";

    // Закрываем файл (важно!)
    file.close();
}
