using namespace std;
#include <iostream>
#include <string>
#include "Game.h"
#include <vector>
#include <optional>

class Rules{
    public:
        bool isValid(const Game&) ; // returns true is previous and current card match; false otherwise.
        bool gameOver(const Game&); // returns true if the number of rounds has reached 7.
        bool roundOver(const Game&) ; // returns true if there is only one active Player left.
        const Player& Rules::getNextPlayer(const Game& ) ;

    private:

};

bool Rules::isValid(const Game& g) {
    if (g.getPreviousCard() == g.getCurrentCard()){
        return true;
    }else{
        return false;
    }
}
bool Rules::gameOver(const Game& g) {
    if (g.getRound() == 7){
        return true;
    } else{
        return false;
    }
}

bool Rules::roundOver(const Game& g) {
    int numActive = 0;
    for (int i = 0; i < 4; i++){
        if (g.getPlayer((Side)(i)).isActive()){
            numActive++;
        }
    }
    return numActive == 1;
}
const Player& Rules::getNextPlayer(const Game& g){//**
    for(int i=0;i<4;i++){
        const Player& p = g.getPlayer((Side)i);
        if(p.isActive()){
            return p;
        }
        
    }
    throw runtime_error("No active player");

    

}