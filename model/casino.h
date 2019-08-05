#ifndef CASINO_H
#define CASINO_H

#include <vector>
#include "dice.h"
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * @brief Classe pour Casino.
 * @details Cette classe permet de représenter un casino.
 * @author  Ordoñez Jonathan
 * @date    Octobre 2016
 */
class Casino{   
private:
    int money;
    vector<int> billets;
    vector<pair<Color,int>> dices_players;
    vector<pair<Color,int>> winners;

public:
    //contructor
    /**
     * @brief Constructeur de la classe Casino.
     */
    Casino();

    //getters
    /**
     * @brief Retourne la quantité d'argent qu'il y a dans un Casino.
     * @return Un entier représentant la somme totale d'argent un casino.
     */
    int get_money()const;

    /**
     * @brief Retourne tout le billets d'un casino.
     * @return Un vecteur d'entiers représentant tout les billets introduit dans un casino.
     */
    vector<int> get_billets()const;

    /**
     * @brief Retourne les dés et le nombre des fois qu'ils apparaissent dans un casino.
     * @return Un vecteur de pair, le pair est composé d'une couleur et un entier.
     */
    vector<pair<Color,int>> get_dices()const;

    /**
     * @brief Retourne les gagnants pour un round et l'argent emporté.
     * @return Un vecteur de pair, le pair est composé d'une couleur et un entier qui indique
     * la quantité d'argent que le joueur a gagné.
     */
    vector<pair<Color,int>> get_winners();

    /**
     * @brief Retourne vrai s'il n'y a pas aucun billet dans le casino sinon faux.
     * @return Un booléen indiquant s'il n'y a pas des billets dans le casino.
     */
    bool isClean();


    //setters
    /**
     * @brief Modifie la somme totale d'argent.
     * @param money Un entier représentant la somme d'argent à ajouter.
     */
    void set_money(int money);

    /**
     * @brief Ajoute et Modifie la liste de joueurs gagnants.
     * @param color Une couleur \e Color du joueur gagnant à ajouter.
     * @param money Un entier représentant la somme d'argent à ajouter.
     */
    void set_winners(Color color,int money);

    //Fonctions
    /**
     * @brief Ajoute les billets du jeu au casino et calcule la somme totale d'argent.
     * @param billet Un entier représentant la valeur du billet à ajouter.
     */
    void add_billets(int billet);

    /**
     * @brief Ajoute les dés du joueur au casino.
     * @param color Une couleur \e Color indiquant la coueur du dé à ajouter.
     */
    void add_dices(Color color);

    /**
     * @brief Nettoie le tableau contenant les dés.
     */
    void clean_dices();

    /**
     * @brief Nettoie le tableau contenant les billets.
     */
    void clean_billets();

    /**
     * @brief Ordonne les billets du casino pour aprés les distribuer au gagnants.
     */
    void order_billets();

    /**
     * @brief Nettoie le tableau contenant les gagnants.
     */
    void clean_winners();

    /**
     * @brief Verifie et supprime les doublons.
     * @details il est possible d'avoir plus de 2 doublons pourtant cette méthode les supprime.
     */
    void eraseDoubles();

    /**
     * @brief Enleve un billet du casino.
     * @return Un entier contenant la valeur du billet retiré du casino.
     */
    int remove_billet();

    /**
     * @brief Extension de comparaison pour \e sort(), on ordonne les gagnants.
     * @param a Un pair<Color,int>.
     * @param b Un pair<Color,int>.
     * @return Un booléen indiquant si a.second et superieur a b.second.
     */
    bool static sortbysec(const pair<Color,int> &a,const pair<Color,int> &b);
};

#endif // CASINO_H
