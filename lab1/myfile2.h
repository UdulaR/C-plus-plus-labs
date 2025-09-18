/*Heather file: myfile2.h*/
#include <iostream>
#include <iomanip>
#include <process.h>

using namespace std;
const double Pi = 3.14159;
char menu(void);
int nvol =0;
int nsur=0;

//taking raidus of type int and calulcating the surface of circle --> also returns number of times it was calculated
int surface(int radius){
    cout << Pi * radius *radius << endl;
    return ++nsur;

}

//taking raidus of type int and height of type int and calulcating the volume of cylinder --> also returns number of times it was calculated

int volume(int radius, int height){
    cout << Pi*radius*radius*height <<endl;
    return ++nvol;
}