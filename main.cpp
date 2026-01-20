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

    auto f = *(v1.begin()); // begin -> puntatore al primo elemento valido
    cout << f << " "; // 3
    auto e = *(v1.end()); // end -> puntatore al primo elemento non valido
    cout << e << " "; // valore casuale
    auto l = *(v1.rbegin()); // rbegin -> ultimo elemento
    cout << l << " ";
    auto n = *(v1.rend());
    cout << n << " "; // rend -> puntatore all'elemento precedente al primo
    cout << endl;
    
    return 0;
}