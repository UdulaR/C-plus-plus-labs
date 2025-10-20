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

	if (p == nullptr){
		node->next = p;
		p = node;
	}else {
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

	char nom[capacity];
	cout<<"Student to be removed: ";
	cin>>nom;

	Evaluation *current = p->next;
	Evaluation *prior = p;

	if(strcmp(prior->student,nom) == 0){
		p=prior->next;
		delete prior;
		--number;
		return p;
	}

	while(current != nullptr){
		if(strcmp(current->student, nom)){
			Evaluation* temp = current;
			current=current->next;
			prior=prior->next->next;
			delete temp;
			--number;
			return p;
		}
	}
	cout<<"Student not found";
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
	if(p->student[0] == '\n')
		std::cout << "student has a newline";
	
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






