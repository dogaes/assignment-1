#ifndef ARRAY_OPS_H
#define ARRAY_OPS_H

const int MAX_SIZE = 1000;

int search(const int arr[], int size, int value);
bool modify(int arr[], int size, int index, int newValue, int &oldValue);
bool add(int arr[], int &size, int value);
bool remove(int arr[], int &size, int index);

#endif
