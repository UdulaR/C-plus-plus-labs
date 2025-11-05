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
    switch (col){ //use switch to check color --> print that color and break
        case club: cout <<"club";break;
        case diamond: cout <<"diamond";break;
        case heart: cout <<"heart";break;
        case spade: cout <<"spade";break;
    }
    //if else conditions to print val
    if (val==1 || val==14){
        cout << "Ace";
    }
    else if( val=11){
        cout << "Jack";
    }
    else if( val=12){
        cout << "Queen";
    }
    else if( val=13){
        cout << "King";
    }
    else{
        cout<<val;
    }
}
