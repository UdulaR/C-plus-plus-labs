#include <iostream>
#include <String>
#include <cmath>

using namespace std;

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
