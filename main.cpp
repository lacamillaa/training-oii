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

    auto rsa1 = map.insert_or_assign('Z', 0);
    // se 'Z' esiste: modifica il valore assegnato a 'Z'
    // altrimenti crea una nuova chiave 'Z' con valore 0
    // rsa1.second == true se il valore è stato inserito
    // rsa1.second == false se il valore è stato assegnato
    if (!rsa1.second) {
        cout << rsa1.first->first << " è stato assegnato" << endl;
    }
    auto rsa2 = map.insert_or_assign('y', 10);
    if (rsa2.second) {
        cout << rsa2.first->first << " è stato inserito" << endl;
    }
    map.insert_or_assign('b', 10);
    map.insert(pair<char, int>('b', 2)); // insert NON modifica il valore di chiave già esistente
    print(map);

    map.erase('Y');
    map.erase(map.begin());
    // map.erase(map.begin(), map.end());
    print(map);

    cout << map.count('X') << " "; // 1
    cout << map.count('c') << " "; // 0
    cout << endl;
    if (map.contains('Z')) {
        cout << map.find('Z')->first << " : " << map.find('Z')->second << endl;
    }
    auto pt = map.find('l');
    if (pt == map.end()) {
        cout << 'l' << " NON è stato trovato" << endl;
    }

    auto lb1 = map.lower_bound('F'); // primo elemento con chiave >= F
    cout << lb1->first << " : " << lb1->second << endl;
    auto ub1 = map.upper_bound('y'); // primo elemento con chiave > y
    if (ub1 == map.end()) {
        cout << 'y' << " è la chiave massima" << endl;
    }
    auto [less, more] = map.equal_range('c');
    // less => map.lower_bound('c')
    // more => map.upper_bound('c')
    cout << less->second << " - " << more->second << endl;
    auto [less2, more2] = map.equal_range('a');
    cout << less2->second << " - " << more2->second << endl;
    return 0;
}