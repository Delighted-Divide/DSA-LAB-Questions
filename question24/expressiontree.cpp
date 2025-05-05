#include <iostream>
#include <stack>
#include <string>
using namespace std;

class ExprTree {
private:
    struct Node {
        char data;
        Node* left;
        Node* right;
        Node(char ch) : data(ch), left(nullptr), right(nullptr) {}
    };
    
    Node* root;
    
    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
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
    
public:
    ExprTree() : root(nullptr) {}
    
    void constructTree(const string& postfix) {
        stack<Node*> st;
        
        for (char c : postfix) {
            Node* newNode = new Node(c);
            
            if (isOperator(c)) {
                newNode->right = st.top(); st.pop();
                newNode->left = st.top(); st.pop();
            }
            
            st.push(newNode);
        }
        
        root = st.top();
    }
    
    void preorder() { preorder(root); cout << endl; }
    void inorder() { inorder(root); cout << endl; }
    void postorder() { postorder(root); cout << endl; }
};

int main() {
    ExprTree tree;
    string postfix;
    int choice;
    
    while (true) {
        cout << "\nExpression Tree Menu:\n";
        cout << "1. Enter Postfix Expression\n";
        cout << "2. Construct Expression Tree\n";
        cout << "3. Preorder\n";
        cout << "4. Inorder\n";
        cout << "5. Postorder\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter postfix expression: ";
                cin >> postfix;
                break;
            case 2:
                tree.constructTree(postfix);
                cout << "Tree constructed\n";
                break;
            case 3:
                tree.preorder();
                break;
            case 4:
                tree.inorder();
                break;
            case 5:
                tree.postorder();
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
1. Postfix Expression: O(1) - just stores input
2. Construct Tree: O(n) where n is length of expression
3. Preorder: O(n)
4. Inorder: O(n)
5. Postorder: O(n)
*/