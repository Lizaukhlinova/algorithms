#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

//can find median or other order statistic

//input: n distinct numbers and int i, 0 <= i < n
//output: i-th order statistic, element that is larger
//than i - 1 other elements

//runs for O(n) in average

int randPartition(vector <int> & a, int p, int r) {
    int k = rand() % (r - p) + p;
    swap(a[r - 1], a[k]);
    int i = p - 1;
    for (int j = p; j < r - 1; j++) {
        if (a[j] <= a[r - 1]) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[r - 1], a[i + 1]);
    return i + 1;
}

int randSelect(vector <int> & a, int p, int r, int i) {
    if (p >= r - 1)
        return a[p];
    int q = randPartition(a, p, r);
    int k = q - p;
    if (i == k)
        return a[q];
    else if (i < k)
        return randSelect(a, p, q, i);
    else
        return randSelect(a, q + 1, r, i - k);
}


int main( ) {
    srand(time(NULL));
    vector <int> a = {0, 2, 3, 3, 2, 1, 0, 5}; // 0 0 1 2 2 3 3 5
    cout << randSelect (a, 0, 8, 3) << endl; //2
    cout << randSelect (a, 0, 8, 7) << endl; //5
    cout << randSelect (a, 0, 8, 0) << endl; //0
    return 0;
}
