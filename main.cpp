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

    // restituisce una pair<iterator, bool> p
    // p.first -> puntatore alla pair inserita
    // p.second -> bool (esito dell'inserimento)
    auto rs1 = map.insert(pair<char, int>('a', 'a'));
    if (rs1.second) {
        cout << rs1.first->first << " è stato inserito" << endl;
    }
    auto rs2 = map.insert(pair<char, int>('B', 'B'));
    if (!rs2.second) {
        cout << rs2.first->first << " NON è stato inserito" << endl;
    }

    return 0;
}