#ifndef OBSERVATEURCASINO_H
#define OBSERVATEURCASINO_H

#include "model/game.h"
#include "o_sdo/observateur.h"
#include "o_sdo/sujetdobservation.h"
#include <QHBoxLayout>
#include <QVector>

/**
 * @brief Classe pour l'inteface graphique.
 * @details Cette classe permet gérer les composants graphiques du jeu tels
 * que les données de chaque casino (étiquettes).
 * @author  Ordoñez Jonathan
 * @date    Octobre 2016
 */
class ObservateurCasino: public QHBoxLayout, public Observateur
{
     Q_OBJECT

private:
    Game * game {nullptr};
    QVector<QLabel *> l_casinos;

public:

    /**
     * @brief     Contructeur de la classe ObservateurCasino.
     * @param     new_game Le jeu qui va être observé.
     */
    explicit ObservateurCasino(Game * new_game);

    /**
     * @brief     Destructeur de cette classe.
     */
    ~ObservateurCasino();

    /**
     * @brief     Rafraichi les composants de l'écran à chaque mouvement fait par le joueur.
     * @param     game Le jeu qui va être observé.
     */
    void rafraichir(SujetDObservation *game);

    /**
     * @brief     Retourne une chaine des characters indiquant les billets courant du casino.
     * @return    Un string représentant tous le billets que le casino contient.
     */
    string print_billets(vector<int> billets);

    /**
     * @brief     Retourne une chaine des characters indiquant les dés ajoutés par les jouers
     * dans ce casino.
     * @return    Un string représentant tous le dés que le casino contient.
     */
    string print_dices(vector<pair<Color, int>> dices);

    /**
     * @brief     Nettoie tout le contenu du casino sur l'écran.
     */
    void clean_label();

};

#endif // OBSERVATEURCASINO_H
