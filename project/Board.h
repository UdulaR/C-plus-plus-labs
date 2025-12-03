using namespace std;
#include <iostream>
#include <string>
#include "Card.h"
#include "CardDeck.h"
#include <vector>

enum Letter { A, B, C, D, E };
enum Number { one, two, three, four, five };

class Board{
    public:
        friend class Card;
        Board();
        bool isFaceUp( const Letter&, const Number&) const ;
        bool turnFaceUp( const Letter&, const Number& );
        bool turnFaceDown( const Letter&, const Number& ) ;
        Card* getCard( const Letter&, const Number& ) const;
        Card* getCard( const int, const int ) const;
        void setCard( const Letter&, const Number&, Card* ) ;
        void allFacesDown ();
        vector<std::pair<Letter,Number>> getCardPlays() const;
        Letter& getLetter( Card* );
        Number& getNumber( Card* );
    private:
        bool expertDisplay = false;
        CardDeck cd = CardDeck::make_CardDeck();
        Card* board[5][5];
        vector<std::pair<Letter,Number>> cardPlays;
        friend ostream& operator<<(ostream& os, const Board& b){
            if (b.expertDisplay){ // EXPERT DISPLAY
                for (int k = 0; k < 3; k++){
                    for (int i = 0; i < b.cardPlays.size(); i++){
                        os<<(*b.board[b.cardPlays[i].first][b.cardPlays[i].second])(k)<<" ";
                    }
                    os<<endl;
                }
            }else{
                for (int i = 0; i < 5; i++){
                    for (int j = 0; j < 3; j++){
                        if (j==1){
                            //row names
                            os<<(char)(65+i)<<" ";
                        } else{
                            os << "  ";
                        }
                        for (int k=0; k < 5; k++){
                            //if middle spot print nothing
                            if (i==2 && k==2){
                                os << "    ";
                            } else{
                                //if card is face up:
                                if ((b.getCard(i, k)->getFaceUp())){
                                    os<<(*b.board[i][k])(j)<<" ";
                                }else{
                                    os<<"zzz ";
                                }
                               
                                //else:
                                
                                //if (b.board[b.cardPlays[i].first][b.cardPlays[i].second]) os<<(*b.board[b.cardPlays[i].first][b.cardPlays[i].second])(k)<<" ";
                            }
                        }
                        os<<endl;
                    }
                    if (i!=4) os<<endl;
                }
                //column names
                os<< "   1   2   3   4   5"<<endl;
            }
            
            return os;
        };
        
};

/**
 * Board constructor--fills 2D array board with cards
 */
Board::Board(){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (i == 2 && j == 2){
                board[i][j] = nullptr; // If middle spot don't fill
            }else{
                if (cd.isEmpty()){
                    std::out_of_range ("no more cards!");
                }
                board[i][j] = cd.getNext();
            }
        }
    }
}

/**
 * sets all cards on the board face down.
 */
void Board::allFacesDown(){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (i == 2 && j == 2){ // If middle spot do nothing
                continue;
            }else{
                board[i][j]->faceUp = false;
            }
        }
    }
}

/**
 * int l: letter position
 * int n: number position
 * returns: The card at the given coordinates on the board
 */
Card* Board::getCard(const int l, const int n) const{
    // Bounds checking
    if (l > 4 || n > 4 || l < 0 || n < 0){
        throw std::out_of_range ("letter or number out of range");
    } else {
        return board[l][n];
    }
}

/**
 * Letter& l: letter position
 * Number& n: number position
 * returns: The card at the given coordinates on the board
 * Converts to int and uses above function.
 */
Card* Board::getCard(const Letter& l, const Number& n) const{
    // Bounds checking
     if (l > 4 || n > 4 || l < 0 || n < 0){
        throw std::out_of_range ("letter or number out of range");
     } else {
        getCard((int)(l), (int)(n));
    }
}

/**
 * Letter& l: letter position of card
 * Number& n: number position of card
 * returns: Whether the card at the position is face up
 */
bool Board::isFaceUp( const Letter& l, const Number& n) const{
    return getCard(l,n)->getFaceUp();
}

/**
 * Letter& l: letter position of card
 * Number& n: number position of card
 * returns: true if the card could be turned face up. False if it was already up.
 */
bool Board::turnFaceUp( const Letter& l, const Number& n ){
    if (getCard(l,n)->getFaceUp()){
        return false;
    } else {
        getCard(l,n)->setFaceUp(true);
    }
    return true;
}

/**
 * Letter& l: letter position of card
 * Number& n: number position of card
 * returns: true if the card could be turned face down. False if it was already down.
 */
bool Board::turnFaceDown( const Letter& l, const Number& n ){
    if (getCard(l,n)->getFaceUp()){
        getCard(l,n)->setFaceUp(false);
    } else {
        return false;
    }
    return true;
}

/**
 * Letter& l: letter position of card
 * Number& n: number position of card
 * Card* c: pointer to a card
 * Sets a card in the given positions to c
 */
void Board::setCard( const Letter& l, const Number& n, Card* c ){
    // Bounds checking
    if (l > 4 || n > 4 || l < 0 || n < 0){
        throw std::out_of_range ("letter or number out of range");
    }else{
        board[l][n] = c;
    }
}

/**
 * returns the vector which stores all the card plays in the game.
 */
vector<std::pair<Letter,Number>> Board::getCardPlays() const{
    return cardPlays;
}