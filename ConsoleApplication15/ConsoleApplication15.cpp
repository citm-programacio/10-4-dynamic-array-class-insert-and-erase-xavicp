// ConsoleApplication15.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

class Dynamic_array {
private:
    int* array;     // Puntero al array dinámico
    int size;       // Tamaño actual del array
    int capacity;   // Capacidad máxima del array

public:
    // Constructor
    Dynamic_array(int p_capacity = 10) : size(0), capacity(p_capacity) {
        array = new int[capacity];
    }

    // Destructor
    ~Dynamic_array() {
        delete[] array;
    }

    // Añadir un elemento al final del array
    void add(int valor) {
        if (size < capacity) { // Solo añadir si hay espacio disponible
            array[size++] = valor;
        } else {
            cout << "Error: Capacidad máxima alcanzada. No se puede añadir el elemento." << endl;
        }
    }

    // Imprimir el contenido del array
    void imprimir() const {
        for (int i = 0; i < size; i++) {
            cout << "[" << array[i] << "]";
        }
        cout << "\n";
    }

    // Insertar un elemento en una posición específica
    void insertar(int index, int numero) {
        if (index < 0 || index > size) {
            cout << "Índice fuera de rango!" << endl;
            return;
        }
        if (size < capacity) { // Solo insertar si hay espacio disponible
            for (int i = size; i > index; i--) {
                array[i] = array[i - 1]; // Desplazar elementos hacia la derecha
            }
            array[index] = numero; // Insertar el nuevo valor
            size++;
        } else {
            cout << "Error: Capacidad máxima alcanzada. No se puede insertar el elemento." << endl;
        }
    }

    // Borrar un elemento en una posición específica
    void borrar(int index) {
        if (index < 0 || index >= size) {
            cout << "Índice fuera de rango!" << endl;
            return;
        }
        for (int i = index; i < size - 1; i++) {
            array[i] = array[i + 1]; // Desplazar elementos hacia la izquierda
        }
        size--; // Reducir el tamaño del array
    }
};

int main() {
    Dynamic_array arr(5); // Crear un array con capacidad máxima de 5

    // Agregar elementos
    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);
    arr.add(50);

    // Imprimir el array inicial
    cout << "Array inicial: ";
    arr.imprimir();

    // Intentar añadir un elemento más (superando la capacidad)
    cout << "Intentando añadir 60..." << endl;
    arr.add(60);

    // Insertar un elemento
    cout << "Insertando 25 en la posición 2..." << endl;
    arr.insertar(2, 25);
    arr.imprimir();

    // Borrar un elemento
    cout << "Borrando el elemento en la posición 2..." << endl;
    arr.borrar(2);
    arr.imprimir();

    return 0;
}
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
