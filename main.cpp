#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> l1;
    list<int> l2(7);
    list<int> l3(6, 4);
    list<int> l4(l2);

    cout << l2.front() << " "; // restituisce il primo elemento
    cout << l2.back() << endl; // restituisce l'ultimo elemento
    return 0;
}