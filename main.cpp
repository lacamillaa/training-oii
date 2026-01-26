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
    return 0;
}