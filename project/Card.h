using namespace std;
#include <iostream>
#include <string>

enum FaceAnimal { crab, penguin, octopus, turtle, walrus };
enum FaceBackground { red, green, purple, blue, yellow };

class Card{

    public:
        friend class CardDeck;
    private:
        FaceAnimal animal;
        FaceBackground background;
        bool faceUp = false;
        Card(FaceAnimal a, FaceBackground bg): animal(a), background(bg){};
        friend ostream& operator<<(ostream& os, const Card& c);
        operator FaceAnimal() const {return animal; };
        operator FaceBackground() const {return background; };
        string operator() (int row) const;
};

string Card::operator() (int row) const {
    
}