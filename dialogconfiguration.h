#ifndef DIALOGCONFIGURATION_H
#define DIALOGCONFIGURATION_H

#include <QDialog>
#include <vector>

using namespace std;

namespace Ui {
class DialogConfiguration;
}


/**
 * @brief Classe pour QDialog pour configuration du jeu.
 * @details Cette classe permet paramétrer le jeu avec la quantité des jouers,
 *  l'option des billets et gros dés.
 * @author  Ordoñez Jonathan
 * @date    Octobre 2016
 */
class DialogConfiguration : public QDialog
{
    Q_OBJECT


private:
    Ui::DialogConfiguration *ui;
    unsigned nbPlayers;
    bool with_bills;
    bool with_big_dice;

public:

    /**
     * @brief DialogConfiguration Constructeur.
     * @param parent la classe que sera lié.
     */
    explicit DialogConfiguration(QWidget *parent = 0);

    /**
      *Destructeur simple
      */
    ~DialogConfiguration();

    /**
     * @brief getTaille, méthode qui permet de savoir combien joueurs vont jouer.
     * @return un entier pour savoir la quantité de joueurs.
     */
    unsigned getTaille();

    /**
     * @brief withBills, méthode qui permet de savoir si on jeu avec l'option de 5 billets de 100000.
     * @return un boolean qui nous indique si on a choisi de jouer avec les 5 billets.
     */
    bool withBills();

    /**
     * @brief withDices, méthode qui permet de savoir si on a choisi des jouer avec les gros dés.
     * @return un boolean qui nous indique si on a choisi de jouer avec les gros dés.
     */
    bool withDices();

private slots :

    /**
     * @brief setTaille, méthode pour indiquer le nombre des jouers lors du paramétrage du jeu.
     * @param nbPlayers Entier pou indiquer la quantité des jouers.
     */
    void setTaille(int nbPlayers);

    /**
     * @brief setBills, méthode pour indiquer si on joue avec les billets de 100000.
     * @param bills Boolean pour indiquer si on joue avec les 5 billets de 100000.
     */
    void setBills(bool bills);

    /**
     * @brief setDices, méthode pour indiquer si on joue avec les gros dés.
     * @param dices Boolean pour indiquer au jeu si on va jouer avec les gros dés.
     */
    void setDices(bool dices);
};

#endif // DIALOGCONFIGURATION_H
