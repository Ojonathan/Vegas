#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogconfiguration.h"
#include <QMessageBox>
#include <sstream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connexion();

    ui->b_throw->setEnabled(false);
    ui->b_nextPlayer->setEnabled(false);
    ui->cb_addCasino->setEnabled(false);
    ui->actionQuitter->setEnabled(false);

    fillCB();
}

MainWindow::~MainWindow()
{
    //close observers
    delete observateur_casinos;
    observateur_casinos = nullptr;

    delete observateur_dices;
    observateur_dices = nullptr;

    //close game
    delete game;
    game = nullptr;

    //delete user_interface
    delete ui;
}

void MainWindow::connexion(){
    connect(ui->actionQuitter, &QAction::triggered,&QCoreApplication::quit);
    connect(ui->b_throw, &QPushButton::clicked,this,&MainWindow::playerThrow);
    connect(ui->b_nextPlayer, &QPushButton::clicked,this,&MainWindow::nextPlayer);
    connect(ui->actionNouveau, &QAction::triggered,this,&MainWindow::createGame);
    connect(ui->cb_addCasino,static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::activated),
        this,&MainWindow::addToCasino);

}

void MainWindow::createGame(){
    DialogConfiguration dc(this);
    int retour = dc.exec();

    if (retour == QDialog::Rejected) {
        return;
    } else {
        try {
            this->game = new Game(dc.getTaille(),dc.withBills(),dc.withDices());
            this->game->shuffle_money();
            this->game->distribute_money();
            this->game->shuffle_players();

            //observateur casino
            observateur_casinos = new ObservateurCasino(game);
            ui->game_graphics->addLayout(observateur_casinos);

            //observateur dice
            observateur_dices = new ObservateurDice(game);
            ui->game_graphics->addLayout(observateur_dices);

            ui->b_throw->setEnabled(true);
            ui->b_nextPlayer->setEnabled(false);
            ui->cb_addCasino->setEnabled(false);
            ui->actionNouveau->setEnabled(false);
            ui->actionQuitter->setEnabled(true);
            ui->l_game->setText(state_player());

        } catch (std::string e) {
            QMessageBox::critical(0,"Erreur",QString::fromStdString(e));
        }
    }
}

void MainWindow::playerThrow(){
    this->game->throwDices();
    ui->b_throw->setEnabled(false);
    ui->cb_addCasino->setEnabled(true);
}

void MainWindow::nextPlayer(){
    this->game->nextPlayer();
    ui->b_nextPlayer->setEnabled(false);
    ui->b_throw->setEnabled(true);
    ui->l_game->setText(state_player());
}

void MainWindow::addToCasino(const QString & pro){
    bool result;
    this->game->addDicestoCasino(pro.toInt(&result,10));
    ui->b_nextPlayer->setEnabled(true);

    ui->cb_addCasino->setEnabled(false);

    if(this->game->isFinishRound()){
        this->game->give_bill2players();
        this->game->nextRound();

        this->showState();

        ui->b_nextPlayer->setEnabled(false);
        ui->b_throw->setEnabled(true);

        this->game->restore_dices_players();
        this->game->distribute_money();

        ui->l_game->setText(state_player());

        if(this->game->isOver()){
            ui->b_nextPlayer->setEnabled(false);
            ui->b_throw->setEnabled(false);
            ui->cb_addCasino->setEnabled(false);
            ui->l_game->setText("");
            observateur_dices->clean_dices();
            observateur_casinos->clean_label();
            showWinners();
        }
    }
}

void MainWindow::fillCB(){
    for(int i = 1;i<=6;i++)
        ui->cb_addCasino->addItem(QString::number(i));
}

void MainWindow::showState(){
    QMessageBox::information(this,"État du round","<b>Voici les resultats pour la fin de ce round</b><br>"
    + fill_state_players());
}

void MainWindow::showWinners(){
    QMessageBox::information(this,"Gagnant","<b>Voici les resultats pour la fin de ce jeu</b><br>"
    + fill_state_winners());
}

QString MainWindow::fill_state_winners(){
    std::ostringstream stream;
    vector<pair<Color,int>> winners= this->game->get_winners();
    for(unsigned i=0;i<winners.size();i++){
        stream << "<br> Le joueur: " << winners[i].first << " a gagné avec : " << winners[i].second;
    }

    stream <<"<br> Felicitations !!!";
    return QString::fromStdString(stream.str());
}

QString MainWindow::fill_state_players(){
    std::ostringstream stream;
    vector<pair<Color,int>> winners;
    for(int i = 0; i < 6; i++){
        winners = this->game->get_casino_at(i).get_winners();
        stream << "<br>Dans le casino : " << i+1;
        if(winners.size() == 0){
            stream << "<br>Personne a gagné";
        }else{
            for(unsigned j=0;j<winners.size();j++){
                stream << "<br> le joueur : " << winners[j].first << " a reçu : " << winners[j].second;
            }
        }

        stream << "<br>";
        this->game->get_casino_at(i).clean_winners();
    }
    stream << "<b><p align=right> Cliquez sur OK pour passer au round suivant! </p></b>";
    return QString::fromStdString(stream.str());
}

QString MainWindow::state_player(){
    std::ostringstream stream;
    Player player = this->game->get_current_player();
    stream << "Round ("<<game->get_current_round()+1<<"/4)"<<
              "<br>je suis le joueur: " << player.get_color() <<
              "<br>j'ai: " << player.get_money();
    return QString::fromStdString(stream.str());
}
