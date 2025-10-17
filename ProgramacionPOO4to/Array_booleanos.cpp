//Ejercicio de arrays y arrays como parámetros. 70 puntos.
//1) Hacer un array de 5 booleanos.
//1.1) Hacer una función que reciba un array de booleanos como parámetro, y el tamaño del array como otro parámetro.
//1.2) En dicha función, los valores del array se modifican de manera que los índices pares sean false y los impares true.
//1.3) Hacer un array de 10 enteros, inicializado con los valores del 0 al 9.
//1.4) Hacer una sobrecarga(es decir : mismo nombre, mismo tipo de retorno, pero distintos parámetros) de la función del punto 1.1) pero que reciba un array de enteros en vez de booleanos.
//1.5) En cada elemento del array remplazar el valor actual con el resultado de dicho valor % 2.
//1.6) En esta función NO pueden usar el operador '[]' para acceder a los elementos del array de enteros.Usen aritmética de punteros para acceder a las direcciones de memoria de los elementos del array. (para esto, recuerden que "*(punteroAEjemplo++);" // se mueve una dirección de memoria Y luego me da lo que hay dentro. )
//1.7) NO modifiquen la variable recibida como parámetro que apunta al array.En vez de eso, usen una variable auxiliar(que solo exista en esa función) para apuntar a la primera dirección de memoria del array y después usen aritmética de punteros para desplazar dicha variable auxiliar.
//1.8) Imprimir las direcciones de memoria de los elementos del array seguidos del valor resultante del % 2.

#include "Array_booleanos.h"
#include <iostream>
using namespace std;

void MyArray(bool Elarray[], int tamano)
{
	for (int i = 0; i < tamano; i++)
	{
		if (i % 2 == 0) //si nuestro índice es par lo vamos a guardar como false 
		{
			Elarray[i] = false;
		}
		else //si nuestro índice es impar entonces los guardaremos como true
		{
			Elarray[i] = true;
		}
	}
}

void MyArray(int Elarray[], int tamano)
{
	int* puntAux = Elarray;

	for (int i = 0; i < tamano; i++)
	{
		*puntAux = *puntAux % 2; //aquí guardamos el residuo del resultado de dividir entre 2 para el par e impar 

		cout << "Direccion: " << puntAux << " valor: " << *puntAux << endl; //mandamos a imprimir la dirección de nuestra memoria y a su vez el valor de esa posición
		puntAux++; //movemos el apuntador hacia la siguiente posición hasta terminar el ciclo 
	}

}

void MostrarArray_booleanos()
{
	//TAREA ARRAYS 
	bool arraydeBool[5]; //creamos un arreglo o array de un tamaño de 5 valores de tipo booleano

	MyArray(arraydeBool, 5); //llamada de la función que se encargara de llenarlo de forma alternada con el true/false 

	cout << "Array de booleanos modificado: ";
	for (int i = 0; i < 5; i++)
	{
		cout << (arraydeBool[i] ? "true" : "false") << " "; // ? abreviación del if a una sola línea (operador ternario)
		//si en este sale true imprimirá el mismo y viceversa con false 
	}
	cout << endl;

	int arrayInt[10]; //creamos un array de 10 números enteros 
	for (int i = 0; i < 10; i++)
	{
		arrayInt[i] = i; //será llenado con números del 0 al 9
	}
	MyArray(arrayInt, 10); //llamaremos la función restante para modificar y a su vez para la impresión
	//TAREA ARRAYS 
}

//Ayuda en forma para completar el ejercicio 
//https://www.youtube.com/watch?v=akox8OXnP2Y
//https://www.youtube.com/watch?v=_pcfFMFs9-g
//https://learn.microsoft.com/es-es/cpp/cpp/raw-pointers?view=msvc-170
//https://www.w3schools.com/cpp/cpp_pointers.asp