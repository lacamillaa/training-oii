#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> s1;
    set<int> s2({1, 2, 5, 4}); // mette in ordine in automatico il set
    set<int> s3(s2);
    ranges::copy(s2, ostream_iterator<int>(cout, " "));
    return 0;
}