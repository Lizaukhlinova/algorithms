#include <iostream>

using namespace std;

void merge(int * a, int p, int mid, int r) {
    int it1 = 0;
    int it2 = 0;
    int buffer[r - p];
    while (p + it1 < mid && mid + it2 < r) {
        if (a[p + it1] <= a[mid + it2]) {
            buffer[it1 + it2] = a[p + it1];
            it1++;
        } else {
            buffer[it1 + it2] = a[mid + it2];
            it2++;
        }
    }
    
    while (p + it1 < mid) {
        buffer[it1 + it2] = a[p + it1];
        it1++;
    }

    while (mid + it2 < r) {
        buffer[it1 + it2] = a[mid + it2];
        it2++;
    }
    
    for (int k = p; k < r; k++)
        a[k] = buffer[k - p];
}

void mergeSort (int * a, int p, int r) {
    if (p + 1 < r) {
        int mid = (p + r) / 2;
        mergeSort(a, p, mid);
        mergeSort(a, mid, r);
        merge(a, p, mid, r);
    }
}

int main( ) {
    int a[] = {4, 6, 8, 2, 0, 14, 22};
    mergeSort(a, 0, 6);
    return 0;
}
