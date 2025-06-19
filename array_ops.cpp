#include <iostream>
#include "array_ops.h"

int search(const int arr[], int size, int value) {
    for (int i = 0; i < size; ++i)
        if (arr[i] == value)
            return i;
    return -1; // Not found
}

bool modify(int arr[], int size, int index, int newValue, int &oldValue) {
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of bounds.");
    oldValue = arr[index];
    arr[index] = newValue;
    return true;
}

bool add(int arr[], int &size, int value) {
    if (size >= MAX_SIZE)
        throw std::overflow_error("Array is full.");
    arr[size++] = value;
    return true;
}

bool remove(int arr[], int &size, int index) {
    if (index < 0 || index >= size)
        return false;
    for (int i = index; i < size - 1; ++i)
        arr[i] = arr[i + 1];
    --size;
    return true;
}
