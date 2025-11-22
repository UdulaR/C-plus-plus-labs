#include <iostream>
using namespace std;

class Rubis{
    public:
        operator int() const{
            return value;
        }

        friend ostream& operator<<(ostream& output, const Rubis& r);


    private:
        int value;
        Rubis(int val){
            this->value=val;
        }
        friend class RubisDeck;


};

ostream& operator<<(ostream&output, const Rubis& r){
    output<<r.value;
    return output;
}