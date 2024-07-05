#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <limits>
#include <queue>
using namespace std;

class Grafo {
public:
    unordered_map<char, list<pair<char, int>>> adjList;

    void agregarArista(char origen, char destino, int distancia) {
        adjList[origen].push_back(make_pair(destino, distancia));
        adjList[destino].push_back(make_pair(origen, distancia));
    }

    void mostrarGrafo() {
        for (auto& node : adjList) {
            cout << node.first << " -> ";
            for (auto& neighbor : node.second) {
                cout << "(" << neighbor.first << ", " << neighbor.second << "km) ";
            }
            cout << endl;
        }
    }
};