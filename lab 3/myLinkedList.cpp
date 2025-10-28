/*Ex2 - a3 CSI2372A*/

#include "myLinkedList.h"
#include <cstring>

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
	Evaluation* temp = p;
	int index;
	cout << "After which element you want to insert ? (0 for start): ";
	cin >> index;
	for (int i = 0; i < index-1; i++){
		if (temp != nullptr || temp->next != nullptr){
			temp = temp->next;
		}
	}

	Evaluation* node = new Evaluation;
	cout << "Student Name: ";
	cin.ignore(INT_MAX,'\n');		// ignore line return
	cin.getline(node->student, capacity, '\t');	//seizure of the string
	cin.ignore(INT_MAX,'\n');		// ignore line return
	cout << "Grade: ";
	cin >> node->grade;

	if (p == nullptr){ // Case 1: Empty List
		node->next = p;
		p = node;
	}else if(index == 0){ // Case 2: Adding at the head of an existing List
		node->next = p;
		p = node;
	}else { // Case 3: Insertion into or at the end of an existing List
		node->next = temp->next;
		temp->next = node;
	}
	
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

	Evaluation* prev = p;
	int index;
	cout << "Which element do you want to remove ? (1 for start): ";
	cin >> index;
	for (int i = 1; i < index-1; i++){
		if (prev != nullptr || prev->next != nullptr){
			prev = prev->next;
		}
	}

	Evaluation *current = prev->next; // A current and a previous are kept so we can route the pointer before current to the one after.
	if (p->next == nullptr){ // Case 1: Empty List
		delete p;
		return nullptr;
	}else if(index == 1){ // Case 2: Adding at the head of an existing List
		prev = p;
		p = p->next;
		delete prev;
	}else{ // Case 3: Insertion into or at the end of an existing List
		prev->next = prev->next->next;
		delete current;
	}
	
	return p;




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
		cout<<"Student: "<<p->student<<endl;
		cout<<"The grade is: "<<p->grade<<endl;
		cout<<endl;
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






