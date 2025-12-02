using namespace std;
#include <iostream>
#include <string>
#include "Game.h"
#include "Rules.h"

int main() {
    // Ask player to choose game version, number of players and names of players.
    cout<<"Welcome to Memoarrr! Please choose a mode (1: regular | 2: expert)"<<endl;
    int mode;
    cin>>mode;
    Game g;
    if (mode == 2){
        g.setMode(true);
    }

    cout<<"How many players are playing? (1-4)"<<endl;
    int numPlayers;
    cin>>numPlayers;

    // Create the corresponding players, rules, cards and board for the game.
    for (int i = 0; i < numPlayers; i++){
        cout<<"Please enter the name of player "<<i+1<<endl;
        string curName;
        cin>>curName;
        Player p(curName, 0, false, (Side)(i));
        g.addPlayer(p);
    }
    
    // Display game (will show board and all players)
    cout<<g;
    Rules r;
    // while Rules.gameOver is false
    while (!r.gameOver(g)){

    
    // update status of cards in board as face down
    // update status of all players in game as active
        for (int i = 0; i < numPlayers; i++){
            Player p = g.getPlayer((Side)(i));
            p.setActive(true);
        }
    // for each player
    // Temporarily reveal 3 cards directly in front of the player
    // while Rules.roundOver is false
    // # next active player takes a turn
    // get selection of card to turn face up from active player
    // update board in game
    // if Rules.isValid(card) is false
    // # player is no longer part of the current round
    // current player becomes inactive
    // display game
    // Remaining active player receives rubies
    // print players with their number of rubies sorted from least to
    // most rubies
    // Print overall winner
    }
}