#include "observateurcasino.h"
#include "model/game.h"
#include <sstream>

ObservateurCasino::ObservateurCasino(Game *new_game):game{new_game}
{
    this->game->attacher(this);
    for(int i = 0; i < 6; i++){
        l_casinos.append(new QLabel);
        l_casinos[i]->setAlignment(Qt::AlignTop);
        this->addWidget(l_casinos[i]);
    }
    this->rafraichir(this->game);
}

ObservateurCasino::~ObservateurCasino(){
    this->game->detacher(this);
}

void ObservateurCasino::rafraichir(SujetDObservation *game){
    for(int i = 0; i < 6; i++){

        std::string text = ("total: " +  std::to_string(this->game->get_casino_at(i).get_money())
                     + "<br>billets de:" + print_billets(this->game->get_casino_at(i).get_billets())
                     + "<br><br>dés des joueurs:" + print_dices(this->game->get_casino_at(i).get_dices()));
        l_casinos[i]->setText(QString::fromStdString(text));
    }
}

string ObservateurCasino::print_billets(vector<int> billets){
    string text = "";
    for (auto i = billets.begin(); i != billets.end(); i++)
        text = text + "<br>" + std::to_string(*i);
    return text;
}

string ObservateurCasino::print_dices(vector<pair<Color,int>> dices){
    std::ostringstream stream;
    for (unsigned i = 0; i < dices.size(); i++){
        stream << "<br>" << dices[i].second << " " << dices[i].first;

    }
    return stream.str();
}

void ObservateurCasino::clean_label(){
    for(int i = 0; i < 6; i++){
        l_casinos[i]->setText("");
    }
}
