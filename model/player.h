#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <iostream>
#include <string>
#include "color.h"
#include "dice.h"

#include "randomgenerator.hpp"
#include <random>

using namespace std;

/**
 * @brief Classe pour un Joueur.
 * Cette classe permet de représenter un joueur dans le jeu.
 * @author  Ordoñez Jonathan
 * @date    Octobre 2016
 */
class Player {
private:

    static int ID;
    const int currentID;

    Color color;
    int money;
    vector<Dice*> dices;
    int restdice;

public :
    //Constructor
    /**
     * @brief     Contructeur de la classe \a Player.
     * @param     dices Booléen indiquant si on joue avec les gros dés.
     */
    Player(bool dices);

    //gettes
    /**
     * @brief     Retourne la somme totale d'argent pour le joueur et round courant.
     * @details   La quantité d'argent est calculé lors de chaque round.
     * @return    Un entier représentant la somme totale d'argent.
     */
    int get_money()const;

    /**
     * @brief     Retourne la couleur du joueur courant.
     * @details   Chaque joueur a une couleur different.
     * @return    Un Color représentant la couleur du ce joueur.
     */
    Color get_color()const;

    /**
     * @brief     Retourne l'ID du joueur.
     * @details   L'I est donne lors de la creation du joueur.
     * @return    Un entier représentant l'ID du joueur.
     */
    int get_ID()const;

    /**
     * @brief     Retourne les dés du joueur courant
     * @details   Chaque joueur a 8 dés, cette méthode retourne une reference vers cette table de dés.
     * @return    Un Vector de dés contenant tous les dés d'un joueur.
     */
    vector<Dice*> & get_dices();

    /**
     * @brief     Retourne la quantité restant de dés.
     * @return    Un entier représentant le nombre restant de dés a lancer.
     */
    int restDice();

    //setters
    /**
     * @brief     Ajoute d'argent dans la somme totale.
     * @details   Chaque fois qu'on ajoute d'argent, l'argent sera augmenté.
     * @param     add_money Entier pour ajouter a la somme totale.
     */
    void set_money(int add_money);


    //fonctions
    /**
     * @brief     Calcule des nombres aleatoire pour attribuer à chaque dés.
     * @details   Un joueur lance les dés et obtient des chiffres aleatoires de 1 à 6.
     */
    void throw_dices();

    /**
     * @brief     Retire les dés du jeu pour passer au joueur suivant.
     * @details   À la fin de son tour le jouer ramase les dés du jeu pour continuer au joueur suivant.
     */
    void takeout_dices();

    /**
     * @brief     Décrément le nombre de dés à lancer par le joueur.
     */
    void decreaseDice();

    /**
     * @brief     Restaure tous les dés pour que le joueur puisse les utiliser.
     * @details   À la fin de chaque round, tous les joueurs recupere leurs dés.
     */
    void restoreDice();

    /**
     * @brief Reécritue de l'operateur de surcharge pour la sortie standard.
     * @relates Player.
     */
    friend std::ostream & operator<<(std::ostream & out, const Player & s);

};

#endif // PLAYER_H
