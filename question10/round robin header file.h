// Header file containing functions to implement Round Robin Scheduling 
// using Circular Linked List in C++

#ifndef CPU_H
#define CPU_H

#include <iostream>
#include <cstdlib>  // For malloc and free
using namespace std;

class cpu {
private:
    struct node { 
        int process_time; // Stores process execution time
        node *next;       // Pointer to the next process in circular linked list
    };
    
    node *head;  // Points to the front of the queue
    int cpu_time; // Fixed time slot for Round Robin execution

public:
    // Constructor to initialize CPU time slice and empty queue
    cpu(int cpu_time) {
        head = NULL;
        this->cpu_time = cpu_time;
    }

    // Function to insert a process into the queue
    void inputprocess(int time);

    // Function to execute the round-robin scheduling step
    void execute();

    // Function to display all processes in the queue
    void display();

    // Function to delete the process at the front of the queue
    void deletebeg();
};

// Function to add a process to the circular linked list
void cpu::inputprocess(int time) {
    node *newnode = (node*)malloc(sizeof(node)); // Allocate memory
    newnode->process_time = time;
    
    if (head == NULL) {
        // First process added, making it a circular linked list
        head = newnode;
        newnode->next = newnode; 
    } else {
        // Insert process at the end of the circular list
        node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
}

// Function to execute a process according to round-robin scheduling
void cpu::execute() {
    if (head == NULL) {
        cout << "No Processes to execute\n";
        return;
    }

    node *temp = head;
    temp->process_time -= cpu_time; // Subtract CPU time slice from process

    if (temp->process_time > 0) {
        // Process is not complete, move it to the end of the queue
        head = head->next;
    } else {
        // Process has completed execution, remove it from the queue
        deletebeg();
    }
}

// Function to delete the first process in the queue when it completes
void cpu::deletebeg() {
    if (head == NULL) {
        return; // No processes left
    }

    if (head->next == head) { // Only one process in the queue
        free(head);
        head = NULL;
        return;
    }

    node *temp = head;
    while (temp->next != head) { 
        temp = temp->next; // Traverse to the last node
    }

    node *temp2 = head; // Store reference to the process being deleted
    head = head->next;  // Move head to the next process
    temp->next = head;  // Update last node to point to new head

    free(temp2); // Free memory of deleted process
}

// Function to display all processes in the queue
void cpu::display() {
    if (head == NULL) {
        cout << "No Processes in the queue\n";
        return;
    }

    cout << "Processes in queue: ";
    node *temp = head;
    do {
        cout << temp->process_time << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

#endif // CPU_H
