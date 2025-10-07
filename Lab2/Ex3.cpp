/*Ex3.cpp : Ex3 a2 CSI2372A*/

#include <iostream>
using namespace std;

//int** --> pointer to pointer --> represent 2d array
int** triangleInf(int n)
{
	int** triangle = new int*[n]; //create triangle pointer which points to array (size n - each element type = int*)

	for(int i=0; i<n;i++){
		triangle[i] = new int[i+1]; //for every pointer element in triangle create array of 1 more element than i
		//this is what allows to gradually increase the numbers outputted and create right angle shape of trianlge
		for(int j=0; j<=i;j++){
			if(j==0||j==i){
				triangle[i][j]=1; //if we are at first element of triangle or last element in array it is 1
			}else{
				triangle[i][j] = triangle[i-1][j-1]+triangle[i-1][j];//from insturctions: Value of (n-1, p-1) + Value of (n-1, p) if 0 < p ≤ n 

			}
		}

	}
	return triangle; //return trianlge (type int**)
	
}

int main() {
	int** tab; //create pointer to pointer
	const int size = 10; //size of input for triangle methid is 10
	tab = triangleInf(size); //call method and store result in tab
	for (int i = 0; i < size; i++) //iterate over arrays 
	{
		for (int j = 0; j <= i; j++) //iterate over values in array
			cout << tab[i][j] << " "; //print values 
		cout << endl;
	}
}