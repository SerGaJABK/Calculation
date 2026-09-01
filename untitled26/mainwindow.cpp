#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "calculation.h"
#include "math.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Создаём объект класса Calculation
    Calculation* calc = new Calculation(this);
    // Соединяем сигнал и слот
    connect(this, &MainWindow::calculation, calc, &Calculation::onCalculation);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "0");
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "1");
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "2");
}

void MainWindow::on_pushButton_17_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "3");
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "4");
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "5");
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "6");
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "7");
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "8");
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "9");
}

void MainWindow::on_pushButton_18_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + ",");
}

void MainWindow::on_pushButton_clicked()
{
    ui->lineEdit->setText("");
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->lineEdit->backspace();
}

void MainWindow::on_pushButton_11_clicked()
{
    float num = ui->lineEdit->text().toFloat();
    ui->lineEdit->setText(QString::number(sqrt(num)));
}

void MainWindow::on_pushButton_12_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + " / ");
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + " * ");
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + " - ");
}

void MainWindow::on_pushButton_19_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + " + ");
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->lineEdit->setText(QString::number(-ui->lineEdit->text().toFloat()));
}

void MainWindow::on_pushButton_20_clicked()
{
    QString expression = ui->lineEdit->text();

    if (expression.isEmpty()) {
            QMessageBox::warning(this, "Ошибка", "Выражение пустое!");
            return;
        }
    // Проверка деления на ноль
    if (expression.contains("/ 0") || expression.contains("/0")) {
        QMessageBox::critical(this, "Ошибка", "Деление на ноль невозможно!");
        return;
        }
    if (expression.contains("+ +") || expression.contains("- -") ||
            expression.contains("* *") || expression.contains("/ /"))
        {
        QMessageBox::warning(this, "Ошибка", "Некорректное выражение!");
        return;
    }


    emit calculation(expression);
    expression.replace(",", ".");


    if (expression.contains("+")) {
        QStringList parts = expression.split("+");
        if (parts.size() == 2) {
            float num1 = parts[0].toFloat();
            float num2 = parts[1].toFloat();
            ui->lineEdit->setText(QString::number(num1 + num2));
        }
        return;
    }

    if (expression.contains("-")) {
        QStringList parts = expression.split("-");
        if (parts.size() == 2) {
            float num1 = parts[0].toFloat();
            float num2 = parts[1].toFloat();
            ui->lineEdit->setText(QString::number(num1 - num2));
        }
        return;
    }

    if (expression.contains("*")) {
        QStringList parts = expression.split("*");
        if (parts.size() == 2) {
            float num1 = parts[0].toFloat();
            float num2 = parts[1].toFloat();
            ui->lineEdit->setText(QString::number(num1 * num2));
        }
        return;
    }

    if (expression.contains("/")) {
        QStringList parts = expression.split("/");
        if (parts.size() == 2) {
            float num1 = parts[0].toFloat();
            float num2 = parts[1].toFloat();
            ui->lineEdit->setText(QString::number(num1 / num2));
        }
        return;
    }

    ui->lineEdit->setText(QString::number(expression.toFloat()));
}


void MainWindow::keyPressEvent(QKeyEvent *pEvent)
{
    if (pEvent->key() == Qt::Key_0) ui->lineEdit->setText(ui->lineEdit->text() + "0");
    if (pEvent->key() == Qt::Key_1) ui->lineEdit->setText(ui->lineEdit->text() + "1");
    if (pEvent->key() == Qt::Key_2) ui->lineEdit->setText(ui->lineEdit->text() + "2");
    if (pEvent->key() == Qt::Key_3) ui->lineEdit->setText(ui->lineEdit->text() + "3");
    if (pEvent->key() == Qt::Key_4) ui->lineEdit->setText(ui->lineEdit->text() + "4");
    if (pEvent->key() == Qt::Key_5) ui->lineEdit->setText(ui->lineEdit->text() + "5");
    if (pEvent->key() == Qt::Key_6) ui->lineEdit->setText(ui->lineEdit->text() + "6");
    if (pEvent->key() == Qt::Key_7) ui->lineEdit->setText(ui->lineEdit->text() + "7");
    if (pEvent->key() == Qt::Key_8) ui->lineEdit->setText(ui->lineEdit->text() + "8");
    if (pEvent->key() == Qt::Key_9) ui->lineEdit->setText(ui->lineEdit->text() + "9");

    if (pEvent->key() == Qt::Key_Plus) ui->lineEdit->setText(ui->lineEdit->text() + " + ");
    if (pEvent->key() == Qt::Key_Minus) ui->lineEdit->setText(ui->lineEdit->text() + " - ");
    if (pEvent->key() == Qt::Key_Asterisk) ui->lineEdit->setText(ui->lineEdit->text() + " * ");
    if (pEvent->key() == Qt::Key_Slash) ui->lineEdit->setText(ui->lineEdit->text() + " / ");
    if (pEvent->key() == Qt::Key_Comma || pEvent->key() == Qt::Key_Period) ui->lineEdit->setText(ui->lineEdit->text() + ",");

    if (pEvent->key() == Qt::Key_Backspace) ui->lineEdit->backspace();
    if (pEvent->key() == Qt::Key_Delete) ui->lineEdit->setText("");
    if (pEvent->key() == Qt::Key_Enter || pEvent->key() == Qt::Key_Return) on_pushButton_20_clicked();
}
