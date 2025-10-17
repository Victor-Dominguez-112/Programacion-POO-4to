//Ejercicio Estructuras : 35 puntos.
//1) Hacer una estructura(struct) llamada VectorDeValores.
//1.1) Internamente tiene dos variables, uno es un puntero a float, y la otra es un int para el tama�o del array.
//1.2) Hacer un constructor que reciba como par�metros un array de floats y un int del tama�o del array de floats y los asigne a las variables internas.
//1.3) Hacer un destructor que libere la memoria din�mica solicitada, e imprima cu�ntos elementos liber�.
//1.4) Hacer un constructor por defecto, que ponga el tama�o del array en 2, y pida la memoria din�mica correspondiente, y despu�s inicialice esos valores en 0.

#include "Ejercicio1_Estructuras.h"
#include <iostream>
using namespace std;

//Constructor con par�metros
VectorDeValores::VectorDeValores(float myArray[], int tamano)
{

	if (tamano <= 0)
	{
		cout << "ERROR: El tama�o del array debe de ser mayor que 0" << endl;
		puntFloat = nullptr;
		tamanoArray = 0;
		return;
	}

	tamanoArray = tamano;
	puntFloat = new float[tamanoArray]; //pediremos memoria para la variable Tama�oArray
	for (int i = 0; i < tamanoArray; i++)
	{
		puntFloat[i] = myArray[i]; //Copiaremos los valores
	}
	cout << "Creacion de un vector con " << tamanoArray << " elementos" << endl;
}

//Destructor
VectorDeValores::~VectorDeValores()
{
	if (puntFloat != nullptr)
	{
		cout << "Se elimino un vector con " << tamanoArray << " elementos" << endl;
		delete[] puntFloat; //Liberamos la memoria ocupada o eliminar
		puntFloat = nullptr;
	}
	else
	{
		cout << "No hay memoria por liberar ahora" << endl;
	}
}

//Constructor por defecto
VectorDeValores::VectorDeValores()
{
	tamanoArray = 2; //Damos un tama�o de 2
	puntFloat = new float[tamanoArray]; //pedimos la memoria
	for (int i = 0; i < tamanoArray; i++)
	{
		puntFloat[i] = 0; //Iniciamos en 0
	}
	cout << "Creacion de un vector con tamano de " << tamanoArray << endl;
}

void EjecutarEjercicioVectorDeValores()
{
	//Ejercicio 1		Ejercicio 1		Ejercicio 1 
	//Destructor por defecto
	VectorDeValores Uno;
	cout << "Vector De Valores numero Uno: ";
	for (int i = 0; i < Uno.tamanoArray; i++)
	{
		cout << Uno.puntFloat[i] << " ";
	}
	cout << endl;

	// Destructor con par�metros
	float array[3] = { 1.5,2.5,3.5 };
	VectorDeValores Dos;
	cout << "Vector De Valores numero Dos: ";
	for (int i = 0; i < Dos.tamanoArray; i++)
	{
		cout << Dos.puntFloat[i] << " ";
	}
	cout << endl;
	//Ejercicio 1		Ejercicio 1		Ejercicio 1
}