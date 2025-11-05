/*myFile1a, Ex1 a4 CSI2372A*/

#include <iostream>
using namespace std;

//class
class Course {
    //variables
    int num;
    int hours;
public:
    Course(int, int); 	//constructor
    int getNum(); //getNum function which returns type int
    int getHours(); //getHours function which returns type int
};

//defining constructor
Course::Course(int num, int hours){
    this->num=num; //sets num
    this->hours=hours; //sets hours
}

//getNum function which returns num
int Course::getNum(){
    return num;
}

//getHours function which returns hours
int Course::getHours(){
    return hours;
}


