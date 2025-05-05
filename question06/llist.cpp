//program to perform various functions on a singly linked list

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class list {
    struct node {
        int data;
        node* next;
    } *head;

    void reversePrint(node*); // Private function for recursive reverse display

public:
    list();
    void insertbeg(int);
    void insertend(int);
    void insertpos(int, int, int);
    int deletebeg();
    int deleteend();
    int deletepos(int, int);
    void search(int);
    void display();
    void rev();
    void rdisplay();
};

// Main Function
int main() {
    list list1;
    int length = 0;
    int option;
    cout << "This is a menu-driven program to perform functions on a linked list.\n";
    cout << "1. Insert at the beginning\n2. Insert at the end\n3. Insert at a position\n";
    cout << "4. Delete from beginning\n5. Delete from end\n6. Delete from a position\n";
    cout << "7. Search\n8. Display\n9. Reverse\n10. Display in reverse\n11. Exit\n";

    while (true) {
        cout << "Enter your option: ";
        cin >> option;
        if (option == 1) {
            int data;
            cout << "Enter value to insert: ";
            cin >> data;
            list1.insertbeg(data);
            length++;
        } else if (option == 2) {
            int data;
            cout << "Enter value to insert: ";
            cin >> data;
            list1.insertend(data);
            length++;
        } else if (option == 3) {
            int data, pos;
            cout << "Enter value to insert: ";
            cin >> data;
            cout << "Enter position to insert in: ";
            cin >> pos;
            list1.insertpos(data, pos, length);
            length++;
        } else if (option == 4) {
            if (length > 0) {
                list1.deletebeg();
                length--;
            } else {
                cout << "List is already empty!\n";
            }
        } else if (option == 5) {
            if (length > 0) {
                list1.deleteend();
                length--;
            } else {
                cout << "List is already empty!\n";
            }
        } else if (option == 6) {
            if (length > 0) {
                int pos;
                cout << "Enter position to delete: ";
                cin >> pos;
                list1.deletepos(pos, length);
                length--;
            } else {
                cout << "List is already empty!\n";
            }
        } else if (option == 7) {
            int data;
            cout << "Enter value to search: ";
            cin >> data;
            list1.search(data);
        } else if (option == 8) {
            list1.display();
        } else if (option == 9) {
            list1.rev();
        } else if (option == 10) {
            list1.rdisplay();
        } else if (option == 11) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid option. Try again!\n";
        }
    }
    return 0;
}

// Function Definitions

list::list() {
    head = NULL;
}

//function to insert data in the beginning
void list::insertbeg(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

//function to insert data in the end
void list::insertend(int data) {
    if (head == NULL) {
        insertbeg(data);
        return;
    }
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

//function to insert a value at a position
void list::insertpos(int data, int pos, int length) {
    if (pos < 1 || pos > length + 1) {
        cout << "Invalid position!\n";
        return;
    }
    if (pos == 1) {
        insertbeg(data);
        return;
    }
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}


//function to delete a value from a beginning
int list::deletebeg() {
    if (head == NULL) {
        cout << "The list is empty!\n";
        return -1;
    }
    node* del = head;
    int data = del->data;
    head = head->next;
    free(del);
    return data;
}

//function to delete a value from the end
int list::deleteend() {
    if (head == NULL) {
        cout << "The list is empty!\n";
        return -1;
    }
    if (head->next == NULL) {
        int data = head->data;
        free(head);
        head = NULL;
        return data;
    }
    node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    int data = temp->next->data;
    free(temp->next);
    temp->next = NULL;
    return data;
}

//function to delete a value from the specified position
int list::deletepos(int pos, int length) {
    if (head == NULL) {
        cout << "The list is empty!\n";
        return -1;
    }
    if (pos < 1 || pos > length) {
        cout << "Invalid position!\n";
        return -1;
    }
    if (pos == 1) {
        return deletebeg();
    }

    node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) { 
        cout << "Invalid position!\n";
        return -1;
    }

    node* del = temp->next;
    int data = del->data;
    temp->next = del->next;
    free(del);
    return data;
}

//function to display elements in the linked list
void list::display() {
    node* temp = head;
    if (!temp) {
        cout << "The list is empty!\n";
        return;
    }
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

//function to reverse the linked list
void list::rev() {
    if (head == NULL || head->next == NULL) return;
    node* prev = NULL;
    node* current = head;
    node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void list::rdisplay() {
    reversePrint(head);
    cout << endl;
}

void list::reversePrint(node* temp) {
    if (!temp) return;
    reversePrint(temp->next);
    cout << temp->data << " ";
}
