#pragma once
#include "EjercicioHerencia.h"

//---------- CLASE CUADRADO ----------//
//hereda de Figura y representara un cuadrado regular
class Cuadrado : public Figura
{
protected:
    float lado; //tamaño del cuadrado

public:
    //constructor este inicializara el nombre y los lados
    Cuadrado(float l) : Figura("Cuadrado"), lado(l) {}

    ~Cuadrado() override {} //destructor virtual

    float CalcularArea() const override //area de nuestro cuadrado lado²
    {
        return lado * lado;
    }

    float CalcularPerimetro() const override //perimetro de nustro cuadrado 4 * lado
    {
        return 4 * lado;
    }

    float GetLado() const { return lado; } //accedemos al valor del lado desde fuera
};

void DemostracionCuadrado();