#pragma once
#include <iostream>

//Ejercicio de clases : 40 puntos.
//NOTA : para esta parte van a necesitar pensarle un poco más, por eso valor más.
//2) Hacer una clase(class) llamada Rect, la cual tiene dentro variables para almacenar una coordenada X, una coordenada Y, un alto y un ancho.Para que lo conceptualicen mejor, un Rect sería un rectángulo en un espacio 2D y X, Y nos define la posición dónde empieza y cuánto alto y ancho tiene a partir de esa posición.
//2.1) Hacer un constructor por defecto que ponga todos esos valores en 0.
//2.2) Hacer un constructor que reciba un parámetro para asignar a cada uno de esos valores.
//2.3) Hacer un constructor que reciba solo dos parámetros, uno para alto y otro para ancho y los asigne.Además, que a las coordenadas X y Y les ponga 0.
//2.4) Hacer una función(método) que reciba por referencia una variable de tipo Rect e imprima las coordenadas X y Y de dicha variable, así como las coordenadas X y Y donde terminaría ese Rect tomando en cuenta su Alto y Ancho.La función debe regresar false si al menos uno de los campos del Rect es menor que 0, y regresar true al final si todo sale bien.Además, saquen las coordenadas X y Y donde terminaría dicho Rect como dos parámetros por referencia.
//2.5) Hacer una función(método) llamada CheckOverlap que reciba dos Rect y regrese true si hay un traslape entre dichos Rect, es decir, si en al menos un punto ocupan el mismo espacio.De lo contrario, regresa false.Ejemplos: los rects{ X = 0, Y = 0, Alto = 5, Ancho = 5 } y{ X = 6, Y = 6, Alto = 5, Ancho = 5 } no se traslapan, mientras que{ X = 0, Y = 0, Alto = 5, Ancho = 5 } y{ X = 2, Y = 2, Alto = 2, Ancho = 2 } sí.También{ X = 0, Y = 0, Alto = 5, Ancho = 5 } y{ X = 1, Y = 1, Alto = 7.5, Ancho = 2 } se traslapan.Usen estos ejemplos en su código para demostrar que su función es correcta.
//2.6) 10 Puntos extra, usar la struct del otro ejercicio anterior para guardar los X, Y, Alto y Ancho.

//Declaracion de las funciones 
class Rect
{
private:
	float x; //Nuestra coordenada x
	float y; //Nuestra coordenada y
	float alto;  //Altura del rectangulo
	float ancho; //Ancho del rectangulo

public:
	Rect(); //Constructor por defecto

	Rect(float x1, float y1, float alto1, float ancho1); //Constructor con parametros

	Rect(float alto1, float ancho1); //Constructor con solo parametros de altura y ancho

	bool ImprimirRect(const Rect& rect1, float& finx, float& finy); //Impresion y calculo del rectangulo

	bool CheckOverlap(const Rect& rect11, const Rect& rect2); //Revision del traslape

	void Imprimir(); //Aux para valores del Rect
};

void EjecutarEjercicioRect();

//https://www.youtube.com/watch?v=VrZOaNpbmcI
// https://www.reddit.com/r/Cplusplus/comments/2kk77n/can_someone_explain_const_and/?tl=es-419
//https://learn.microsoft.com/es-es/cpp/cpp/constructors-cpp?view=msvc-170
//https://ants.inf.um.es/staff/jlaguna/tp/tutoriales/colisiones/index.html
//https://developer.mozilla.org/es/docs/Games/Techniques/2D_collision_detection
//https://learn.microsoft.com/es-es/cpp/cpp/destructors-cpp?view=msvc-170