#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> s1;
    set<int> s2({1, 2, 5, 4}); // mette in ordine in automatico il set
    set<int> s3(s2);
    ranges::copy(s2, ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << *s2.begin() << " ";
    cout << *s2.end() << " ";
    cout << *s2.rbegin() << " ";
    cout << *s2.rend() << " ";
    cout << endl;

    // insert inserisce solo se l'elemento non è già presente
    // result.second == true => l'elemento è stato inserito
    // result.second == false => l'elemento NON è stato inserito
    auto result = s2.insert(5);
    if (result.second) {
        cout << *result.first << " è stato inserito" << endl;
    }
    else {
        cout << *result.first << " non è stato inserito" << endl;
    }
    auto result2 = s2.insert(7);
    if (result2.second) {
        cout << *result2.first << " è stato inserito" << endl;
    }
    else {
        cout << *result2.first << " non è stato inserito" << endl;
    }

    s2.erase(s2.begin());
    s2.erase(7); // elimina l'elemento 7 dal set
    ranges::copy(s2, ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << s2.count(9) << " "; // 0 (9 NON è presente nel set)
    cout << s2.count(2) << endl; // 1 (2 è presente nel set)

    auto p1 = s2.find(2); // puntatore a 2
    auto p2 = s2.find(8); // p2 == end() (8 NON è presente nel set)
    if (p2 == s2.end()) cout << "8 non trovato" << endl;

    if (s2.contains(4)) cout << "s2 contiene 4" << endl;

    s2.insert({3, 7});
    ranges::copy(s2, ostream_iterator<int>(cout, " "));
    cout << endl;
    auto lb1 = s2.lower_bound(5);
    cout << *lb1 << " "; // puntatore al primo elemento >= a 5
    auto lb2 = s2.lower_bound(6);
    cout << *lb2 << " ";

    auto ub1 = s2.upper_bound(4);
    cout << *ub1 << " "; // puntatore al primo elemento > 4
    cout << endl;
    auto ub2 = s2.upper_bound(7); // puntatore al primo elemento > 7
    if (ub2 == s2.end()) cout << "7 è l'elemento massimo" << endl;
    return 0;
}