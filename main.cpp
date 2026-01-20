#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v1; // crea un array vuoto
    vector<int> v2(5); // crea un array di 5 elementi tutti a 0
    vector<int> v3(5, -1); // crea un array di 5 elementi tutti a -1
    vector<int> v4(v2); // crea una copia di v2
    return 0;
}