#include "Cubo.h"

void DemostracionCubo()
{
    //cubo
    //el cubo hereda de Cuadrado, así que este tiene las funciones las cuales son las de CalcularArea(), CalcularPerimetro(), además de Volumen() y Surface()
    Cubo c(2); //lado que es igual a 2 unidades
    cout << c.ObtenerNombreDeFigura() << " - Volumen: " << c.Volumen() << ", Superficie: " << c.Surface() << endl;
}
