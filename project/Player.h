#include <string>
#include <iostream>
#include "Rubis.h"
using namespace std;

class Rubis; //forward declartion --> tells Player class Rubis class exists

enum Side { top_side, bottom_side, left_side, right_side }; //enum for sides --> where players sit --> used to determine what 3 cards player can see

class Player{
    public:
        Player(string name, int rubis, bool isActive, Side s);
        string getName() const;
        void setActive(bool a);
        bool isActive() const;

        int getNRubis() const;
        void addRubis(const Rubis& r);

        void setDisplayMode(bool endOfGame);

        Side getSide() const;
        void setSide(Side s);

        friend ostream& operator<<(ostream& output, const Player& p); //operator<< over defintion is a friend function

    private:
        string name;
        int rubis;
        bool activity_status; //activity status of player
        Side side;
        bool game_status; //do we need to add this as an argument 
};

//Constructor
Player::Player(string name, int rubis, bool isActive, Side s){
    this->name=name;
    this->rubis=rubis;
    this->activity_status=isActive;
    this->side=s;
    this->game_status=false;
}

//returns the name of the player
string Player::getName() const{
    return name;
}

//sets activity of the player
void Player::setActive(bool a){
    activity_status=a;
}

//checks activity of player
bool Player::isActive() const{
    return activity_status;
}

//gets the number of rubis of a player
int Player::getNRubis() const{
    return rubis;
}

//increments the number of rubis a player has --> pass by reference
void Player::addRubis(const Rubis& r){
    rubis += int(r);
}

//sets the game status --> whether game has ended or not
void Player::setDisplayMode(bool endOfGame){
    game_status=endOfGame;
}

//sets side for player
void Player::setSide(Side s){
    side=s;
}

//gets the side of a player
Side Player::getSide() const{
    return side;
}

//over define << operator
ostream& operator<<(ostream& output, const Player& p){
    //check games status --> if false (game not currently playing) --> print side of player with activity status
    if(!p.game_status){
        output<<p.name<<": ";

        switch(p.side){
            case top_side: output<<"top"; break;
            case bottom_side: output<<"bottom"; break;
            case left_side: output<<"left"; break;
            case right_side: output<<"right"; break;
        }
        output<<" ("<<(p.activity_status?"active":"inactive")<<")";
    }
    else{
        //if game is in progress print the number of rubis the player has
        output<<p.name<<": "<<p.rubis<<" rubis";
    }

    return output;

}
