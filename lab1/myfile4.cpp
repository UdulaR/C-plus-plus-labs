#include <iostream>
#include <String>
#include <cmath>

using namespace std;

//take input of num --> convert to string --> iterate over string for each index to calculate ^3 of each value and sum all of them
// if it is = to original value then outputs "this is an Angstrom" else "this is not an angstrom number"
int main(){
    int sum=0;
    int num;
    string str;
    cout << "Please, enter your number: ";
    cin >> num;
    str= to_string(num);

    for(int i=0; i<str.length(); i++){
        sum= sum+pow(str[i] - '0', 3);
        
    }
    if (sum == num){
        cout << "This is an Angstrom number" << endl;
    }
    else{
        cout << "This is not an Angstrom number" << endl;
    }

}
