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
        Board& getBoard(); //getBoard --> modifable
        const Board& getBoard() const; //getboard --> not modifying 
        void revealThreeForPlayer(Side s);

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

//getting Board methods
Board& Game::getBoard(){
    return b;
}

const Board& Game::getBoard() const{
    return b;
}





//method that reveals 3 cards
void Game::revealThreeForPlayer(Side s){
    switch(s){
        case top_side: //A 1-3
            b.turnFaceUp((Letter)0, (Number)1);
            b.turnFaceUp((Letter)0, (Number)2);
            b.turnFaceUp((Letter)0, (Number)3);
            break;

        case bottom_side: //E 1-3
            b.turnFaceUp((Letter)4, (Number)1);
            b.turnFaceUp((Letter)4, (Number)2);
            b.turnFaceUp((Letter)4, (Number)3);
            break;

        case left_side://1 B-D
            b.turnFaceUp((Letter)1, (Number)0);
            b.turnFaceUp((Letter)2, (Number)0);
            b.turnFaceUp((Letter)3, (Number)0);
            break;

        case right_side: //5 B-D
            b.turnFaceUp((Letter)1, (Number)4);
            b.turnFaceUp((Letter)2, (Number)4);
            b.turnFaceUp((Letter)3, (Number)4);
            break;

        

    }
}



