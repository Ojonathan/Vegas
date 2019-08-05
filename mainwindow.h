#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "model/game.h"
#include "observateurdice.h"
#include "observateurcasino.h"

namespace Ui {
class MainWindow;
}

/**
 * @brief Classe pour l'inteface graphique.
 * @details Cette classe permet gérer les composants graphiques du jeu tels
 * que les boutons, les menus et les messages.
 * @author  Ordoñez Jonathan
 * @date    Octobre 2016
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    QAction* aide;
    Game* game {nullptr};
    ObservateurDice * observateur_dices {nullptr};
    ObservateurCasino * observateur_casinos {nullptr};

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //slots
    void createGame();
    void playerThrow();
    void nextPlayer();
    void addToCasino(const QString & pro);

    //fonctions
    void connexion();
    void fillCB();

    void showState();
    void showWinners();
    QString state_player();
    QString fill_state_winners();
    QString fill_state_players();
};

#endif // MAINWINDOW_H
