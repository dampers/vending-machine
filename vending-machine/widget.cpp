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

std::string Widget:: calChange(int coin)
{
    int coins = 0;
    if(money>=coin)
    {
        coins += money/coin;
        money %= coin;
    }
    return std::to_string(coin) + "coins = " + std::to_string(coins) + "\n";

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
    change += calChange(500);
    change += calChange(100);
    change += calChange(50);
    change += calChange(10);
    m.information(nullptr, "information", change.c_str());
    changeMoney(0);
}
