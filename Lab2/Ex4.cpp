/*Ex4.cpp : Ex4 a2 CSI2372A*/


#include <iostream>
using namespace std;

//if a>b return true else false
bool increasing(int a, int b) {
	if(a<b){
        return true;
    }else{
        return false;
    }
}
//if a<b return true else false
bool decreasing(int a, int b) {
	if(a>b){
        return true;
    }else{
        return false;
    }
}

//sorting method
void sorting(int arr[], int len, bool (*compare)(int, int)) {
    int i, j, min, tmp; //initialize vairables
    for (i = 0; i < len; i++) {
        min = i; //set min to be first index

        for (j = i + 1; j < len; j++) { //each iteration of min gets min in unsorted

            if ((*compare)(arr[j],arr[min])) { //call increasing/decreasing function with a=j and b=min
                min = j; //set min to j if if condition returns true
            }
        }
        //change position of values
        tmp = arr[min];
        arr[min] = arr[i];
        arr[i] = tmp;
    }
}
 
int main()
{

	int a1[6] = { 12,234,-35,1234,0, 51 };
	int a2[10] = { 1,24,5,124, -14, 0, -55, 51, 10, 33 };

    //calc length of arrays --> divide by size of first element since sizeof returns size of type in bytes
    int len1= sizeof(a1)/sizeof(a1[0]);
    int len2= sizeof(a2)/sizeof(a2[0]);

    //sorting done for both arrays
    sorting(a1, len1, increasing);
    sorting(a2, len2, decreasing);

    //array in increasing
	cout << "My first array a1 sorted in ascending order:" << endl;
    //for loops iterating over and printing numbers
	for(int i=0; i<len1;i++){
        cout <<a1[i]<<" ";
    }
    cout <<endl;

    //array in decreasing
	cout << "My second array a2 sorted in descending order:" << endl;
    //for loops iterating over and printing numbers
	for (int i=0; i<len2; i++){
        cout<<a2[i]<<" ";
    }
    cout<<endl;

	return 0;
}