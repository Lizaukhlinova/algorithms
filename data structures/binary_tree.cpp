#include <iostream>
#include <stdexcept>

using namespace std;

struct Node {
    Node * left;
    Node * right;
    Node * parent;
    int key;
    
    Node() : left(NULL), right(NULL), parent(NULL), key(0) {}
};

class BinaryTree {
private:
    Node * treeRoot;
    
public:
    BinaryTree() {
        treeRoot = NULL;
    }
    
    void insert(int key) {
        if (treeRoot == NULL) {
            treeRoot = new Node;
            treeRoot->key = key;
            return;
        }
        Node * temp = treeRoot;
        Node * p = treeRoot;;
        while (temp != NULL) {
            p = temp;
            if (key <= temp->key)
                temp = temp->left;
            else
                temp = temp->right;
        }
        temp = new Node;
        temp->key = key;
        temp->parent = p;
        if (key <= p->key)
            p->left = temp;
        else
            p->right = temp;
    }
    
    void del(int k) {
        Node * temp = search(treeRoot, k);
        Node * newNode = new Node;
        if (temp->left == NULL || temp->right == NULL) {
            newNode = NULL;
            if (temp->left == NULL && temp->right != NULL) {
                newNode = temp->right;
                temp->right->parent = temp->parent;
            } else if (temp->right == NULL && temp->left != NULL) {
                newNode = temp->left;
                temp->left->parent = temp->parent;
            }
            if (temp->parent != NULL)
                if (temp == temp->parent->left)
                    temp->parent->left = newNode;
                else
                    temp->parent->right = newNode;
        } else {
            newNode = successor(temp);
            int newKey = newNode->key;
            del(newNode->key);
            temp->key = newKey;
        }
    }
    
    Node * search(Node * root, int k) {
        if (root->key == k) return root;
        if (k < root->key && root->left != NULL)
            return search(root->left, k);
        else if (k > root->key && root->right != NULL)
            return search(root->right, k);
        else
            return NULL;
    }
    
    Node * minimum(Node * root) {
        if (root->left == NULL) return root;
        Node * temp = root->left;
        while (temp->left != NULL)
            temp = temp->left;
        return temp;
    }
    
    Node * maximum(Node * root) {
        if (root->right == NULL) return root;
        Node * temp = root->right;
        while (temp->right != NULL)
            temp = temp->right;
        return temp;
    }
    
    Node * successor(Node * root) {
        if (root->right != NULL)
            return minimum(root->right);
        Node * temp = root;
        while (temp->parent != NULL && temp->parent->right == temp)
            temp = temp->parent;
        return temp->parent;
    }

    Node * predecessor(Node * root) {
        if (root->left != NULL)
            return maximum(root->left);
        Node * temp = root;
        while (temp->parent != NULL && temp->parent->left == temp)
            temp = temp->parent;
        return temp->parent;
    }
    
    void inorderTreeWalk(Node * root) {
        if (root->left != NULL) inorderTreeWalk(root->left);
        if (root != NULL) cout << root->key << ' ';
        if (root->right != NULL) inorderTreeWalk(root->right);
    }
    
    void print() {
        inorderTreeWalk(treeRoot);
    }
};

int main() {
    BinaryTree T;
    T.insert(5);
    T.insert(1);
    T.insert(10);
    T.insert(2);
    T.insert(22);
    T.insert(12);
    T.insert(7);
    T.insert(9);
    T.insert(6);
    T.del(5);
    T.print();
    cout << endl;
    return 0;
}
