#include "FiguraNlados.h"

void DemostracionNlados()
{
    //figura de N lados (crearemos un hexágono)
    Figura* f3 = new FiguraNLados(3, 6);
    //Se usaran las fórmulas del polígono regular
    cout << f3->ObtenerNombreDeFigura() << " - Area: " << f3->CalcularArea() << ", Perimetro: " << f3->CalcularPerimetro() << endl;

    delete f3; //eliminara la figura de N lados
}