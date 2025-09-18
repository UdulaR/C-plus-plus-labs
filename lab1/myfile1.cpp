#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    int num;
    float fnum;
    char ch;



    cout << "Size in bytes of a character: " << sizeof(char) << "\n";
    cout << "Size in bytes of a Integer: " << sizeof(int)<< "\n";
    cout << "Size in bytes of a float: " << sizeof(float)<< "\n";
    cout << "Size in bytes of a double: " << sizeof(double)<< "\n";
    cout << "Size in bytes of a short Integer: " << sizeof(short)<< "\n";
    cout << "Size in bytes of a unsigned integer: " << sizeof(unsigned)<< "\n";

    cout << "Enter an Integer: ";
    cin >> num;

    cout << "Number in decimal: " << num << "\n";
    cout << "Number in octal:: " << oct << num << "\n";
    cout << "Number in hexadecimal: " << hex << num << "\n";

    cout << "Enter a real number: ";
    cin >> fnum;
    cout << fnum <<endl;
    cout << hexfloat << fnum <<endl;

    cout << "Enter a character: ";
    cin >> ch;
    cout << ch << endl;
    cout << int(ch)<< endl;




















    return 0;

}