#ifndef DICE_H
#define DICE_H

#include <QLabel>
#include "color.h"

using namespace std;

/**
 * @brief Classe pour les dés.
 * @details Cette classe permet de representer un dé.
 * @author  Ordoñez Jonathan
 * @date    Octobre 2016
 */
class Dice {
private:
    int value;
    Color color;
    bool big;

public:

    //contructor
    /**
     * @brief     Contructeur de la classe Dice.
     * @param     color Une couleur \e Color qui provient du joueur.
     */
    Dice(Color color);

    //getters
    /**
     * @brief     Retourne la valeur du dé.
     * @details   chaque joueur lance ces dés, pourtant chaque dé aura une valeur different.
     * @return    Un entier indiquant la valeur.
     */
    int get_value() const;

    /**
     * @brief     Retoune vrai si le dé est gros sinon faux.
     * @return    Un booléen indiquant si le dés est gros ou pas.
     */
    bool is_big() const;

    /**
     * @brief     Retourne la couleur du dé.
     * @return    Une couleur \e Color.
     */
    Color get_color()const;

    //setters
    /**
     * @brief     Permet de modifier la valeur du dé.
     * @param     value Un entier indiquant la valeur pour ce dé.
     */
    void set_value(int value);

    /**
     * @brief     Permet de modifier la couleur du dé.
     * @param     color Une couleur \e Color indiquant la couleur pour ce dé.
     */
    void set_color(Color color);

    /**
     * @brief     Permet d'indiquer si le dé est gros.
     * @param     _big Un booléen indiquant si le dé est gros ou pas.
     */
    void set_big(bool _big);

    /**
     * @brief Reécritue de l'operateur de surcharge pour la sortie standard.
     * @relates Dice.
     */
    friend std::ostream & operator<<(std::ostream & out, const Dice & s);
};

#endif // DICE_H
