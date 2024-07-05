#pragma once
#include "Persona.h"
#include <iostream>
#include <vector>
using namespace std;
// Función de comparación para QuickSort
bool compare(const Cliente& a, const Cliente& b) {
    if (a.edad != b.edad)
        return a.edad < b.edad;
    return a.edad < b.edad;
}

// Implementación de QuickSort
template <typename T>
void quickSort(vector<T>& arr, int left, int right, bool(*compare)(const T&, const T&)) {
    int i = left, j = right;
    T pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (compare(arr[i], pivot))
            i++;
        while (compare(pivot, arr[j]))
            j--;
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        quickSort(arr, left, j, compare);
    if (i < right)
        quickSort(arr, i, right, compare);
}