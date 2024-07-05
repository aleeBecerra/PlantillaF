#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
struct Cliente {
    int dni;
    int edad;
    char sexo;
    int satisfaccion;
    int celular;
    int tipo_servicio;
};

// Función para generar sexos aleatorios
char generarSexoAleatorio() {
    return rand() % 2 == 0 ? 'M' : 'F';
}

// Función para generar el conjunto de datos de vacas
vector<Cliente> generarDatos(int cantidad) {
    vector<Cliente> datos;
    for (int i = 0; i < cantidad; ++i) {
        datos.push_back({
            rand() % 90000000 + 10000000, // DNI
            rand() % 70 + 18,             // Edad
            generarSexoAleatorio(),       // Sexo
            rand() % 2,                   // Satisfaccion (0 o 1)
            rand() % 1000000000,          // Celular
            rand() % 3                    // Tipo_servicio (0: Internet, 1: Celular, 2: Ambos)
            });
    }
    return datos;
}