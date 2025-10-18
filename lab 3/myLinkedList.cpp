/*Ex2 - a3 CSI2372A*/

#include "myLinkedList.h"

int main()
{
	int choice;
	int number =0;
	Evaluation* first = nullptr;
	
	do
	{
		cout << endl << endl << "1) Display  of the complete linked list.\n";
		cout << "2) Insert an element\n";
		cout << "3) Remove an element.\n";
		cout << "4) Calculation of the class average.\n";
		cout << "5) Exit the program.\n" << endl << endl;
		cout << "Your choice ??:";
		cin >> choice;

		switch (choice)
		{
		case 1: display(first);
			break;
		case 2: first = add(first, number);
			break;
		case 3: first = remove(first, number);
			break;
		case 4: average(first, number);
			break;
		case 5: exit(0);
		default:
			break;
		}
	} while (1);
	return 0;
}



/*
*add() Function*
**/
Evaluation* add(Evaluation* p, int& number)
{
	Evaluation* node = new Evaluation;
	cout << "Student Name: ";
	cin >> (*node).student;
	cout << "Grade: ";
	cin >> (*node).grade;

	(*node).next=p;
	p=node;

	++number;
	return p;

}


/**
*remove() Function*
**/

Evaluation* remove(Evaluation* p, int& number)
{
	if(p == nullptr){
		cout<<"There are no nodes";
	}

	char nom[capacity];
	cout<<"Student to be removed: ";
	cin>>nom;

	while(p != nullptr){
		if()
	}


	
	--number;
}



/**
*display() Function *
**/
void display(Evaluation* p)
{
	if(p == nullptr){
		cout<<"There are no nodes";
	}

	while(p != nullptr){
		cout<<"Student: "<<(*p).student<<" Grade: "<<(*p).grade<<endl;
		p=p->next;
	}
}



/**
*average() Function *
***/
int average(Evaluation* p, int const& nbre)
{
	if(p == nullptr){
		cout<<"There are no nodes";
		return 0;
	}

	int sum=0;
	while(p != nullptr){
		sum=sum+p->grade;
		
		p=p->next;
	}

	double avg= (double)sum/nbre;
	cout<<"Average: "<<avg<<endl;
	return (int)avg;


}






