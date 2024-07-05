#pragma once
#include <iostream>
using namespace std;
class Nodo {
public:
    int edad;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int edad) : edad(edad), izquierda(nullptr), derecha(nullptr) {}
};

// Implementación del Árbol Binario de Búsqueda
class ArbolBinario {
public:
    Nodo* raiz;

    ArbolBinario() : raiz(nullptr) {}

    void insertar(int edad) {
        raiz = insertarRec(raiz, edad);
    }

    Nodo* insertarRec(Nodo* nodo, int edad) {
        if (nodo == nullptr) {
            return new Nodo(edad);
        }
        if (edad < nodo->edad) {
            nodo->izquierda = insertarRec(nodo->izquierda, edad);
        }
        else {
            nodo->derecha = insertarRec(nodo->derecha, edad);
        }
        return nodo;
    }

    int encontrarMayor() {
        Nodo* nodo = raiz;
        while (nodo->derecha != nullptr) {
            nodo = nodo->derecha;
        }
        return nodo->edad;
    }

    bool esMultiploDe3(int numero) {
        return numero % 3 == 0;
    }

    Nodo* eliminar(Nodo* nodo, int edad) {
        if (nodo == nullptr) return nodo;

        if (edad < nodo->edad) {
            nodo->izquierda = eliminar(nodo->izquierda, edad);
        }
        else if (edad > nodo->edad) {
            nodo->derecha = eliminar(nodo->derecha, edad);
        }
        else {
            if (nodo->izquierda == nullptr) {
                Nodo* temp = nodo->derecha;
                delete nodo;
                return temp;
            }
            else if (nodo->derecha == nullptr) {
                Nodo* temp = nodo->izquierda;
                delete nodo;
                return temp;
            }

            Nodo* temp = encontrarMin(nodo->derecha);
            nodo->edad = temp->edad;
            nodo->derecha = eliminar(nodo->derecha, temp->edad);
        }
        return nodo;
    }

    Nodo* encontrarMin(Nodo* nodo) {
        while (nodo->izquierda != nullptr) {
            nodo = nodo->izquierda;
        }
        return nodo;
    }

    bool esPrimo(int numero) {
        if (numero <= 1) return false;
        if (numero == 2) return true;
        if (numero % 2 == 0) return false;
        for (int i = 3; i <= sqrt(numero); i += 2) {
            if (numero % i == 0) return false;
        }
        return true;
    }

    void mostrarRec(Nodo* nodo) {
        if (nodo != nullptr) {
            mostrarRec(nodo->izquierda) ;
            cout << nodo->edad << " ";
            mostrarRec(nodo->derecha);
        }
    }

    void mostrar() {
        mostrarRec(raiz);
        cout << endl;
    }
    void preordenRec(Nodo* nodo) {
        if (nodo != nullptr) {
            cout << nodo->edad << " ";
            preordenRec(nodo->izquierda);
            preordenRec(nodo->derecha);
        }
    }

    void inordenRec(Nodo* nodo) {
        if (nodo != nullptr) {
            inordenRec(nodo->izquierda);
            cout << nodo->edad << " ";
            inordenRec(nodo->derecha);
        }
    }

    void postordenRec(Nodo* nodo) {
        if (nodo != nullptr) {
            postordenRec(nodo->izquierda);
            postordenRec(nodo->derecha);
            cout << nodo->edad << " ";
        }
    }

    void preorden() {
        preordenRec(raiz);
        cout << endl;
    }

    void inorden() {
        inordenRec(raiz);
        cout << endl;
    }

    void postorden() {
        postordenRec(raiz);
        cout << endl;
    }
};

