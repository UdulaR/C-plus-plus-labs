using namespace std;
#include <iostream>
#include <string>

//enum for the animal
enum FaceAnimal { crab, penguin, octopus, turtle, walrus };
//enum for background color
enum FaceBackground { red, green, purple, blue, yellow };

class Card{

    public:
    //make CardDeck a friend function
        friend class CardDeck;

    private:
        FaceAnimal animal;
        FaceBackground background;
        bool faceUp = false;

        //constructor
        Card(FaceAnimal a, FaceBackground bg): animal(a), background(bg){};

        //friend function to print 3x3 card
        friend ostream& operator<<(ostream& os, const Card& c);

        //conversion operators
        operator FaceAnimal() const {return animal; };
        operator FaceBackground() const {return background; };

        //gets the number of rows --> always 3
        int getNRows() const{return 3;}

        //over define () operator --> allows to call card object like a function
        string operator() (int row) const;
};


string Card::operator() (int row) const {
    //select card color
    char cardColor;
    switch (background){
        case red: cardColor= 'r'; break;
        case green: cardColor= 'g'; break;
        case purple: cardColor= 'p'; break;
        case blue: cardColor= 'b'; break;
        case yellow: cardColor= 'y'; break;
    }

    //select card animal
    char cardAnimal;
    switch (animal){
        case crab: cardAnimal= 'C'; break;
        case penguin: cardAnimal= 'P'; break;
        case octopus: cardAnimal= 'O'; break;
        case turtle: cardAnimal= 'T'; break;
        case walrus: cardAnimal= 'W'; break;
    }

    //if argument is row 0 create string of length 3 with color of card
    if (row==0){
        return string(3,cardColor);
    }

    //if argument is row 1 create string with middle character being corresponding animal and 2 side characters being color of card
    if (row==1){
        string mid ="";
        mid = mid+cardColor;
        mid = mid+cardAnimal;
        mid = mid+cardColor;
        return mid;
    }

    //if argument is row 2 create string with length 3 with color of card
    if (row==2){
        return string(3,cardColor);
    }

    return "";
    
}

//overdefine << to print card
ostream& operator<<(ostream& os, const Card& c){
    for(int row=0; row<c.getNRows();row++){ //unsure about c.getNRows --> used in sample code but we cant put 3 for simplicity
        os<<c(row)<<endl;
    }
    return os;
}