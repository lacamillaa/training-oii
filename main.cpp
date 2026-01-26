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
    return 0;
}