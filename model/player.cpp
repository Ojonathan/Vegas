#include "player.h"
int Player::ID = 0;

Player::Player(bool dices):currentID(ID++){
    this->money = 0;
    switch (ID) {
        case 1:
            this->color = Color::green;
            break;
        case 2:
            this->color = Color::violet;
            break;
        case 3:
            this->color = Color::yellow;
            break;
        case 4:
            this->color = Color::white;
            break;
        case 5:
            this->color = Color::black;
            break;
        case 6:
            this->color = Color::blue;
            break;
        case 7:
            this->color = Color::red;
            break;
        case 8:
            this->color = Color::grey;
            break;
        }

    for(int i=0;i<8;i++){
        this->dices.push_back(new Dice(this->color));
    }

    if(dices == true){
        //l'implementation du gros dés n'est pas fait.
        //this->dices[0]->set_big(true);
    }

    restdice=8;
}

//getters
int Player::get_money()const{
    return money;
}

Color Player::get_color()const{
    return color;
}

int Player::get_ID()const{
    return ID;
}

vector<Dice *> &Player::get_dices(){
    return dices;
}

int Player::restDice(){
    return restdice;
}

//setters
void Player::set_money(int add_money){
    money = add_money;
}

//fonctions
void Player::throw_dices(){
    for(int i=0;i<restdice;i++){
        this->dices[i]->set_value(nvs::random_integer(1,6));
    }
}

void Player::takeout_dices(){
    for(int i=0;i<8;i++){
        this->dices[i]->set_value(0);
    }
}

void Player::decreaseDice(){
    restdice--;
}

void Player::restoreDice(){
    restdice = 8;
}

std::ostream & operator<<(std::ostream & out, const Player & p){
    out << "le joueur: " << p.color << " a : " << p.money << " dollars";
    return out;
}
