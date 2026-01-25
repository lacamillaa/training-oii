#include <deque>
#include <iostream>

using namespace std;

int main() {
    deque<int> q1;
    deque<int> q2(5);
    deque<int> q3(5, 3);
    deque<int> q4(q2);

    q2.insert(q2.begin(), q3.begin(), q3.end()); // copia q3 all'inizio di q2
    q2.insert(q2.end(), 5); // inserisci prima di end()
    q2.insert(q2.begin(), 10, 8); // inserisce 8 per 10 volte
    q2.insert(q2.end(), {1, 2, 3, 4, 5, 6, 7, 8, 9}); // inserisce la lista alla fine

    for (auto i : q2) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}