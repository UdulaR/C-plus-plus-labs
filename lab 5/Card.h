#include <iostream>
using namespace std;
#include <cassert> //for assert()

enum color { club, diamond, heart, spade };

class Card {
public:
    Card(color c = club, int v = 1);
    int value() { return val; }
    void write();
private:
    color col;
    int val;
};

/*Constructor*/
Card::Card(color c, int v) {
    assert(v >= 1 && v <= 13); //we use a standard function void assert (int expression)
    //which indicates an error message if the expression is false.
    col = c;
    val = v;
}

//write method
void Card::write(){
    //if else conditions to print val
    if (val==1 || val==14){
        cout << "Ace of ";
    }
    else if( val==11){
        cout << "Jack of ";
    }
    else if( val==12){
        cout << "Queen of ";
    }
    else if( val==13){
        cout << "King of ";
    }
    else{
        cout<<val<<" of ";
    }
    switch (col){ //use switch to check color --> print that color and break
        case club: cout <<"Clubs";break;
        case diamond: cout <<"Diamonds";break;
        case heart: cout <<"Hearts";break;
        case spade: cout <<"Spades";break;
    }
}
