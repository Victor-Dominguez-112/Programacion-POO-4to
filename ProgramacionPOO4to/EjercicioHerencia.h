#pragma once
#include <iostream>
#include <cmath>    //importamos la libreria cmath para usar M_PI, tan(), etc.
//en algunos compiladores, la constante M_PI no está definida por defecto
//este bloque nos garantizara que si esta no existe, se pueda definir manualmente el valor de PI.
#ifndef M_PI        
#define M_PI 3.14159265358979323846
#endif
using namespace std;

//clase abstracta que definirá la estructura general de una figura
class Figura
{
protected:
    string nombre; //nombre de nuestra figura que sera accesible a las clases hijas

public:
    //constructor
    Figura(string name) : nombre(name) {}

    //destructor virtual que permitirá la eliminación polimórfica
    virtual ~Figura() {}

    //definimos funciones virtuales puras y todas las figuras deben definirlas
    virtual float CalcularArea() const = 0;
    virtual float CalcularPerimetro() const = 0;

    //devolvemos el nombre de nuestra figura
    const string& ObtenerNombreDeFigura() const
    {
        return nombre;
    }
};

void DemostracionHerencia();

//https://learn.microsoft.com/es-es/cpp/c-runtime-library/math-constants?view=msvc-170