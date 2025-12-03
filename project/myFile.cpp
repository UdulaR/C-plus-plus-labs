using namespace std;
#include <iostream>
#include <string>
#include "Game.h"
#include "Rules.h"
#include "RubisDeck.h"
#include "Player.h"

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
    RubisDeck& rDeck = RubisDeck::make_RubisDeck(); //create a rubis deck

    // while Rules.gameOver is false
    while (!r.gameOver(g)){
        // update status of cards in board as face down
        g.getBoard().allFacesDown();

        // update status of all players in game as active
            for (int i = 0; i < numPlayers; i++){
                Player p = g.getPlayer((Side)(i));
                p.setActive(true);
            }


        // for each player Temporarily reveal 3 cards directly in front of the player
        for (int i=0; i<numPlayers; i++){
            g.revealThreeForPlayer((Side)i);
        }

        // while Rules.roundOver is false
        while(!r.roundOver(g)){
            // # next active player takes a turn
            const Player& current = r.getNextPlayer(g);
            // get selection of card to turn face up from active player
            cout <<"Current player = " << current.getName();
            cout <<"Choose a card Letter then Number: "<<endl;

            char let;
            int num;
            //take in card
            cin >> let >> num;

            //get enum value
            Letter letter =Letter(let-'A');
            Number number =Number(num-1);



            // update board in game
            g.getBoard().turnFaceUp(letter,number);
            //HOW TO UPDATE BOARD --> USE VECTOR IN GAME ##############################

            // if Rules.isValid(card) is false
            if(!r.isValid(g)){
                // # player is no longer part of the current round
                // current player becomes inactive
                cout<<current.getName() <<" out for round";
                current.setActive(false); //CANT SET CURRENT PLAYER TO FALSE#########################
            }
            // display game
            cout<<g;

        }

        // Remaining active player receives rubies
        for(int i=0;i<numPlayers;i++){
            Player& p = g.getPlayer((Side)i);
            if(p.isActive()){
                Rubis* r= rDeck.getNext();
                p.addRubis(*r);

            }
        }





            // print players with their number of rubies sorted from least to
            // most rubies
            // Print overall winner
        
        
    }
}