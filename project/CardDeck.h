#include "Card.h"
#include "DeckFactory.h"
#ifndef CARD_DECK_H
#define CARD_DECK_H

class CardDeck : public DeckFactory <Card>{

    public:
    //deck created for entire program
        static CardDeck& make_CardDeck(){
            static CardDeck cdeck; //calls CardDeck constructor to create cards
            return cdeck;
        }

    private:
    //creating a 5x5 cardeck
        CardDeck(){
            for(int i=0; i<=4;i++){ //for animal
                for(int j=0; j<=4;j++){ //for background
                    add(new Card(static_cast<FaceAnimal>(i),static_cast<FaceBackground>(j))); //cast to data type
                }
            }
            //shuffle cards after making
            shuffle();

        }



};
#endif