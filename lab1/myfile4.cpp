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
        sum= sum+pow(int(str[i]),3);
    }

    if 

}
