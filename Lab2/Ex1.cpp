#include <iostream>
using namespace std;
// automatic, static and dynamic(with new created during run time)

int main(void) {
    int tab[10];
    int* p;
    for (int i = 0;i < 10;i++) {
        tab[i] = i * i;
    }
    cout << tab[2] << endl; //print 4

    tab[2] = tab[1];
    cout << tab[2] << endl; //print 1


    tab[2] = *(tab + 1); //same as &tab[0+1] = tab[1]
    cout << tab[2]<<endl; //print 1

    *(tab + 2) = tab[1];
    cout << tab[2]<<endl; //print 1

    *(tab + 2) = *(tab + 1);
    cout << tab[2]<<endl; //print 1
    p = &tab[0];
    
    p = tab + 1; //tab byitself is pointer to memory location = &tab[0]
    
    tab[4] = *p;
    cout << tab[4] <<endl;
}
