#include <iostream>
#include <stack>
using namespace std;

class BST {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };
    
    Node* root;
    
    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data) node->left = insert(node->left, val);
        else if (val > node->data) node->right = insert(node->right, val);
        return node;
    }
    
    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
    
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
    
    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
    
    bool search(Node* node, int val) {
        if (!node) return false;
        if (val == node->data) return true;
        if (val < node->data) return search(node->left, val);
        return search(node->right, val);
    }
    
public:
    BST() : root(nullptr) {}
    
    void insert(int val) { root = insert(root, val); }
    void preorder() { preorder(root); cout << endl; }
    void inorder() { inorder(root); cout << endl; }
    void postorder() { postorder(root); cout << endl; }
    bool search(int val) { return search(root, val); }
};

int main() {
    BST tree;
    int choice, val;
    
    while (true) {
        cout << "\nBST Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Preorder\n";
        cout << "3. Inorder\n";
        cout << "4. Postorder\n";
        cout << "5. Search\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                tree.insert(val);
                break;
            case 2:
                tree.preorder();
                break;
            case 3:
                tree.inorder();
                break;
            case 4:
                tree.postorder();
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> val;
                cout << (tree.search(val) ? "Found" : "Not found") << endl;
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}

/*
Time Complexity:
1. Insert: O(h) where h is height of tree (O(n) worst case, O(log n) balanced)
2. Preorder: O(n)
3. Inorder: O(n)
4. Postorder: O(n)
5. Search: O(h) same as insert
*/