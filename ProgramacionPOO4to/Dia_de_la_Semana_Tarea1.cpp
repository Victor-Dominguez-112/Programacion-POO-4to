//Ejercicio de Variables, Funciones y Condiciones. 40 puntos:Entregar un programa de c++ donde al ejecutarlo(presionar Depurar o F5) suceda lo siguiente :
//1) los días de la semana están representados por un valor del 0 al 6, van a tener una variable que diga qué día es,
//2) si es día lunes, se llame una función que imprima "es lunes",
//3) se llame a otra función que imprima "es jueves antes del mediodía" si es jueves antes de las 11:59 AM,
//4) se llame una función dentro de la cual, si es martes, se imprima "es martes" y si no, si es después de las 12:00 PM, se imprima "no es martes pero es después de las 12 PM".
//5) Se haga un ciclo For que se ejecute 1 vez por cada día de la semana, y por cada uno me imprima "Hoy no es DÍA" cuando no sea ese día, e imprima "Hoy sí es DÍA" cuando sí sea el día. (La primera ejecución correspondería al día lunes, la segunda al martes y así sucesivamente) (remplazar DÍA por el día que sí es).

#include "Dia_de_la_Semana_Tarea1.h"
#include <iostream>
using namespace std;

//Función encargada de la impresión de los lunes de acuerdo al dia que este preestablecido
void Lunes(int dia)
{
	if (dia == 1) //si se cumple con el dia que colocamos se imprimira el mensaje 
	{
		cout << "Hoy es lunes" << endl;
	}
}

//Función encargada de la impresión del dia jueves si el dia preestablecido es 4 y la hora menor a 12 se imprimirá el mensaje
void Juevesmediodia(int dia, int hora)
{
	if (dia == 4 && hora < 12) //si el dia coincide con el dado y la hora no supera la establecida se mostrara el mensaje
	{
		cout << "Es jueves antes del mediodia" << endl;
	}
}

//Función encargada de la impresión del martes si el dia preestablecido es 2 se imprimirá y si la hora es superior a las 12 imprimirá el segundo mensaje 
void Esmartes(int dia, int hora)
{
	if (dia == 2) //si el dia coincide se imprimira el mensaje 
	{
		cout << "Es martes" << endl;
	}
	else if (hora >= 12)	//si ell dia coincide pero aparte de eso la hora colocada es mayor a 12h.
	{						//este sera el mensaje que se mostrara puesto que cumple con el dia 2 pero la hora es superior.
		cout << "No es martes" << endl;
	}
}


void MostrarDiaSemana()
{
	//TAREA Dia_de_la_Semana
	int dia = 4; //seleccionamos un dia
	int hora = 5; //le damos una hora al sistema

	Lunes(dia);					//mandamos a llamar las funciones
	Juevesmediodia(dia, hora);	//mandamos a llamar las funciones
	Esmartes(dia, hora);		//mandamos a llamar las funciones

	string Semana[7] = { "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };

	for (int i = 0; i < 7; i++) //se entra al ciclo for y hasta encontrar el numero que coincida entre el array y el dia de la semana que le dimos nosotros   
	{
		if (dia == i)
		{
			cout << "Hoy si es " << Semana[i] << endl; //impresión con el dia o numero que coincida 
		}
		else
		{
			cout << "Hoy no es " << Semana[i] << endl; //el resto de impresiones de los días de la semana
		}
	}
	cout << endl;
	//TAREA Dia_de_la_Semana
}