#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Persona.h"
using namespace std;

class Registro {
public:
    vector<Cliente> clientes;

    void ingresarDatos() {
        Cliente cliente;
        cout << "DNI: ";
        cin >> cliente.dni;
        cout << "Edad: ";
        cin >> cliente.edad;
        cout << "Sexo (M/F): ";
        cin >> cliente.sexo;
        cout << "Satisfaccion (0/1): ";
        cin >> cliente.satisfaccion;
        cout << "Celular: ";
        cin >> cliente.celular;
        cout << "Tipo_servicio (0: Internet, 1: Celular, 2: Ambos): ";
        cin >> cliente.tipo_servicio;
        clientes.push_back(cliente);
    }

    void mostrarDatos() const {
        for (const auto& cliente : clientes) {
            cout << "DNI: " << cliente.dni << ", Edad: " << cliente.edad << ", Sexo: " << cliente.sexo
                << ", Satisfaccion: " << cliente.satisfaccion << ", Celular: " << cliente.celular
                << ", Tipo_servicio: " << cliente.tipo_servicio << endl;
        }
    }
};
