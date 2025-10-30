#include <cstdlib> 
using namespace std;

class SetInt
{
public:
	SetInt() : elem(NULL), size(0) {};
	SetInt(int[], int);
	~SetInt();
	SetInt(const SetInt&);  // copy constructor
	void add(int);
	void remove(int);
	bool contains(int);
	int nbElem();
	int* tabElem();
private:
	int* elem;
	int size;
	bool containsIn(int n, int&);
};

//constructor
SetInt::SetInt(int *e, int s) // Takes in size and existing array
{
	size = s; // Assign size
	elem = e; // Assign existing array to elem pointer
}

//copy constructor
SetInt::SetInt(const SetInt& s)
{
	size = s.size; // Copy size over
	elem = new int[size]; // Allocate new memory
	int i;
	for (i = 0; i < size; i++){ // Copy ints of s.elem into this elem
		elem[i] = s.elem[i];
	}
}

//destructor
SetInt::~SetInt()
{
	delete[] elem; // Release dynamically allocated memory
}

//add
void SetInt::add(int n)
{
	if (elem == NULL){ // Case 1: Empty list -- initialize and add
		elem = new int[1];
		elem[size] = n;
		size++;
	}
	else if (!contains(n)){ // Case 2: Non-empty list -- add at end (size'th index)
		elem[size] = n;
		size++; // increase size
	}
	
}

//remove
void SetInt::remove(int n) // O(n)
{
	bool shift = false; // indicates that elements of array need to be shifted down
	int i;
	for (i = 0; i < size; i++){
		if (shift){ // If shift is true shift the current element down one index
			elem[i-1] = elem[i];
		}
		if (elem[i] == n){
			if (i == size-1){ // Case 1: n is at end of list -- no shift
				size --;
				break;
			}else{ // Case 2: n is in body of list -- start shifting all elements back one
				shift = true;
			}
		}
	}

	if (shift){ // If we shifted make sure to decrease size of list.
		size--;
	}
}

//contains
bool SetInt::contains(int n)
{
	int i;
	bool res = false; // result value
	for (i = 0; i < size; i++){ // iterate through all integers of elem
		if (elem[i] == n){ // If one equals n, result is true
			res = true;
		}
	}

	return res;

}

//nbElem
int SetInt::nbElem()
{
	return size;
}

//tabElem
int* SetInt::tabElem()
{
	if (size == 0){ // if the set is empty this function must return NULL
		return NULL;
	}else{
		return elem;
	}
}

//containsAux
bool SetInt::containsIn(int n, int& p)
{
	return (elem[p] == n);
}
