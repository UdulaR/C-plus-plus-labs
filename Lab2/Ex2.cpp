/*Ex2.cpp : Ex2 a2 CSI2372A*/

#include "Ex2.h"

int main() {
	int myArray[sizeArray] = { 2,4,88,20,3,55,87,134,2,5 };

	cout << "Displaying the unsorted array :" << endl;
	for (int i = 0; i < sizeArray; i++) {
		cout << myArray[i] << " ";
	}
	cout <<  endl << endl;
	sort(myArray, sizeArray);
	cout << "Displaying the sorted array :" << endl;
	for (int i = 0; i < sizeArray; i++) {
		cout << myArray[i] << " ";
	}
	cout << endl;
}

//insertion sort
void sort(int a[], int size)//insert array size and size of array
{
	for(int i=1; i<size; i++){ //for loop to iterate over each value starting at index 1 since index 0 already in correct position
		int current=a[i]; //setting current element value
		int j = i-1; //setting j as 1 less than current index of current value to compare

		while (j>=0 && a[j] >current){ //while loop runs if first condition met and previous element bigger than current
			a[j+1]=a[j];//set current index value to that of previous element
			j=j-1;
		}
		a[j+1]=current; //set previous element value to current --> only matters if we swapped values
	}
	
}