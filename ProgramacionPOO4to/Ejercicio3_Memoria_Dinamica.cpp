#include <iostream>
using namespace std;

//Ejercicio 3		Ejercicio 3		Ejercicio 3 
//3) Declarar un puntero a flotante y asignarle el valor nullptr.
//3.1) Pedir memoria dinámica para dicho puntero, y que dentro tenga el valor 7.77.
//3.2) Declarar una variable de tipo flotante con un valor de 6.66.
//3.3) Hacer que ahora el puntero a flotante del punto 3) apunte a la dirección de memoria de la variable del punto 3.2).
//3.4) Imprimir en pantalla : "Cuidado, acabas de causar un memory leak!".
//3.5) Imprimir en pantalla un texto que describa por qué es un memory leak y qué deberías hacer para evitar dicho memory leak. (Pista: esto está en el archivo main de la clase!pueden ponerlo con sus propias palabras también).
//3.6) Pedir memoria dinámica(otra vez) para el puntero de 3) y asignarle el valor 1984.
//3.7) Hacer un nuevo puntero a float y hacer que apunte a la misma dirección que el puntero del punto 3.6).
//3.8) Después, liberar dicha memoria dinámica borrando el puntero de 3.6) y después asignarle a ese puntero el valor nullptr.
//3.9) Checar si ese puntero es igual a nullptr y si sí lo es, entonces imprimir que esa variable es igual a nullptr.
//3.10) Checar si ese puntero es igual a NULL y si sí lo es, entonces imprimir que esa variable es igual a NULL.
//3.11) Checar si el puntero de 3.7) es nullptr o NULL, y si no es ninguna de las dos, imprimir que esa variable no es nullptr ni NULL y que se debe tener cuidado de usar esa variable porque ya se borró la variable a donde apunta.

void MostrarEjercicio3()
{
	float* FloPtr = nullptr; //Creación del puntero float

	//Pedir memoria y dar el valor de 7.77
	FloPtr = new float;	//Pedimos espacio en la memoria
	*FloPtr = 7.77;		//Guardamos el valor
	cout << "Valor del puntero FloPtr es de: " << *FloPtr << endl;

	float valor = 6.66; //Declaramos una variable float con valor de 6.66

	FloPtr = &valor; //Hacemos que el puntero apunte a la dirección de valor

	//Advertencia de memory leak
	cout << "Cuidado, acabas de causar un memory leak" << endl;

	//Explicación memory leak
	cout << "Esto es un memory leak porque se perdió la referencia a la memoria que se pidio con new" << endl;
	cout << "Esa memoria ya no puede liberarse, porque el puntero ahora apunta a otro lugar." << endl;
	cout << "Para evitar esto se debio liberar la memoria con delete ptr; antes de poder reasignarlo." << endl;

	//Pedimos memoria dinámica y le asignamos un valor de 1984
	FloPtr = new float;
	*FloPtr = 1984;
	cout << "Nuevo valor asignado al puntero FloPtr: " << *FloPtr << endl;

	//Creamos un nuevo puntero que apunte al mismo lugar que el puntero FloPtr
	float* NewPtr = FloPtr;
	cout << "NewPtr apunta a sia el mismo valor que el puntero FloPtr: " << NewPtr << endl;

	//Liberamos la memoria y lo colocamos como nullptr
	delete FloPtr; //Libera la memoria
	FloPtr = nullptr;
	cout << "Se libero la memoria del puntero FloPtr y se le asigno el valor de nullptr" << endl;

	//Checamos si FloPtr es igual a nullptr
	if (FloPtr == nullptr)
	{
		cout << "El puntero FloPtr es de valor nullptr" << endl;
	}

	//Checamos si FloPtr es igual a NULL
	if (FloPtr == NULL)
	{
		cout << "El puntero FloPtr es de valor NULL" << endl;
	}

	//Checamos si NewPtr es nullptr o NULL
	if (NewPtr == nullptr || NewPtr == NULL)
	{
		cout << "El puntero NewPtr es del valor nullptr o NULL" << endl;
	}
	else
	{
		cout << "El puntero NewPtr no es nullptr o NULL" << endl;
		cout << "Cuidado: el puntero NewPtr apunta a memoria que ya ha sido liberada" << endl;
	}
	cout << endl;
	//Ejercicio 3		Ejercicio 3		Ejercicio 3
}