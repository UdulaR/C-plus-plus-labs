#include <cstdlib>
#include <ctime>
class CardsSet {
public:
    CardsSet() : number(0) {}
    void novSet();
    void shuffle();
    int numCards() { return number; }
    Card take();
    void put(Card k);
    Card lookIn(int no);
    void empty() { number = 0; }
private:
    Card set[52];
    int number;
};

//create set of cards
void CardsSet::novSet(){
    number = 0; //counter to access index
    for (int col = club; col<=spade;col++){ //for each color
        for(int val = 1; val<=13;val++){ //give value
            set[number] = Card((color)col,val); //put it in set and index cnt --> creating Card object with Color and Value arguments
            number++; //increase counter
            
        }
    }
}

//shuffle method
void CardsSet::shuffle(){
    cout<<number<<endl;
    //sets new seed --> ensures different random number generated each time
    srand(time(0)); 
    for(int i=0; i<number;i++){ //iterate over the number of cards
        int j=rand()%number; //give random index between 0 and the size of number (initally going to be 52)
        //swap card positins
        Card tmp = set[i];
        set[i]=set[j];
        set[j]=tmp;
    }
}

//take method
Card CardsSet::take(){
    assert(number>0); //check if number of cards is greater than 0
    Card top = set[0]; //get top card

    //shift other elements left
    for (int i=1; i<number;i++){
        set[i-1]=set[i];
    }
    number--; //reduce the number of cards 
    return top; //return top card

}

//put method
void CardsSet::put(Card c){
    // add c to end of the set
    set[number] = c;
    number++;
}

//lookIn method
Card CardsSet::lookIn(int no){
    //If 1 denotes first card we subtract 1 to reach the proper index
    return set[no-1];
}
