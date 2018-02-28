#include <iostream>
#include <vector>
#include <exception>

using namespace std;

class Heap {
private:
    vector <int> heap;
public:
    int leftChild (int i) {
        return 2 * i + 1;
    }
    
    int rightChild (int i) {
        return 2 * i + 2;
    }
    
    int parent (int i) {
        return (i - 1) / 2;
    }
    
    void heapify (int i) {
        int left = leftChild(i);
        int right = rightChild(i);
        int maxIndex = i;
        if (left < heap.size() && heap[left] > heap[maxIndex])
            maxIndex = left;
        if (right < heap.size() && heap[right] > heap[maxIndex])
            maxIndex = right;
        if (maxIndex != i) {
            swap(heap[maxIndex], heap[i]);
            heapify(maxIndex);
        }
    }
    
    void buildHeap (vector <int> a) {
        if (!a.size())
            return;
        heap = a;
        for (int i = heap.size() / 2 - 1; i >= 0; i--) {
            heapify(i);
        }
    }
    
    //priority queue
    int extractMax() {
        if (heap.empty())
            throw out_of_range("empty heap");
        int a = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
        return a;
    }

    void insert (int a) {
        heap.push_back(a);
        int i = heap.size() - 1;
        int p = parent(i);
        while (i > 0 && heap[p] < heap[i]) {
            swap(heap[p], heap[i]);
            i = p;
            p = parent(i);
        }
    }
    
    //sorting
    void heapSort (vector <int> & a) {
        buildHeap(a);
        int size = heap.size();
        for (int i = 0; i < size; i++) {
            a[i] = extractMax();
        }
    }
    
    void printHeap() {
        if (!heap.size())
            return;
        for (int i = 0; i < heap.size(); i++)
            cout << heap[i] << ' ';
        cout << endl;
    }
};

int main( ) {
    vector <int> a = {2, 4, 6, 8, 14, 1, 3};
    
    Heap h;
    h.heapSort(a);
    h.printHeap();
    return 0;
}
