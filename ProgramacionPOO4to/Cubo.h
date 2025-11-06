#pragma once
#include "EjercicioHerencia.h"
#include "Cuadrado.h"

//---------- CLASE CUBO ----------//
//hereda de Cuadrado y añade volumen y área superficial
class Cubo : public Cuadrado
{
public:
    //constructor este reutiliza el constructor del Cuadrado yse encargara de cambiar el nombre a "Cubo"
    Cubo(float l) : Cuadrado(l)
    {
        nombre = "Cubo";
    }

    ~Cubo() override {} //destructor virtual

    float CalcularArea() const override
    {
        //calculo del area superficial de un cubo
        return 6 * lado * lado;
    }

    //calculo del perimetro de una cara del cubo 
    float CalcularPerimetro() const override
    {
        return 4 * lado;
    }

    //calculo del volumen del cubo
    float Volumen() const
    {
        return lado * lado * lado;
    }

    //calculo del area total del cubo que es la superficie del mismo
    float Surface() const
    {
        return 6 * lado * lado;
    }
};

void DemostracionCubo();