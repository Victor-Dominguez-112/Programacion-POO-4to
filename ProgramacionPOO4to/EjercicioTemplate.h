#pragma once
#include <iostream>
using namespace std;

//0) Hacer una funci�n template que se llame PrintArray, que reciba un array del tipo template, su tama�o, e imprima todos los elementos del inicio al final.

// Funcion template para imprimir cualquier tipo de array
template <typename T>
void PrintArray(T array[], int tamano)
{
    for (int i = 0; i < tamano; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Funcion para la impresion del ejercicio en Main
void MostrarEjercicioTemplate();
