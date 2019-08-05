#include "dialogconfiguration.h"
#include "ui_dialogconfiguration.h"

DialogConfiguration::DialogConfiguration(QWidget *parent):QDialog(parent),ui(new Ui::DialogConfiguration)
{
    ui->setupUi(this);
    this->nbPlayers = 2;
    with_bills = false;
    with_big_dice = false;
}

DialogConfiguration::~DialogConfiguration()
{
    delete ui;
}

unsigned DialogConfiguration::getTaille(){
    return nbPlayers;
}

bool DialogConfiguration::withBills(){
    return with_bills;
}

bool DialogConfiguration::withDices(){
    return with_big_dice;
}

void DialogConfiguration::setTaille(int nbPlayers){
    this->nbPlayers = nbPlayers;
}

void DialogConfiguration::setBills(bool bills){
    this->with_bills = bills;
}

void DialogConfiguration::setDices(bool dices){
    this->with_big_dice = dices;
}
