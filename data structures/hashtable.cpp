#include <iostream>
#include <stdexcept>

using namespace std;

struct Node {
    Node * next;
    Node * prev;
    int data;
    
    Node() : next(NULL), prev(NULL) {}
};

class hashtable {
private:
    Node ** T;
    int size;
public:
    hashtable(int s) {
        size = s;
        T = new Node * [size];
        for (int i = 0; i < size; i++)
            T[i] = new Node;
    }
    
    ~hashtable() {
        for (int i = 0; i < size; i++)
            delete T[i];
        delete [] T;
    }
    
    void insertKey(int key) {
        int h = key % size;
        Node * temp = new Node;
        temp->data = key;
        temp->next = T[h]->next;
        T[h]->next = temp;
        temp->prev = T[h];
        if (temp->next != NULL)
            temp->next->prev = temp;
    }
    
    void deleteKey(int key) {
        Node * temp = searchKey(key);
        if (temp == NULL) {
            cout << "No element with key " << key << endl;
            return;
        }
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
        delete temp;
    }
    
    Node * searchKey(int key) {
        int h = key % size;
        Node * temp = T[h];
        while (temp->next != NULL && temp->next->data != key)
            temp = temp->next;
        return temp->next;
    }
    
    void print() {
        for (int i = 0; i < size; i++) {
            Node * temp = T[i];
            cout << i << ": ";
            while (temp->next != NULL) {
                cout << temp->next->data << ' ';
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    hashtable H(13);
    H.insertKey(2);
    H.insertKey(15);
    H.insertKey(7);
    H.insertKey(7);
    H.print();
    H.deleteKey(2);
    H.deleteKey(7);
    H.print();
    return 0;
}
