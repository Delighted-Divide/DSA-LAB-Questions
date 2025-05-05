//Program to implement a doubly linked list 
//with tail in c++

#include <iostream>
#include <cstdlib> // For malloc and free
using namespace std;

class List {
private:
    struct Node {
        int data;
        Node *next;
        Node *prev;
    };
    Node *head;
    Node *tail;

public:
    List() { head = tail = NULL; } // Constructor to initialize empty list

    bool insertBeginning(int value);
    bool insertEnd(int value);
    bool insertAtPosition(int value, int position);
    int deleteBeginning();
    int deleteEnd();
    int deleteAtPosition(int position);
    int search(int value);
    void display();
};

// Main function to handle menu-driven operations
int main() {
    int choice, value, position;
    List obj;

    while (true) {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert Beginning\n2. Insert End\n3. Insert Position\n";
        cout << "4. Delete Beginning\n5. Delete End\n6. Delete Position\n";
        cout << "7. Search\n8. Display\n9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Value: ";
                cin >> value;
                obj.insertBeginning(value);
                break;
            case 2:
                cout << "Enter Value: ";
                cin >> value;
                obj.insertEnd(value);
                break;
            case 3:
                cout << "Enter Value: ";
                cin >> value;
                cout << "Enter Position: ";
                cin >> position;
                obj.insertAtPosition(value, position);
                break;
            case 4:
                obj.deleteBeginning();
                break;
            case 5:
                obj.deleteEnd();
                break;
            case 6:
                cout << "Enter Position: ";
                cin >> position;
                obj.deleteAtPosition(position);
                break;
            case 7:
                cout << "Enter Value to Search: ";
                cin >> value;
                obj.search(value);
                break;
            case 8:
                obj.display();
                break;
            case 9:
                cout << "Program Exited.\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}

// Function to display list in forward and reverse order
void List::display() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    cout << "List (Forward): ";
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    cout << "List (Reverse): ";
    temp = tail;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

// Function to insert value at the beginning of the list
bool List::insertBeginning(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return false;

    newNode->data = value;
    newNode->prev = NULL;

    if (head == NULL) { // If list is empty
        newNode->next = NULL;
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    return true;
}

// Function to insert value at the end of the list
bool List::insertEnd(int value) {
    if (head == NULL) { // If list is empty, insert at the beginning
        return insertBeginning(value);
    }

    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return false;

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
    return true;
}

// Function to insert value at a specific position
bool List::insertAtPosition(int value, int position) {
    if (position < 0) {
        cout << "Invalid Position!\n";
        return false;
    }
    if (position == 0) return insertBeginning(value);

    Node *temp = head;
    for (int i = 0; i < position - 1; i++) {
        if (temp == NULL) {
            cout << "Index out of range!\n";
            return false;
        }
        temp = temp->next;
    }

    if (temp == tail) return insertEnd(value);

    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return false;

    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    return true;
}

// Function to delete first element from list
int List::deleteBeginning() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return -1;
    }

    int value = head->data;
    Node *temp = head;

    if (head == tail) { // If only one node exists
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }

    free(temp);
    return value;
}

// Function to delete last element from list
int List::deleteEnd() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return -1;
    }
    if (head == tail) return deleteBeginning();

    int value = tail->data;
    Node *temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(temp);
    return value;
}

// Function to delete element at a given position
int List::deleteAtPosition(int position) {
    if (position < 0) {
        cout << "Invalid Position!\n";
        return -1;
    }
    if (head == NULL) {
        cout << "List is empty.\n";
        return -1;
    }
    if (position == 0) return deleteBeginning();

    Node *temp = head;
    for (int i = 0; i < position; i++) {
        if (temp == NULL) {
            cout << "Index out of range!\n";
            return -1;
        }
        temp = temp->next;
    }

    if (temp == tail) return deleteEnd();

    int value = temp->data;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    return value;
}

// Function to search for a specific element and return its index
int List::search(int value) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return -1;
    }

    int index = 0;
    Node *temp = head;
    while (temp) {
        if (temp->data == value) {
            cout << "Element found at index " << index << ".\n";
            return index;
        }
        temp = temp->next;
        index++;
    }

    cout << "Element not found.\n";
    return -1;
}
