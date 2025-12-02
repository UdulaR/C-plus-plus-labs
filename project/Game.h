using namespace std;
#include <iostream>
#include <string>
#include "Board.h"
#include "Player.h"
#include <vector>
#include <optional>

class Game{
    public:
        Game();
        int getRound() const ; // returns a number between 0 and 6 corresponding to the current round of the game
        void addPlayer( const Player& ) ; // which adds a Player to this game.
        Player& getPlayer( Side ) const;
        const Card* getPreviousCard() const ;
        const Card* getCurrentCard() const ;
        void setCurrentCard( const Card*) ;
        Card* getCard( const Letter&, const Number& ); // which calls the corresponding method in Board.
        void setCard( const Letter&, const Number&, Card* ) ; // which calls the corresponding method in Board. 
        bool getMode();
        void setMode(bool);
    private:
        int round = 0;
        vector<Player> players;
        Board b;
        bool isExpert = false;
        friend ostream& operator<<(ostream& os, const Game& g){
                os<<g.b;
                os<<g.players.size();
                for (int i = 0; i < g.players.size(); i++){
                    os<<"TEST";
        //     //     os<<g.players[i];
                }
            
        }
};

Game::Game(){

}

int Game::getRound() const {
    return round;
}
void Game::addPlayer( const Player& p ){
    players.push_back(p);
}

Player& Game::getPlayer( Side s ) const {
    for (Player p : players) { // Iterate through vector for player on side s
        if (p.getSide() == s){
            return p;
        }
    }
    throw std::runtime_error ("No player in that spot");
}
const Card* Game::getPreviousCard() const{ // iterator starts at end of recent plays, moves one back, then returns that card
    auto i = b.getCardPlays().rbegin();
    i++;
    return b.getCard(i->first, i->second);
}
const Card* Game::getCurrentCard() const{ // Iterator starts at end of recent plays and returns that card
    auto i = b.getCardPlays().rbegin();
    return b.getCard(i->first, i->second);
}
void Game::setCurrentCard( const Card* c) { // **
    // b.getCardPlays().push_back(ts);
}
Card* Game::getCard( const Letter& l, const Number& n ){
    b.getCard(l, n);
}
void Game::setCard( const Letter& l , const Number& n, Card* c ) {
    b.setCard(l, n, c);
}

bool Game::getMode(){
    return isExpert;
}

void Game::setMode(bool m){
    isExpert = m;
}