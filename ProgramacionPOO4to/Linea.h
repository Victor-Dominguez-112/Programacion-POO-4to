#pragma once
#include "EjercicioHerencia.h"

//---------- CLASE LINEA ----------//
//hereda de Figura. Usa memoria dinamica para almacenar segmentos.
class Linea : public Figura
{
private:
    float* segmentos; //creacion de un arreglo dinamico con los segmentos de la linea
    int cantidad;     //cantidad de los segmentos que se almacenen

public:
    //el constructor copiara los valores del arreglo recibido
    Linea(float* arr, int tam) : Figura("Linea"), cantidad(tam)
    {
        //se reservara memoria dinamica para poder guardar todos los segmentos
        segmentos = new float[tam];
        for (int i = 0; i < tam; i++)
        {
            segmentos[i] = arr[i];
        }
    }

    //destructor este libera memoria dinámica
    ~Linea() override
    {
        delete[] segmentos;
    }

    //el área de una línea siempre es de 0
    float CalcularArea() const override
    {
        return 0.0;
    }

    //el perimetro es la suma de todos los segmentos de la linea
    float CalcularPerimetro() const override
    {
        float suma = 0.0;
        for (int i = 0; i < cantidad; i++)
            suma += segmentos[i];
        return suma;
    }
};

void DemostracionLinea();