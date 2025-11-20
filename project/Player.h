#include <string>
#include <iostream>
using namespace std;

enum Side { top, bottom, left, right };

class Player{
    public:
        Player(string name, int rubis, bool isActive, Side s);
        string getName();
        void setActive(bool a);
        bool isActive();
        int getNRubis() const;
        void addRubis(const Rubis& r);
        void setDisplayMode(bool endOfGame);
        Side getSide();
        void setSide(Side s);

    private:
        string name;
        int rubis;
        bool isActive;
        Side s;
};