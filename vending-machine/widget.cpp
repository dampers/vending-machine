#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <string>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff)
{
    money += diff;
    ui->lcdNumber->display(money);
    if(money>=100) ui->pbCoffee->setEnabled(true);
    else ui->pbCoffee->setEnabled(false);
    if(money>=150) ui->pbTea->setEnabled(true);
    else ui->pbTea->setEnabled(false);
    if(money>=200) ui->pbMilk->setEnabled(true);
    else ui->pbMilk->setEnabled(false);
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbReset_clicked()
{
    QMessageBox m;
    std::string change = "";
    change += "Thank you\n\n";
    int c500 = 0, c100 = 0, c50 = 0, c10 = 0;
    if(money>=500)
    {
        c500 += money/500;
        money %= 500;
    }
    change += "500 coins = " + std::to_string(c500) + "\n";
    if(money>=100)
    {
        c100 += money/100;
        money %= 100;
    }
    change += "100 coins = " + std::to_string(c100) + "\n";
    if(money>=50)
    {
        c50 += money/50;
        money %= 50;
    }
    change += "50 coins = " + std::to_string(c50) + "\n";
    if(money>=10)
    {
        c10 += money/10;
        money %= 10;
    }
    change += "10 coins = " + std::to_string(c10) + "\n";
    m.information(nullptr, "information", change.c_str());
    changeMoney(0);
}
