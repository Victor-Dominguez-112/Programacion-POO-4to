#include "Linea.h"

void DemostracionLinea()
{
    //línea
    //creamos una línea a partir de un arreglo de segmentos en el que cada elemento representa la longitud de un tramo de la línea
    float segmentos[] = { 1.5, 2.0, 3.2 };
    Figura* myLine = new Linea(segmentos, 3);
    cout << myLine->ObtenerNombreDeFigura() << " - Area: " << myLine->CalcularArea() << ", Perimetro: " << myLine->CalcularPerimetro() << endl; //CalcularArea() = 0 siempre y CalcularPerimetro() es igual a la suma de segmentos

    //liberamos la memoria dinámica
    //como las fijuras fueron creadas con 'new' debemos de liberar la memoria manualmente con el 'delete'
    //y gracias al destructor virtual de la clase Figura, se llaman correctamente los destructores de cada una de las clases hijas que tenemos 
    delete myLine; //eliminara la linea
}
