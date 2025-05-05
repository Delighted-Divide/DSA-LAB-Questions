// SearchProgram.cpp
#include <iostream>
#include <algorithm>
#include "ArraySorter.h"

// Function prototypes
int linearSearch(const std::vector<int>& arr, int target);
int binarySearch(const std::vector<int>& arr, int target);
void searchMenu();

int main() {
    searchMenu();
    return 0;
}

// Linear Search implementation
int linearSearch(const std::vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// Binary Search implementation (requires sorted array)
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Main menu function
void searchMenu() {
    ArraySorter sorter;
    char choice;
    int target, result;

    do {
        std::cout << "\nSearch Algorithm Menu" << std::endl;
        std::cout << "a. Linear Search" << std::endl;
        std::cout << "b. Binary Search" << std::endl;
        std::cout << "c. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (tolower(choice)) {
            case 'a': {
                sorter.getArrayInput();
                if (sorter.getArray().empty()) break;

                std::cout << "Enter the target value to search: ";
                std::cin >> target;

                sorter.displayArray();
                result = linearSearch(sorter.getArray(), target);

                if (result != -1) {
                    std::cout << "Value found at index " << result << std::endl;
                } else {
                    std::cout << "Value not found in the array." << std::endl;
                }
                break;
            }
            case 'b': {
                sorter.getArrayInput();
                if (sorter.getArray().empty()) break;

                // Ensure array is sorted for binary search
                if (!sorter.isSorted()) {
                    std::cout << "Array needs to be sorted for binary search. Sorting..." << std::endl;
                    sorter.bubbleSort();
                }

                std::cout << "Sorted ";
                sorter.displayArray();

                std::cout << "Enter the target value to search: ";
                std::cin >> target;

                result = binarySearch(sorter.getArray(), target);

                if (result != -1) {
                    std::cout << "Value found at index " << result << std::endl;
                } else {
                    std::cout << "Value not found in the array." << std::endl;
                }
                break;
            }
            case 'c':
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (tolower(choice) != 'c');
}