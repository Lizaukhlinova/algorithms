#include <iostream>
#include <stdexcept>

using namespace std;

struct Node {
    Node * left;
    Node * right;
    Node * parent;
    int key;
    
    Node() : left(NULL), right(NULL), parent(NULL), key(-1) {}
};

class BinaryTree {
private:
    
public:
    Node * treeRoot;
    
    BinaryTree() {
        treeRoot = new Node;
    }
    
    void insert(int key) {
        if (treeRoot->key == -1) {
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
    
    Node * search(Node * root, int k) {
        if (root->key == k) return root;
        if (k < root->key && root->left != NULL)
            search(root->left, k);
        else if (k > root->key && root->right != NULL)
            search(root->right, k);
        return NULL;
    }
    
    Node * minimum(Node * root) {
        if (root->left == NULL) return treeRoot;
        Node * temp = root->left;
        while (temp->left != NULL)
            temp = temp->left;
        return temp;
    }
    
    Node * maximum(Node * root) {
        if (root->right == NULL) return treeRoot;
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
};

int main() {
    BinaryTree T;
    T.insert(5);
    T.insert(1);
    T.insert(10);
    T.insert(2);
    T.insert(22);
    T.inorderTreeWalk(T.treeRoot);
    cout << endl;
    return 0;
}
