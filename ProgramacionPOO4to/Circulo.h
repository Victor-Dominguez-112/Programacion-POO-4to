#pragma once
#include "EjercicioHerencia.h"

//---------- CLASE CIRCULO ----------//
//esta hereda de Figura y calcula el área y el perímetro de un círculo
class Circulo : public Figura
{
private:
    float radio; //radio de nuestro circulo

public:
    //nuestro constructor inicializara la figura con el nombre "Circulo" y su radio
    Circulo(float r) : Figura("Circulo"), radio(r) {}

    ~Circulo() override {} //nuestro destructor virtual

    float CalcularArea() const override //calculo del area del circulo pi * r²
    {
        return M_PI * radio * radio;
    }

    float CalcularPerimetro() const override //calculo de nuestro perimetro del circulo
    {
        return 2 * M_PI * radio;
    }
};

void DemostracionCirculo();
