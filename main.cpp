#include <deque>
#include <iostream>

using namespace std;

int main() {
    deque<int> q1;
    deque<int> q2(5);
    deque<int> q3(5, 3);
    deque<int> q4(q2);

    return 0;
}