#include "EjercicioHerencia.h"
#include "Circulo.h"
#include "Cuadrado.h"
#include "FiguraNlados.h"
#include "Cubo.h"
#include "Linea.h"

void DemostracionHerencia()
{
    //circulo
    DemostracionCirculo();

    //cuadrado
    DemostracionCuadrado();

    //figura de N lados (crearemos un hexágono)
    DemostracionNlados();

    //cubo
    DemostracionCubo();

    //linea
    DemostracionLinea();
}