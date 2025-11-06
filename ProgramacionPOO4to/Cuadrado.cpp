#include "Cuadrado.h"
using namespace std;

void DemostracionCuadrado()
{
    //cuadrado
    Figura* f2 = new Cuadrado(4); //creamos un Cuadrado con sus 4 lados
    //se llamaran las funciones de Cuadrado y no las de Figura
    cout << f2->ObtenerNombreDeFigura() << " - Area: " << f2->CalcularArea() << ", Perimetro: " << f2->CalcularPerimetro() << endl;

    //liberamos la memoria dinámica
    //como las fijuras fueron creadas con 'new' debemos de liberar la memoria manualmente con el 'delete'
    //y gracias al destructor virtual de la clase Figura, se llaman correctamente los destructores de cada una de las clases hijas que tenemos 
    delete f2; //eliminara el cuadrado
}
