#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ArraySorter {
private:
    vector<int> arr;

    // Display the current array
    void displayArray() {
        cout << "Current Array: [";
        for (size_t i = 0; i < arr.size(); ++i) {
            cout << arr[i];
            if (i != arr.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    // Get array input from user
    void getArrayInput() {
        arr.clear();
        int size, value;
        cout << "Enter the size of the array: ";
        cin >> size;

        if (size <= 0) {
            cout << "Invalid size! Size must be positive." << endl;
            return;
        }

        cout << "Enter " << size << " elements:" << endl;
        for (int i = 0; i < size; ++i) {
            cin >> value;
            arr.push_back(value);
        }
    }

public:
    // Bubble Sort implementation
    void bubbleSort() {
        if (arr.empty()) {
            cout << "Array is empty!" << endl;
            return;
        }

        for (size_t i = 0; i < arr.size() - 1; ++i) {
            bool swapped = false;
            for (size_t j = 0; j < arr.size() - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break; // Early termination if no swaps
        }
        cout << "Array sorted using Bubble Sort." << endl;
    }

    // Selection Sort implementation
    void selectionSort() {
        if (arr.empty()) {
            cout << "Array is empty!" << endl;
            return;
        }

        for (size_t i = 0; i < arr.size() - 1; ++i) {
            size_t min_idx = i;
            for (size_t j = i + 1; j < arr.size(); ++j) {
                if (arr[j] < arr[min_idx]) {
                    min_idx = j;
                }
            }
            if (min_idx != i) {
                swap(arr[i], arr[min_idx]);
            }
        }
        cout << "Array sorted using Selection Sort." << endl;
    }

    // Insertion Sort implementation
    void insertionSort() {
        if (arr.empty()) {
            cout << "Array is empty!" << endl;
            return;
        }

        for (size_t i = 1; i < arr.size(); ++i) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
        cout << "Array sorted using Insertion Sort." << endl;
    }

    // Main menu function
    void run() {
        char choice;
        do {
            cout << "\nSorting Algorithm Menu" << endl;
            cout << "a. Bubble Sort" << endl;
            cout << "b. Selection Sort" << endl;
            cout << "c. Insertion Sort" << endl;
            cout << "d. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (tolower(choice)) {
                case 'a':
                    getArrayInput();
                    if (!arr.empty()) {
                        cout << "Original Array: ";
                        displayArray();
                        bubbleSort();
                        cout << "Sorted Array: ";
                        displayArray();
                    }
                    break;
                case 'b':
                    getArrayInput();
                    if (!arr.empty()) {
                        cout << "Original Array: ";
                        displayArray();
                        selectionSort();
                        cout << "Sorted Array: ";
                        displayArray();
                    }
                    break;
                case 'c':
                    getArrayInput();
                    if (!arr.empty()) {
                        cout << "Original Array: ";
                        displayArray();
                        insertionSort();
                        cout << "Sorted Array: ";
                        displayArray();
                    }
                    break;
                case 'd':
                    cout << "Exiting program." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (tolower(choice) != 'd');
    }
};

int main() {
    ArraySorter sorter;
    sorter.run();
    return 0;
}