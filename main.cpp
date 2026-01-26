#include <algorithm>
#include <iostream>
#include <forward_list>

using namespace std;

int main() {
    forward_list<int> fl1; // forward_list vuota
    forward_list<int> fl2(7); // forward_list di 7 elementi inizializzati a 0
    forward_list<int> fl3(7, -3); // 7 elementi inizializzati a -3
    forward_list<int> fl4(fl2); // copia di fl2
    ranges::copy(fl4, ostream_iterator<int>(cout, " "));
    cout << endl;

    fl1.assign(5, -2); // 5 elementi assegnati a -2
    fl1.assign({1, 2, 3, 4, 5}); // copia la lista in fl1
    fl2.assign(fl1.begin(), fl1.end()); // copia fl1 in fl2
    ranges::copy(fl2, ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << fl1.front() << " ";
    cout << *fl1.before_begin() << " ";
    cout << *fl1.begin() << " ";
    cout << endl;
    // fl1.end() non è dereferenziabile

    cout << *next(fl1.begin()) << endl; // puntatore all'elemento dopo begin()

    fl1.insert_after(fl1.begin(), 4); // inserisce 4 dopo il primo elemento
    fl1.insert_after(fl1.before_begin(), 4, 5); // inserisce 4 volte 5 all'inizio
    fl1.insert_after(fl1.before_begin(), { 3, 2, 1 }); // inserisce la lista data all'inizio
    ranges::copy(fl1, ostream_iterator<int>(cout, " "));

    return 0;
}