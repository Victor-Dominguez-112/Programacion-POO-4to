#pragma once
#include <iostream>

//Ejercicio Estructuras : 35 puntos.
//1) Hacer una estructura(struct) llamada VectorDeValores.
//1.1) Internamente tiene dos variables, uno es un puntero a float, y la otra es un int para el tama�o del array.
//1.2) Hacer un constructor que reciba como par�metros un array de floats y un int del tama�o del array de floats y los asigne a las variables internas.
//1.3) Hacer un destructor que libere la memoria din�mica solicitada, e imprima cu�ntos elementos liber�.
//1.4) Hacer un constructor por defecto, que ponga el tama�o del array en 2, y pida la memoria din�mica correspondiente, y despu�s inicialice esos valores en 0.

struct VectorDeValores
{
	float* puntFloat; //Puntero de tipo float
	int tamanoArray;  //Tama�o del array

	//Declaraci�n de las funciones 
	VectorDeValores(float myArray[], int tamano); //constructor (con par�metros)

	VectorDeValores();//constructor (por defecto)

	~VectorDeValores();//destructor
};

void EjecutarEjercicioVectorDeValores();

//https://learn.microsoft.com/es-es/cpp/cpp/destructors-cpp?view=msvc-170
//https://isocpp.org/wiki/faq/dtors