#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

void print(const map<char, int>& m) { // il & evita che venga passata una copia di m alla funzione
    for (auto i : m) {
        cout << i.first << " : " << i.second << endl;
    }
}

int main() {
    map<char, int> map;
    for (int i = 65; i < 91; i++) {
        map[i] = i; // l'operatore [] costruisce la chiave se non esiste
    }
    print(map);
    return 0;
}