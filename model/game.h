#ifndef GAME_H
#define GAME_H

#include <algorithm>
#include <cstdlib>      // std::rand, std::srand
#include "player.h"
#include "casino.h"

#include "o_sdo/sujetdobservation.h"

/**
 * @brief Classe pour le Jeu.
 * @details Cette classe permet gérer le jeu.
 * @author  Ordoñez Jonathan
 * @date    Octobre 2016
 */
class Game : public SujetDObservation {
private:
    int rounds;
    int unsigned id_player;
    vector<Casino *> casinos;
    vector<Player *> players;
    vector<int> billets;

public:
    //constructor
    /**
     * @brief     Contructeur de la classe Game.
     * @param     nbPlayes Un entier indiquant le nombre de joueurs.
     * @param     bills Un booléen indiquant si on joue avec les 5 billets de 100000.
     * @param     dices Un boolées indiquant si on joue avec les gros dés.
     */
    Game(unsigned nbPlayers, bool bills, bool dices);

    //getters
    /**
     * @brief     Retourne une référence vers le joueur currant.
     * @return    Un Joueut \e Player.
     */
    Player & get_current_player();

    /**
     * @brief     Retoune une référence vers un casino choisi par l'utilisateur
     * @details   Evidement l'indice du casino doit correspondre de 1 à 6.
     * @param     i Un entier représentant l'indice.
     * @return    Une casino \e Casino.
     */
    Casino & get_casino_at(int i);

    /**
     * @brief     Retourne un vecteur contenant le(s) joueur(s) gagnant(s) de ce jeu.
     * @details   Il est possible mais pas très souvent d'avoir plus d'un gagnant pourtant
     * cette méthode donne un vector contenant tous les gagnants.
     * @return    Un vecteur de pair, un pair est composé d'une couleur et un entier qui
     * indique la somme total que ce joueur gagnant a emporté.
     */
    vector<pair<Color,int>> get_winners();

    /**
     * @brief     Retourne la valeur du round courant.
     * @return    Un entier indiquant le round courant.
     */
    int get_current_round();

    /**
     * @brief     Retourne vrai si le round est fini sinon faux.
     * @details   Un round est consideré fini quand tous les joueurs ont utilisé tous leurs dés.
     * @return    Un booléen indiquant la fin du round courant.
     */
    bool isFinishRound();

    /**
     * @brief     Retourne vrai si le jeu est fini sinon faux.
     * @details   Le jeu est fini quand on arrive au 4 rounds.
     * @return     Un booléen indiquant la fin du jeu.
     */
    bool isOver();

    //fonctions
    /**
     * @brief     Permet de passer au joueur suivant.
     * @details   Si le joueur suivant n'as plus des dés alosr on continue au suivant successivement.
     */
    void nextPlayer();

    /**
     * @brief     Mélange les billets du jeu.
     * @details   Il ya un total de 54 billets avec des valeurs differents (voir manuel du jeu).
     */
    void shuffle_money();

    /**
     * @brief     Mélange les joueurs inscrits.
     * @details   On mélagne pour pouvoir choisir un nouveau ordre de passage.
     */
    void shuffle_players();

    /**
     * @brief     Calcule et Distribue les billets au joueurs.
     * @details   Verifie casino par casino et cherchant les gagnants.
     */
    void give_bill2players();

    /**
     * @brief     Permet de passer au round suivant.
     * @details   Un round est consideré fini quand tous les joueurs ont utilisé tous leurs dés.
     */
    void nextRound();

    /**
     * @brief     Restaure les dés à tous les joueurs.
     * @details   On effectue cette action apres avoir fini un round.
     */
    void restore_dices_players();

    /**
     * @brief     Calcule et lance les dés.
     * @details   Un joueur lance ces dés, cette méthode permetra d'apeller le jouer
     * courant et lancer ces dés.
     */
    void throwDices();

    /**
     * @brief     Ajoute des dés choisi par l'utilisateur vers le casino correspondant.
     * @param     value Un entier choisi par l'utilisateur.
     */
    void addDicestoCasino(int value);

    /**
     * @brief     Distribue l'argent à chaque casino.
     * @details   La distribution s'arrête quand on a une somme totale superieur à 50000.
     */
    void distribute_money();

};

#endif // GAME_H
