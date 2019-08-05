#include "observateurdice.h"
#include "model/game.h"

ObservateurDice::ObservateurDice(Game *new_game):game{new_game}
{   
    game->attacher(this);

    for(int i = 0; i < 8; i++){
        l_dices.append(new QLabel);
        l_dices[i]->setFixedWidth(50);
        l_dices[i]->setFixedHeight(50);
        l_dices[i]->setScaledContents(true);
        this->addWidget(l_dices[i]);
    }

    rafraichir(game);
}

ObservateurDice::~ObservateurDice(){
    this->game->detacher(this);
}

void ObservateurDice::rafraichir(SujetDObservation *game){
    Player player = this->game->get_current_player();
    vector<Dice*> dices = player.get_dices();

    Color color = player.get_color();
    string s_color;
    switch(color){
        case Color::green:  s_color = "background-color: rgb(0, 204, 0);";
                            break;
        case Color::violet: s_color = "background-color: rgb(178, 102, 205);";
                            break;
        case Color::yellow: s_color = "background-color: rgb(255, 255, 51);";
                            break;
        case Color::white:  s_color = "background-color: white;";
                            break;
        case Color::black:  s_color = "background-color: rgb(82, 82, 82);";
                            break;
        case Color::blue:   s_color = "background-color: rgb(0, 128, 255);";
                            break;
        case Color::red:    s_color = "background-color: rgb(255, 102, 102);";
                            break;
        case Color::grey:   s_color = "background-color: rgb(202, 201, 201);";
                            break;
    }

    for(unsigned i = 0; i < dices.size(); i++){
        l_dices[i]->setStyleSheet(QString::fromStdString(s_color));

        if(dices[i]->is_big() == true){
            l_dices[i]->setFixedWidth(60);
            l_dices[i]->setFixedHeight(60);
        }else{
            l_dices[i]->setFixedWidth(50);
            l_dices[i]->setFixedHeight(50);
        }

        switch(dices[i]->get_value()){
            case 0:
                l_dices[i]->setPixmap(QPixmap(":ressource/d_0.png"));
                break;
            case 1:
                l_dices[i]->setPixmap(QPixmap(":ressource/d_1.png"));
                break;
            case 2:
                l_dices[i]->setPixmap(QPixmap(":ressource/d_2.png"));
                break;
            case 3:
                l_dices[i]->setPixmap(QPixmap(":ressource/d_3.png"));
                break;
            case 4:
                l_dices[i]->setPixmap(QPixmap(":ressource/d_4.png"));
                break;
            case 5:
                l_dices[i]->setPixmap(QPixmap(":ressource/d_5.png"));
                break;
            case 6:
                l_dices[i]->setPixmap(QPixmap(":ressource/d_6.png"));
                break;
            default:
                break;
        }
    }
}

void ObservateurDice::clean_dices(){
    for(int i = 0; i < 8; i++){
        l_dices[i]->setEnabled(false);
    }
}

