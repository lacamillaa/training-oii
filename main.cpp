#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v1; // crea un array vuoto
    vector<int> v2(5); // crea un array di 5 elementi tutti a 0
    vector<int> v3(5, -1); // crea un array di 5 elementi tutti a -1
    vector<int> v4(v2); // crea una copia di v2

    // 1. il vettore conterrà 3 elementi uguali a 0
    v1.assign(3,0);
    for (int i : v1) {
        cout << i << " ";
    }
    cout << endl;
    // 2. il vettore conterrà tutti gli elementi di v3
    v1.assign(v3.begin(), v3.end());
    for (int i : v1) {
        cout << i << " ";
    }
    cout << endl;
    // 3. il vettore conterrà tutti gli elementi nella lista
    v1.assign({3, 5, 6, 10, 2});
    for (int i : v1) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}