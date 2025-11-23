#include <iostream>
using namespace std;


class Rubis{
    public:
    //conversion operator to type int
        operator int() const{
            return value;
        }

        friend ostream& operator<<(ostream& output, const Rubis& r);


    private:
        int value;
        //rubis constructor
        Rubis(int val){
            this->value=val;
        }
        //make RubisDeck a friend class
        friend class RubisDeck;


};

//independent freind function that over defines << --> prints rubis 
ostream& operator<<(ostream&output, const Rubis& r){
    output<<r.value;
    return output;
}