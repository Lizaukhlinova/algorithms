#include <iostream>

using namespace std;

int partition (int * a, int p, int r) {
    int x = a[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (a[j] <= x) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[r], a[i + 1]);
    return i + 1;
}

void quicksort (int * a, int p, int r) {
    if (p < r) {
        int q = partition(a, p, r);
        quicksort(a, p, q - 1);
        quicksort(a, q + 1, r);
    }
}

//take random element as pivot
int randPartiotion (int * a, int p, int r) {
    int i = rand() % (r - p + 1) + p;
    swap(a[i], a[r]);
    partition(a, p, r);
}

void randQuicksort (int * a, int p, int r) {
    if (p < r) {
        int q = randPartiotion(a, p, r);
        randQuicksort(a, p, q - 1);
        randQuicksort(a, q + 1, r);
    }
}

int main( ) {
    int a[] = {4, 6, 8, 2, 0, 14, 22};
    quicksort(a, 0, 6);
    return 0;
}
