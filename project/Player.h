#include <string>
#include <iostream>

enum side = { top, bottom, left, right };

class Player{
    public:
        Player(string name, int rubis, bool isActive, side s);
        string getName();
        void setActive(bool a);
        bool isActive();
        int getNRubis() const;
        void addRubis(const Rubis& r);
        void setDisplayMode(bool endOfGame);
        side getSide();
        void setSide(side s);

    private:
        string name;
        int rubis;
        bool isActive;
        side s;
};