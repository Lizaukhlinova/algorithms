#include <iostream>
#include <stdexcept>

using namespace std;

struct Node {
    Node * next;
    int data;
    
    Node() : next(NULL) {}
};

class queue {
private:
    Node * head;
    Node * tail;
public:
    queue() {
        head = new Node;
        tail = new Node;
    }
    
    void push(int d) {
        Node * temp = new Node;
        temp->data = d;
        
        if (empty()) {
            tail->next = head->next = temp;
        } else {
            tail->next->next = temp;
            tail->next = temp;
        }
    }
    
    int top() {
        if (!empty())
            return head->next->data;
        else
            throw out_of_range("empty queue");
    }
    
    void pop() {
        if (!empty())
            head->next = head->next->next;
        else
            throw out_of_range("empty queue");
    }
    
    void print() {
        Node * temp = head->next;
        while (temp != NULL) {
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << endl;
    }
    
    bool empty() {
        return (head->next == NULL);
    }
};

int main() {
    queue S;
    S.push(5);
    S.push(8);
    S.push(3);
    S.print();
    S.pop();
    S.print();
    return 0;
}
