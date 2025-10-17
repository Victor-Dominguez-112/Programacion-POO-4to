#include <iostream>
#include "Ejercicio2_clases.h"
using namespace std;

//Ejercicio de clases : 40 puntos.
//NOTA : para esta parte van a necesitar pensarle un poco más, por eso valor más.
//2) Hacer una clase(class) llamada Rect, la cual tiene dentro variables para almacenar una coordenada X, una coordenada Y, un alto y un ancho.Para que lo conceptualicen mejor, un Rect sería un rectángulo en un espacio 2D y X, Y nos define la posición dónde empieza y cuánto alto y ancho tiene a partir de esa posición.
//2.1) Hacer un constructor por defecto que ponga todos esos valores en 0.
//2.2) Hacer un constructor que reciba un parámetro para asignar a cada uno de esos valores.
//2.3) Hacer un constructor que reciba solo dos parámetros, uno para alto y otro para ancho y los asigne.Además, que a las coordenadas X y Y les ponga 0.
//2.4) Hacer una función(método) que reciba por referencia una variable de tipo Rect e imprima las coordenadas X y Y de dicha variable, así como las coordenadas X y Y donde terminaría ese Rect tomando en cuenta su Alto y Ancho.La función debe regresar false si al menos uno de los campos del Rect es menor que 0, y regresar true al final si todo sale bien.Además, saquen las coordenadas X y Y donde terminaría dicho Rect como dos parámetros por referencia.
//2.5) Hacer una función(método) llamada CheckOverlap que reciba dos Rect y regrese true si hay un traslape entre dichos Rect, es decir, si en al menos un punto ocupan el mismo espacio.De lo contrario, regresa false.Ejemplos: los rects{ X = 0, Y = 0, Alto = 5, Ancho = 5 } y{ X = 6, Y = 6, Alto = 5, Ancho = 5 } no se traslapan, mientras que{ X = 0, Y = 0, Alto = 5, Ancho = 5 } y{ X = 2, Y = 2, Alto = 2, Ancho = 2 } sí.También{ X = 0, Y = 0, Alto = 5, Ancho = 5 } y{ X = 1, Y = 1, Alto = 7.5, Ancho = 2 } se traslapan.Usen estos ejemplos en su código para demostrar que su función es correcta.
//2.6) 10 Puntos extra, usar la struct del otro ejercicio anterior para guardar los X, Y, Alto y Ancho.

//Constructor (defecto)
Rect::Rect()
{
	x = 0;
	y = 0;
	alto = 0;
	ancho = 0;
}

//Constructor con parametros
Rect::Rect(float x1, float y1, float alto1, float ancho1)
{
	x = x1;
	y = y1;
	ancho = ancho1;
	alto = alto1;
}

//Constructor con solo parametros de altura y ancho
Rect::Rect(float alto1, float ancho1)
{
	x = 0;
	y = 0;
	alto = alto1;
	ancho = ancho1;
}

//Impresion y calculo del rectangulo
bool Rect::ImprimirRect(const Rect& rect1, float& finx, float& finy)
{
	if (rect1.x < 0 || rect1.y < 0 || rect1.alto < 0 || rect1.ancho < 0)
	{
		cout << "Uno de los valores del Rectangulo es 0" << endl;
		return false;
	}

	finx = rect1.x + rect1.ancho;
	finy = rect1.y + rect1.alto;

	cout << "Rectnngulo en la posicion ( " << rect1.x << ", " << rect1.y << ")" << endl;
	cout << "Hasta la posicion de ( " << finx << ", " << finy << ")" << endl;

	return true;
}

//Revision del traslape
bool Rect::CheckOverlap(const Rect& rect11, const Rect& rect2)
{
	//Si uno esta a la derech o izquierda del otro
	if (rect11.x + rect11.ancho <= rect2.x || rect2.x + rect2.ancho <= rect11.x);
	return false;

	//Si uno esta arriba o debajo del otro
	if (rect11.y + rect11.alto <= rect2.y || rect2.y + rect2.alto <= rect11.y);
	return false;

	return true; //Si no hay ningún traslape
}

// Aux para valores del Rect8
void Rect::Imprimir()
{
	cout << "Rectangulo (X = " << x << ", Y =" << y << " Alto = " << alto << ", Ancho " << ancho << ")" << endl;
}

void EjecutarEjercicioRect()
{
	//Ejercicio 2		Ejercicio 2		Ejercicio 2 
	Rect rect1;
	rect1.Imprimir();

	Rect rect2(0, 0, 5, 5);
	rect2.Imprimir();

	Rect rect3(10, 3);
	rect3.Imprimir();

	float finx, finy;
	if (rect2.ImprimirRect(rect2, finx, finy))
	{
		cout << "El rectangulo terminara en (" << finx << ", " << finy << ")" << endl;
	}

	Rect a(0, 0, 5, 5);
	Rect b(6, 6, 5, 5);
	Rect c(2, 2, 2, 2);
	Rect d(1, 1, 7.5, 2);

	cout << "\nPruebas del traslape" << endl;
	cout << "A Y B se traslapan " << (a.CheckOverlap(a, b) ? "SI" : "NO") << endl;
	cout << "A Y C se traslapan " << (a.CheckOverlap(a, c) ? "SI" : "NO") << endl;
	cout << "A Y D se traslapan " << (a.CheckOverlap(a, d) ? "SI" : "NO") << endl;
	cout << endl;
	cout << endl;
	//Ejercicio 2		Ejercicio 2		Ejercicio 2 
}