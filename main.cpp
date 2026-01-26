#include <algorithm>
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

    ranges::copy(l3, ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << *prev(l3.end()) << " ";
    cout << *next(l3.begin()) << endl;

    l3.assign({ 1, 4, 2, 7, 2 });
    ranges::copy(l3, ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << *l3.rbegin() << " ";
    cout << *prev(l3.rend()) << endl;
    return 0;
}