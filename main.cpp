#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

void print(const map<char, int>& m) { // il & evita che venga passata una copia di m alla funzione
    for (auto i : m) {
        cout << i.first << " : " << i.second << " - ";
    }
    cout << endl;
}

int main() {
    map<char, int> map;
    for (int i = 65; i < 91; i++) {
        map[i] = i; // l'operatore [] costruisce la chiave se non esiste
    }
    print(map);

    for (int i = 65; i < 91; i++) {
        cout << map[i] << endl;
    }

    auto it = map.begin();
    cout << it->first << " : " << it->second << endl;
    auto itr = map.rbegin();
    cout << (*itr).first << " : " << (*itr).second << endl;

    cout << map.size() << endl; // numero di coppie key-value

    return 0;
}