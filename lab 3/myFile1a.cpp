/*Ex1a - a3 CSI2372A*/

#include <iostream>
using namespace std;

//enum with of shpaes and numbers
enum Color { club, diamond, spades, heart };
enum Face { seven, eight, nine, ten, jack, queen, king, ace };

//struct for card
struct Card{
	Color color;
	Face face;
};

int main(){
	Card game[32]; //array of type card holding 32 cards
	//YOUR CODE HERE
	int k=0;
	for(int i=0; i<4; i++){ //iterate over each color and assocaite a face to it
		for(int j=0; j<8; j++){
			game[k].color = static_cast<Color>(i); //use static cast to turn color/face to correspodning int value
			game[k].face = static_cast<Face>(j);
			++k;
		}
	}

	//test --> prints int values corresponding to cards
	// for (int t=0; t<32; t++){
	// 	cout<<"Card "<< t+1 << ": color=" << game[t].color << " face=" <<game[t].face <<endl;
	// }

	
}

