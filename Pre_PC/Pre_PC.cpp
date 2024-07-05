#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <Windows.h>
#include <conio.h>

#include "Persona.h"
#include "Ordenamiento.h"
#include "HashTable.h"
#include "ArbolBinario.h"
#include "Registro.h"
#include "Grafo.h"

using namespace std;


int main() {
    srand(time(NULL));
    Registro registro;

    int opc;
    do {
        cout << "Menu de Opciones" << endl;
        cout << "<1> Generar Datos Automaticamente" << endl;
        cout << "<2> Registrar Datos Manualmente" << endl;
        cout << "<3> Mostrar Datos de Encuestas" << endl;
        cout << "<4> Ordenar por Edad (QuickSort)" << endl;
        cout << "<5> Implementar HashTable" << endl;
        cout << "<6> Crear Arbol Binario de Busqueda" << endl;
        cout << "<7> Mostrar Arbol Binario en Preorden" << endl;
        cout << "<8> Crear Grafo de Sedes" << endl;
        cout << "<9> Salir" << endl;
        cout << "Selecciona una opcion: ";
        cin >> opc;
        if (opc == 1) {
            int n;
            cout << "Ingrese la cantidad de registros que quiere hacer: "; cin >> n;
            cout << "=================================================================================" << endl;
            cout << "Generando datos aleatorios" << endl;
            cout << "=================================================================================" << endl;
            cout << "Generando..." << endl;
            Sleep(350);
            registro.clientes = generarDatos(n);
            cout << "Datos generados:" << endl;
            for (const auto& cliente : registro.clientes) {
                cout << "DNI: " << cliente.dni << ", Edad: " << cliente.edad << ", Sexo: " << cliente.sexo
                    << ", Satisfaccion: " << cliente.satisfaccion << ", Celular: " << cliente.celular
                    << ", Tipo_servicio: " << cliente.tipo_servicio << endl;
            }
            cout << "Presiona cualquier tecla para volver al menu...";
            _getch();

            system("cls");

        }
        else if (opc == 2) {
            registro.ingresarDatos();
            cout << "Presiona cualquier tecla para volver al menu...";
            _getch();

            system("cls");
        }
        else if (opc == 3) {
            registro.mostrarDatos();
            cout << "Presiona cualquier tecla para volver al menu...";
            _getch();

            system("cls");
        }
        else if (opc == 4) {
            cout << "=================================================================================" << endl;
            cout << "Ordenamiento Quicksort por edad" << endl;
            cout << "=================================================================================" << endl;
            quickSort(registro.clientes, 0, registro.clientes.size() - 1, compare);
            registro.mostrarDatos();
            cout << "Presiona cualquier tecla para volver al menu...";
            _getch();

            system("cls");
        }
        else if (opc == 5) {
            cout << "=================================================================================" << endl;
            cout << "Implementacion de Satisfaccion y Tipo de Servicio por Hash table" << endl;
            cout << "=================================================================================" << endl;
            HashTable ht(20);
            for (const auto& cliente : registro.clientes) {
                ht.insert(cliente.satisfaccion, cliente.tipo_servicio);
            }
            ht.display();
            cout << "Presiona cualquier tecla para volver al menu...";
            _getch();

            system("cls");
        }
        else if (opc == 6) {
            cout << "=================================================================================" << endl;
            cout << "Crear arbol binario" << endl;
            cout << "=================================================================================" << endl;
            ArbolBinario arbol;
            for (const auto& cliente : registro.clientes) {
                arbol.insertar(cliente.satisfaccion);
            }
            cout << "Arbol Binario creado." << endl;
            cout << "Presiona cualquier tecla para volver al menu...";
            _getch();

            system("cls");
        }
        else if (opc == 7) {
            cout << "=================================================================================" << endl;
            cout << "Mostrar Arbol Binario en Preorden " << endl;
            cout << "=================================================================================" << endl;
            ArbolBinario arbol;
            for (const auto& encuesta : registro.clientes) {
                arbol.insertar(encuesta.edad);
            }
            cout << "Recorrido en Preorden:" << endl;
            arbol.preorden();
            cout << "Presiona cualquier tecla para volver al menu...";
            _getch();

            system("cls");
        }
        else if (opc == 8) {
            cout << "=================================================================================" << endl;
            cout << "GRAFO DE SEDES" << endl;
            cout << "=================================================================================" << endl;
            cout << endl;
            Grafo grafo;
            grafo.agregarArista('A', 'B', 10);
            grafo.agregarArista('A', 'C', 15);
            grafo.agregarArista('B', 'D', 12);
            grafo.agregarArista('B', 'E', 5);
            grafo.agregarArista('C', 'D', 8);
            grafo.agregarArista('D', 'E', 7);

            grafo.mostrarGrafo();
            cout << "Presiona cualquier tecla para volver al menu...";
            _getch();

            system("cls");
        }
    } while (opc != 9);
    return 0;
}