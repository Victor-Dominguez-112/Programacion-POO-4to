#pragma once
#include "EjercicioHerencia.h"

//---------- CLASE FIGURA DE N LADOS ----------//
//hereda de Figura y representa polígonos regulares de N lados
class FiguraNLados : public Figura
{
protected:
    float lado; //tamaño de nuestra figura
    int nLados; //cantidad de lados de nuestra figura 

public:
    //constructor recibira la longitud de lado y número total de lados que tiene la figura
    FiguraNLados(float l, int n) : Figura("Figura de N lados"), lado(l), nLados(n) {}

    ~FiguraNLados() override {} //destructor virtual

    float CalcularArea() const override
    {
        // Fórmula para polígonos regulares (n * lado²) / (4 * tan(? / n))
        return (nLados * lado * lado) / (4 * tan(M_PI / nLados));
    }

    float CalcularPerimetro() const override //el perímetro es simplemente calculando n * lado
    {
        return nLados * lado;
    }
};

void DemostracionNlados();