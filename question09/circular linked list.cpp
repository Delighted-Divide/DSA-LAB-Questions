//program to implement a circular 
//linked list in c++

#include <iostream>
#include <cstdlib> // For malloc and free
using namespace std;

struct Node {
    int data;
    Node *next;
};

class CircularLinkedList {
private:
    Node *head; // Pointer to the first node

public:
    // Constructor
    CircularLinkedList() {
        head = NULL;
    }

    // Function prototypes
    void insertBeginning(int value);
    void insertEnd(int value);
    void insertPosition(int value, int position);
    void deleteBeginning();
    void deleteEnd();
    void deletePosition(int position);
    void search(int value);
    void display();
};

// Inserts a node at the beginning of the list
void CircularLinkedList::insertBeginning(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head; // Circular connection
    } else {
        Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode; // Update head to the new node
    }
}

// Inserts a node at the end of the list
void CircularLinkedList::insertEnd(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head; // Circular connection
    } else {
        Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head; // Circular connection
    }
}

// Inserts a node at a specific position
void CircularLinkedList::insertPosition(int value, int position) {
    if (position < 1) {
        cout << "Invalid Position!\n";
        return;
    }

    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    if (position == 1) {
        insertBeginning(value);
        return;
    }

    Node *temp = head;
    for (int i = 1; i < position - 1; i++) {
        if (temp->next == head) {
            cout << "Invalid Position! List has fewer elements.\n";
            free(newNode);
            return;
        }
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Deletes the first node in the list
void CircularLinkedList::deleteBeginning() {
    if (head == NULL) {
        cout << "List is empty, nothing to delete.\n";
        return;
    }

    if (head->next == head) { // Only one node
        free(head);
        head = NULL;
        return;
    }

    Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    Node *toDelete = head;
    head = head->next;
    temp->next = head; // Update last node's next pointer
    free(toDelete);
}

// Deletes the last node in the list
void CircularLinkedList::deleteEnd() {
    if (head == NULL) {
        cout << "List is empty, nothing to delete.\n";
        return;
    }

    if (head->next == head) { // Only one node
        free(head);
        head = NULL;
        return;
    }

    Node *temp = head, *prev = NULL;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    free(temp);
}

// Deletes a node at a given position
void CircularLinkedList::deletePosition(int position) {
    if (head == NULL || position < 1) {
        cout << "Invalid position or list is empty.\n";
        return;
    }

    if (position == 1) {
        deleteBeginning();
        return;
    }

    Node *temp = head, *prev = NULL;
    for (int i = 1; i < position; i++) {
        prev = temp;
        temp = temp->next;
        if (temp == head) {
            cout << "Invalid Position! List has fewer elements.\n";
            return;
        }
    }

    prev->next = temp->next;
    free(temp);
}

// Searches for a node with a given value
void CircularLinkedList::search(int value) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node *temp = head;
    int pos = 1;
    do {
        if (temp->data == value) {
            cout << "Element found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    cout << "Element not found in the list.\n";
}

// Displays the list elements
void CircularLinkedList::display() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node *temp = head;
    cout << "List elements: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Main function: Menu-driven program
int main() {
    CircularLinkedList list;
    int choice, value, position;

    while (true) {
        cout << "\n--- Circular Linked List Menu ---\n";
        cout << "1. Insert Beginning\n2. Insert End\n3. Insert Position\n";
        cout << "4. Delete Beginning\n5. Delete End\n6. Delete Position\n";
        cout << "7. Search\n8. Display\n9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertEnd(value);
                break;
            case 3:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                list.insertPosition(value, position);
                break;
            case 4:
                list.deleteBeginning();
                break;
            case 5:
                list.deleteEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> position;
                list.deletePosition(position);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                list.search(value);
                break;
            case 8:
                list.display();
                break;
            case 9:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
