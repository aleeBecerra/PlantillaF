#pragma once
#include <iostream>
#include <vector>
using namespace std;
// Implementación de HashTable
class HashTable {
private:
    vector<int> keys;
    vector<int> values;
    vector<bool> isOccupied;
    int hashFunction(int key) {
        const double A = (sqrt(5) - 1) / 2; // Constante A para hashing dorado
        const int prime = 769; // Número primo para evitar patrones comunes

        // Aplicación de la técnica de hashing dorado
        double fractionalPart = key * A - floor(key * A);
        int index = floor(keys.size() * fractionalPart);

        // Ajuste por si el índice calculado está fuera de los límites
        index %= keys.size();
        if (index < 0) {
            index += keys.size();
        }

        return index;
    }
public:
    HashTable(int size) : keys(size), values(size), isOccupied(size, false) {}

    void insert(int key, int value) {
        int index = hashFunction(key);
        while (isOccupied[index]) {
            index = (index + 1) % keys.size(); // Sondeo lineal
        }
        keys[index] = key;
        values[index] = value;
        isOccupied[index] = true;
    }

    void display() {
        for (int i = 0; i < keys.size(); ++i) {
            cout << "Index " << i << ": ";
            if (isOccupied[i]) {
                cout << "(" << keys[i] << ", " << values[i] << ")";
            }
            cout << endl;
        }
    }
};