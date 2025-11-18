template <class C> class DeckFactory<C>{
    void shuffle();
    C* getNext();
    bool isEmpty() const;
}