/*myFile1b.h, Ex1 a4 CSI2372A*/


#include <iostream>
using namespace std;

//class
class Student {
	//vairables
	int numID;
	int nbCourses;
	int maxCourses;
	int* List_grades;
	Course** List_courses;
public:
	Student(int, int); 	//constructor
	~Student(); 		//destructor
	double average(); //function that returns average of type double
	int totalHours(); //function that returns totalHours in int
	bool addCourse(Course*, int); //function that returns ture/false after adding course
};

//constructor
Student::Student(int numID, int maxCourses){
	this->numID=numID; //setting objects numID
	this->nbCourses=0; //initalizaing number of courses to 0 for student
	this->maxCourses=maxCourses; //setting max courses
	List_grades = new int[maxCourses]; //dynamically allcoating memmory for list_grades of student
	List_courses = new Course*[maxCourses]; //dynamically allocating memmory for list_courses for Courses

}

//deconstructor that deletes memory locations for dynamically allocated memory 
Student::~Student(){
	delete List_grades;
	delete List_courses;
}

//definning average function
double Student::average(){
	double sum=0; //sum and count  is set to double and orignally initizlaised to 0
	double count=0;
	for(int i=0; i<nbCourses;i++){ //itterates over courses and for each adds grade to sum
		sum=sum+List_grades[i];
		count++; //increment count
	}
	return sum/count; //return average by dividing sum and count
}

//deffinning totalHours function
int Student::totalHours(){
	int total=0; //total initally set to 0
	for(int i=0; i<nbCourses; i++){ //itteratre over number of courses
		total = total+List_courses[i]->getHours(); //for each course get hours and add to total
	}
	return total; //return total
}
//addcourse method
bool Student::addCourse(Course* crs, int grade){
	if(nbCourses<maxCourses){ //check if number of courses are greater than max number of courses
		List_courses[nbCourses]=crs; //add course
		List_grades[nbCourses] = grade; //add grade
		nbCourses++; //incremeant number of courses
		return true; //return true
	}
	return false; //return false
}