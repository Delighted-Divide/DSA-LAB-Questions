// Program to implement Round Robin Scheduling Algorithm 
// using Circular Linked List in C++

#include <iostream>
#include "cpu.h"  // Include the header file

using namespace std;

int main() {
    int cpu_time;
    cout << "Enter CPU processing time: ";
    cin >> cpu_time;

    cpu obj(cpu_time);  // Create CPU scheduler object
    int choice;
    int time;

    while (true) {
        cout << "\n1: Insert Process\n2: Execute\n3: Display\n4: Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Process Time: ";
                cin >> time;
                obj.inputprocess(time);
                break;
            case 2:
                obj.execute();
                break;
            case 3:
                obj.display();
                break;
            case 4:
                cout << "Program Exited\n";
                return 0;
            default:
                cout << "Invalid Choice. Please enter again.\n";
        }
    }
}
