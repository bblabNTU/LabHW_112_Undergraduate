#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Ordering System");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // Setup
    ui->showData->setText("");
    ui->showData->setFontPointSize(14);
    QString customerChoose = "You order : ", customerPayWay = "You choose ";
    int totalMoney = 0, payMoney;

    // Check box
    if(ui->carrotCake->checkState())
    {
        customerChoose += "Carrot Cake, ";
        totalMoney += 40;
    }
    if(ui->dumpling->checkState())
    {
        customerChoose += "Dumpling, ";
        totalMoney += 30;
    }
    if(ui->hotdog->checkState())
    {
        customerChoose += "Hotdog, ";
        totalMoney += 20;
    }
    if(ui->porkHamberger->checkState())
    {
        customerChoose += "Pork Hamberger, ";
        totalMoney += 50;
    }
    if(ui->tunaChineseOmelet->checkState())
    {
        customerChoose += "Tuna Chinese Omelet, ";
        totalMoney += 35;
    }
    if(ui->blacktea->checkState())
    {
        customerChoose += "Blacktea, ";
        totalMoney += 20;
    }
    if(ui->coffee->checkState())
    {
        customerChoose += "Coffee, ";
        totalMoney += 35;
    }
    if(ui->freshMilktea->checkState())
    {
        customerChoose += "Fresh Milk Tea, ";
        totalMoney += 35;
    }
    if(ui->milktea->checkState())
    {
        customerChoose += "Milk Tea, ";
        totalMoney += 25;
    }
    if(ui->soymilk->checkState())
    {
        customerChoose += "Soy Milk, ";
        totalMoney += 20;
    }

    // Radio box
    if(ui->jkoPay->isChecked())
    {
        double returnMoney = totalMoney*0.06;
        payMoney = totalMoney;
        customerPayWay += "jko pay(get " + QString::number(int(returnMoney)) + " reward)";
    }
    else if (ui->studentPay->isChecked())
    {
        payMoney = totalMoney - 5;
        customerPayWay += "student pay";
    }
    else if (ui->ordinaryPay->isChecked())
    {
        payMoney = totalMoney;
        customerPayWay += "ordinary pay";
    }
    else
    {
        ui->showData->append("You have to choose a payment method!");
        return;
    }

    // Show data
    customerChoose.replace(customerChoose.length() - 2, 1, ""); // clear the last punctuation, ","
    ui->showData->append(customerChoose);
    ui->showData->append("Total money is " + QString::number(totalMoney));
    ui->showData->append(customerPayWay + ", so you have to pay " + QString::number(payMoney));
}

void MainWindow::on_pushButton_3_clicked()
{
    QApplication::quit();
}

