// ArraySorter.h
#ifndef ARRAY_SORTER_H
#define ARRAY_SORTER_H

#include <vector>
#include <algorithm>
#include <iostream>

class ArraySorter {
private:
    std::vector<int> arr;

public:
    // Get array input from user
    void getArrayInput() {
        arr.clear();
        int size, value;
        std::cout << "Enter the size of the array: ";
        std::cin >> size;

        if (size <= 0) {
            std::cout << "Invalid size! Size must be positive." << std::endl;
            return;
        }

        std::cout << "Enter " << size << " elements:" << std::endl;
        for (int i = 0; i < size; ++i) {
            std::cin >> value;
            arr.push_back(value);
        }
    }

    // Display the current array
    void displayArray() const {
        std::cout << "Array: [";
        for (size_t i = 0; i < arr.size(); ++i) {
            std::cout << arr[i];
            if (i != arr.size() - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }

    // Bubble Sort implementation
    void bubbleSort() {
        if (arr.empty()) {
            std::cout << "Array is empty!" << std::endl;
            return;
        }

        for (size_t i = 0; i < arr.size() - 1; ++i) {
            bool swapped = false;
            for (size_t j = 0; j < arr.size() - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    }

    // Getter for the array
    const std::vector<int>& getArray() const {
        return arr;
    }

    // Check if array is sorted
    bool isSorted() const {
        for (size_t i = 0; i < arr.size() - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }
};

#endif // ARRAY_SORTER_H