#include <iostream>
#include <vector>

using namespace std;

//counting sort is eligible if all elements are
//nonnegative and less or equal k, k = O(n). Then
//it runs for O(n)

const int k = 5;

vector <int> countingSort (vector <int> a) {
    vector <int> c(k + 1, 0);
    vector <int> b(a.size(), 0);
    for (int i = 0; i < a.size(); i++)
        c[a[i]]++;
    for (int i = 1; i < c.size(); i++)
        c[i] += c[i - 1];
    for (int i = a.size() - 1; i >= 0; i--) {
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }
    return b;
}

int main( ) {
    vector <int> a = {0, 2, 3, 3, 2, 1, 0, 5};
    vector <int> b = countingSort(a);
    for (int i = 0; i < b.size(); i++)
        cout << b[i] << ' ';
    return 0;
}
