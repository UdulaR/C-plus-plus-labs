class Player {
public:
    Player(CardsSet& cardPacket, bool isComputer) : packet(cardPacket), computer
    (isComputer) {}
    int play();
private:
    CardsSet inHand;
    CardsSet& packet;
    const bool computer;
    int countPoints();
};

//play method
int Player::play(){
    packet.novSet();
    cout<<packet.numCards();
    Card c = packet.take();
    inHand.put(c);
    cout<<"You get Card: ";
    c.write();
    cout<<endl;
    do{
        char choice;

        cout<<"Your score is "<<countPoints()<<" points."<<endl;
        cout<<"Any additional card? ";
        cin>>choice;

        if (choice == 'n'){
            break;
        }else if (choice == 'y'){
            Card c = packet.take();
            inHand.put(c);
            cout<<"You get Card: ";
            c.write();
            cout<<endl;
        }

    }while(countPoints() < 21);

    return countPoints();
}

//countPoints method
int Player::countPoints(){
    int sum = 0;

    for(int i = 1; i <= inHand.numCards(); i++){
        sum += inHand.lookIn(i).value();
    }
    return sum;
}