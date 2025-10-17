//0) Hacer una función template que se llame PrintArray, que reciba un array del tipo template, su tamaño, e imprima todos los elementos del inicio al final.
#include "EjercicioTemplate.h"
#include <iostream>
using namespace std;

void MostrarEjercicioTemplate()
{
    int arrayInt[5] = { 1, 2, 3, 4, 5 };
    float arrayFloat[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    char arrayChar[5] = { 'A', 'B', 'C', 'D', 'E'};

    cout << "Array de enteros: ";
    PrintArray(arrayInt, 5);

    cout << "Array de floats: ";
    PrintArray(arrayFloat, 5);

    cout << "Array de caracteres: ";
    PrintArray(arrayChar, 5);
}
