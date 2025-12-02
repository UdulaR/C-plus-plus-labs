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
        Card* getCard( const Letter&, const Number& );
        void setCard( const Letter&, const Number&, Card* ) ;
        void allFacesDown ();
    private:
        bool expertDisplay = false;
        CardDeck cd = CardDeck::make_CardDeck();
        Card* board[5][5];
        vector<std::pair<Letter,Number>> cardPlays;
        friend ostream& operator<<(ostream& os, const Board& b){
            if (b.expertDisplay){
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
                                os<<"AAA ";
                                
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

Board::Board(){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (i == 2 && j == 2){
                board[i][j] = nullptr;
            }else{
                board[i][j] = cd.getNext();
            }
        }
    }
}

void Board::allFacesDown(){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (i == 2 && j == 2){
                continue;
            }else{
                board[i][j]->faceUp = false;
            }
        }
    }
}
