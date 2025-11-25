#include "Rubis.h"
#include "DeckFactory.h"

class RubisDeck : public DeckFactory <Rubis>{
    //only one rubis deck created per program run
    public:
        static RubisDeck& make_RubisDeck(){
            static RubisDeck rdeck;
            return rdeck;
        }


    private:
        //create 7 cards
        RubisDeck(){
            //3 cards with 1 rubis 
            add(new Rubis(1));
            add(new Rubis(1));
            add(new Rubis(1));

            //2 cards with 2 rubis
            add(new Rubis(2));
            add(new Rubis(2));

            //1 card with 3 rubis
            add(new Rubis(3));

            //1 card with 4 rubis
            add(new Rubis(4));
            // shuffle cards once created
            shuffle();


        }

};