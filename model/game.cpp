#include "game.h"
//constructor
Game::Game(unsigned nbPlayers, bool bills, bool dices){

    id_player=0;
    rounds=0;

    for(int i=0;i<6;i++){
        casinos.push_back(new Casino());
    }

    for(unsigned i=0;i<nbPlayers;i++){
        players.push_back(new Player(dices));
    }

    if(bills == true){
        for(int i=0;i<5;i++){
            billets.push_back(100000);
        }
    }

    //bills 60,70,80,90 mil
    for(int i=0;i<5;i++){
        billets.push_back(60000);
        billets.push_back(70000);
        billets.push_back(80000);
        billets.push_back(90000);
    }
    //bills 10,40,50 mil
    for(int i=0;i<6;i++){
        billets.push_back(10000);
        billets.push_back(40000);
        billets.push_back(50000);
    }
    //bills 20,30 mil
    for(int i=0;i<8;i++){
        billets.push_back(20000);
        billets.push_back(30000);
    }

    notifierChangement();
}

Casino & Game::get_casino_at(int i){
    return *casinos[i];
}

Player & Game::get_current_player(){
    return *players[id_player];
}

vector<pair<Color,int>> Game::get_winners(){
    vector<pair<Color,int>> winners;
    vector<Player *>::iterator it;
    it = std::max_element(players.begin(), players.end(),[](Player * p1, Player * p2)
         {
            return p1->get_money() < p2->get_money();
         });
    for(unsigned i=0;i<players.size();i++){
        if((*it)->get_money() == players[i]->get_money()){
            winners.push_back( pair<Color,int>(players[i]->get_color(),players[i]->get_money()));
        }
    }

    return winners;
}

int Game::get_current_round(){
    return rounds;
}

bool Game::isOver(){
    if(rounds > 3){
        return true;
    }
    return false;
}

bool Game::isFinishRound(){
    for(unsigned i=0;i<players.size();i++){
        if(players[i]->restDice() != 0){
            return false;
        }
    }
    return true;
}

//fonctions
void Game::distribute_money(){
    for(int i=0;i<6;i++){
        casinos[i]->add_billets(billets.back());
        billets.pop_back();
        while (casinos[i]->get_money() < 50000){
            casinos[i]->add_billets(billets.back());
            billets.pop_back();
        }
        casinos[i]->order_billets();
    }

    this->notifierChangement();
}

void Game::nextPlayer(){
    players[id_player]->takeout_dices();
    do{
        if (id_player == players.size()-1) {
            id_player = 0;
        }else{
            id_player++;
        }
    }while(players[id_player]->restDice() == 0);

    notifierChangement();
}

void Game::shuffle_money(){
    srand(unsigned(time(nullptr)));
    std::random_shuffle(billets.begin(), billets.end());
}

void Game::shuffle_players(){
    srand(unsigned(time(nullptr)));
    std::random_shuffle(players.begin(), players.end());
}

void Game::give_bill2players(){
    vector<pair<Color,int>> winners;
    vector<Player *>::iterator it;
    int bills;

    for(unsigned i=0;i<casinos.size();i++){
        casinos[i]->eraseDoubles();//to erase we order the dices.
        winners = casinos[i]->get_dices();

        for(unsigned j=0;j<winners.size();j++){
            Color color = winners[j].first;
            it = std::find_if(players.begin(), players.end(),[color](Player * player){
                    return player->get_color() == color;
            });
            //Item exists
            if(casinos[i]->get_billets().size() != 0 && it != players.end()){
                bills = casinos[i]->remove_billet();
                (*it)->set_money((*it)->get_money() + bills);
                casinos[i]->set_winners((*it)->get_color(),bills);
            }else if(casinos[i]->get_billets().size() == 0 && it != players.end()){
                casinos[i]->set_winners((*it)->get_color(),0);
            }
        }

        //return billets to game.
        int size= casinos[i]->get_billets().size();
        for(int j=0;j<size;j++){
            billets.push_back(casinos[i]->remove_billet());
        }

        //clean winners
        casinos[i]->clean_dices();
    }
}

void Game::nextRound(){
    rounds++;
    id_player=0;
}

void Game::throwDices(){
    players[id_player]->throw_dices();
    notifierChangement();
}

void Game::addDicestoCasino(int value){
    vector<Dice*> dices = this->get_current_player().get_dices();

    for(unsigned i=0;i<dices.size();i++){
        if(dices[i]->get_value() == value){
            casinos[value-1]->add_dices(dices[i]->get_color());

            //if the dices is big
            if(dices[i]->is_big() == true){
                casinos[value-1]->add_dices(dices[i]->get_color());
            }

            dices[i]->set_value(0);
            //this->get_current_player().get_dices().erase(dices.begin() + i);
            this->get_current_player().decreaseDice();

        }else{
            //emit if not exits the value.
        }
    }
    notifierChangement();
}

void Game::restore_dices_players(){
    for(unsigned i=0; i < players.size();i++){
        players[i]->restoreDice();
    }
}

