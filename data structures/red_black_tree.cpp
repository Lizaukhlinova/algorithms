#include <iostream>
#include <stdexcept>

using namespace std;

struct Node {
    Node * left;
    Node * right;
    Node * parent;
    bool color;
    int key;
    
    Node() : left(NULL), right(NULL), parent(NULL), key(0), color(0) {}
};

class BinaryTree {
private:
    Node * treeRoot;
    
public:
    BinaryTree() {
        treeRoot = NULL;
    }
    
    void leftRotate(Node * x) {
        Node * y = x->right;
        x->right = y->left;
        if (y->left != NULL)
            y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == NULL)
            treeRoot = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
        y->left = x;
        x->parent = y;
    }
    
    void rightRotate(Node * x) {
        Node * y = x->left;
        x->left = y->right;
        if (y->right != NULL)
            y->right->parent = x;
        y->parent = x->parent;
        if (x->parent == NULL)
            treeRoot = y;
        else if (x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;
        y->right = x;
        x->parent = y;
    }
    
    
    void rbInsert(int key) {
        Node * temp = insert(key);
        temp->color = 1;
        while (temp->parent != NULL && temp->parent->color == 1 && temp->parent->parent != NULL){
            if (temp->parent->parent->left == temp->parent) {
                Node * y = temp->parent->parent->right;
                if (y != NULL) {
                    if (y->color == 1) {
                        y->color = 0;
                        temp->parent->color = 0;
                        y->parent->color = 1;
                        temp = y->parent;
                    } else {
                        if (temp == temp->parent->right) {
                            temp = temp->parent;
                            leftRotate(temp);
                        }
                        temp->parent->color = 0;
                        temp->parent->parent->color = 1;
                        rightRotate(temp->parent->parent);
                    }
                }
            } else {
                Node * y = temp->parent->parent->left;
                if (y != NULL) {
                    if (y->color == 1) {
                        y->color = 0;
                        temp->parent->color = 0;
                        y->parent->color = 1;
                        temp = y->parent;
                    } else {
                        if (temp == temp->parent->left) {
                            temp = temp->parent;
                            rightRotate(temp);
                        }
                        temp->parent->color = 0;
                        temp->parent->parent->color = 1;
                        leftRotate(temp->parent->parent);
                    }
                }
            }
        }
        treeRoot->color = 0;
    }
    
    Node * insert(int key) {
        if (treeRoot == NULL) {
            treeRoot = new Node;
            treeRoot->key = key;
            return treeRoot;
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
        return temp;
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
    T.rbInsert(5);
    T.rbInsert(1);
    T.rbInsert(10);
    T.rbInsert(2);
    T.rbInsert(22);
    T.rbInsert(12);
    T.rbInsert(7);
    T.rbInsert(9);
    T.rbInsert(6);
    T.del(5);
    T.print();
    cout << endl;
    return 0;
}
