/*Heather file: myfile2.h*/
#include <iostream>
#include <iomanip>
#include <process.h>

using namespace std;
const double Pi = 3.14159;
char menu(void);
int nvol =0;
int nsur=0;

int surface(int radius){
    cout << Pi * radius *radius << endl;
    return ++nsur;

}

int volume(int radius, int height){
    cout << Pi*radius*radius*height <<endl;
    return ++nvol;
}