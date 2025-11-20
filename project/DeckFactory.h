using namespace std;

template <class C> class DeckFactory{
    void shuffle();
    C* getNext();
    bool isEmpty() const;
};