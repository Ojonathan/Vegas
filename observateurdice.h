#ifndef OBSERVATEURDICE_H
#define OBSERVATEURDICE_H

#include <QWidget>
#include <QObject>

#include <QHBoxLayout>
#include <QVector>
#include <QPixmap>

#include "model/game.h"
#include "o_sdo/observateur.h"
#include "o_sdo/sujetdobservation.h"
#include <QtGui>

/**
 * @brief Classe pour l'inteface graphique.
 * @details Cette classe permet gérer les composants graphiques du jeu tels
 * que les images des dés.
 * @author  Ordoñez Jonathan
 * @date    Octobre 2016
 */
class ObservateurDice: public QHBoxLayout, public Observateur
{
    Q_OBJECT

private:
    Game * game {nullptr};
    QVector<QLabel *> l_dices;

public:

    /**
     * @brief     Contructeur de la classe ObservateurDice.
     * @param     new_game Le jeu qui va être observé.
     */
    explicit ObservateurDice(Game * new_game);

    /**
     * @brief     Destructeur de cet observateur.
     */
    ~ObservateurDice();

    /**
     * @brief     Rafraichi les composants de l'ecran à chaque mouvement fait par le joueur.
     * @param     game Le jeu qui va être observé.
     */
    void rafraichir(SujetDObservation *game);

    /**
     * @brief     Nettoie les dés de l'écran.
     */
    void clean_dices();

};

#endif // OBSERVATEURDICE_H
