/*Ex1b - a3 CSI2372A*/

#include <iostream>
using namespace std;

enum Color { club, diamond, spades, heart };
enum Face { seven, eight, nine, ten, jack, queen, king, ace };

struct Card
{
	Color color;
	Face face;
};

typedef Card Hand[5];

/* testPair() function*/
bool testPair(const Hand& h)
{
	for(int i=0; i<5;i++){
		for(int j=i+1; j<5;j++){
			if(h[i].face==h[j].face){
				return true;
			}
		}
	}
	return false;
	 
}


/*Example of main()*/
int main()
{
	bool testPair(const Hand&);
	Hand myHand = { {club,nine}, {diamond, eight}, {spades, ace}, {spades, jack}, {club, ace} };
	cout << "\nI have at least: " << testPair(myHand) << " pair" << endl;
	return 0;
}



