#include "casino.h"

//contructor
Casino::Casino(){
    money = 0;
}

//getters
int Casino::get_money()const{
    return money;
}

vector<int> Casino::get_billets()const{
    return billets;
}

vector<pair<Color,int>> Casino::get_dices()const{
    return dices_players;
}

bool Casino::isClean(){
    if(billets.size() == 0){
        return true;
    }
    return false;
}

vector<pair<Color,int>> Casino::get_winners(){
    return winners;
}

//setters
void Casino::set_money(int money){
    this->money = money;
}

void Casino::set_winners(Color color,int money){
    winners.push_back( pair<Color,int>(color, money));
}

//fonctions
void Casino::add_billets(int billet){
    billets.push_back(billet);
    money = money + billet;
}

void Casino::clean_dices(){
    dices_players.clear();
    set_money(0);
}

void Casino::clean_billets(){
    billets.clear();
    set_money(0);
}

void Casino::order_billets(){
    std::sort(billets.begin(), billets.end());
}

void Casino::add_dices(Color color){
    vector<pair<Color, int>>::iterator it;

    it = std::find_if(dices_players.begin(), dices_players.end(),[color](const std::pair<Color, int>& element){ return element.first == color;} );

    if( it != dices_players.end()){
        //Item exists, so increment second (int)
        it->second++;
    }else{
        //Item does not exist, so add it
        dices_players.push_back( pair<Color,int>(color, 1) );
    }
}


bool Casino::sortbysec(const pair<Color,int> &a,const pair<Color,int> &b){
    return (a.second > b.second);
}

void Casino::eraseDoubles(){
    vector<int>::iterator it;
    vector<int> toErase;

    sort(dices_players.begin(), dices_players.end(), sortbysec);//sortbysec must be static

    for (unsigned i=0; i<dices_players.size(); i++){
        for (unsigned j=i+1; j<dices_players.size(); j++){
            if(dices_players[i].second == dices_players[j].second){
                int compare = dices_players[i].second;
                it = std::find_if(toErase.begin(), toErase.end(),[compare](const int & value){
                    return value == compare;
                });

                //if item not exits
                if( it == toErase.end()){
                    toErase.push_back(dices_players[i].second);
                }
            }
        }
    }

    //time to erase
    for(unsigned i = 0; i<toErase.size();i++){
        unsigned j = 0;
        while(j < dices_players.size()){
            if(dices_players[j].second == toErase[i]){
                dices_players.erase(dices_players.begin() + j);
            }else{
                j++;
            }
        }
    }
}

void Casino::clean_winners(){
    winners.clear();
}

int Casino::remove_billet(){
    int _billet = billets.back();
    billets.pop_back();
    return _billet;
}
