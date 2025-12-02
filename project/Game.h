using namespace std;
#include <iostream>
#include <string>
#include "Board.h"
#include "Player.h"
#include <vector>
#include <optional>

class Game{
    public:
        int getRound(); // returns a number between 0 and 6 corresponding to the current round of the game
        void addPlayer( const Player& ) ; // which adds a Player to this game.
        Player& getPlayer( Side ) ;
        const Card* getPreviousCard() ;
        const Card* getCurrentCard() ;
        void setCurrentCard( const Card*) ;
        Card* getCard( const Letter&, const Number& ); // which calls the corresponding method in Board.
        void setCard( const Letter&, const Number&, Card* ) ; // which calls the corresponding method in Board. 
    private:
        int round = 0;
        std::vector<Player> players;
        Board b;
};



int Game::getRound(){
    return round;
}
void Game::addPlayer( const Player& p ){
    players.push_back(p);
}

Player& Game::getPlayer( Side s ) {
    for (Player p : players) { // Iterate through vector for player on side s
        if (p.getSide() == s){
            return p;
        }
    }
    throw std::runtime_error ("No player in that spot");
}
const Card* Game::getPreviousCard(){ // iterator starts at end of recent plays, moves one back, then returns that card
    auto i = b.getCardPlays().rbegin();
    i++;
    return b.getCard(i->first, i->second);
}
const Card* Game::getCurrentCard() { // Iterator starts at end of recent plays and returns that card
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