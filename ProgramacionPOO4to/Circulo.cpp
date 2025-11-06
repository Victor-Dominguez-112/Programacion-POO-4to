#include "Circulo.h"
#include "EjercicioHerencia.h"
using namespace std;

void DemostracionCirculo()
{
	//circulo
	Figura* f1 = new Circulo(5); //le damos un radio de valor de 5
	//al llamar a CalcularArea() y CalcularPerimetro() se ejecutanran las versiones que estan en la clase de Circulo no las de la clase Figura
	cout << f1->ObtenerNombreDeFigura() << " - Area: " << f1->CalcularArea() << ", Perimetro: " << f1->CalcularPerimetro() << endl;

	//liberamos la memoria dinámica
	//como las fijuras fueron creadas con 'new' debemos de liberar la memoria manualmente con el 'delete'
	//y gracias al destructor virtual de la clase Figura, se llaman correctamente los destructores de cada una de las clases hijas que tenemos 
	delete f1; //eliminara el circulo
}