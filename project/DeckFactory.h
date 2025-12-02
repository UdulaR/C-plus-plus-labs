#include <random>
#include <algorithm> //for random_shuffle
#include <vector>
#ifndef DECK_FACTORY_H
#define DECK_FACTORY_H

using namespace std;

template <class C> class DeckFactory{
    private:
        vector<C*> deck; //deck = vector to store pointers of type C*

    public:
        //constructor
        DeckFactory(){}

        //add element to deck
        void add(C* elem){
            deck.push_back(elem);
        }

        //fuction to shuffle rubis or cards
        void shuffle(){
            random_shuffle(deck.begin(), deck.end());
        }

        //get next card/rubis
        C* getNext(){
            if(deck.empty()){ //if the deck is empty return a null pointer
                return nullptr;
            }
            else{
                C* next = deck.back(); //put last element in vector into next
                deck.pop_back(); //remove last element from vector
                return next;
            }

        }

        //checks if vector is empty
        bool isEmpty() const{
            return deck.empty();
        }
};

#endif