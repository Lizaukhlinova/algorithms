#include <iostream>

using namespace std;

struct Node {
    Node * next;
    int data;
    
    Node() : next(NULL) {}
};

class stack {
private:
    Node * head;
public:
    stack() {
        head = new Node;
    }

    void push(int d) {
        Node * temp = new Node;
        temp->data = d;
        temp->next = head->next;
        head->next = temp;
    }
    
    int top() {
        return head->next->data;
    }
    
    void pop() {
        if (!empty()) {
            head->next = head->next->next;
        }
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
        return head->next == NULL;
    }
};

int main() {
    stack S;
    S.push(6);
    S.push(3);
    S.pop();
    S.print();
    return 0;
}
