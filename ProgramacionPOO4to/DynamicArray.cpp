//1) Necesitan investigar sobre la sobrecarga de operadores(ya lo vimos por encima en clase) para poder hacer una sobrecarga del operador '[]' para la clase DynamicArray y as� poder acceder a los elementos como si fuera un array normalito.Por ejemplo :
//DynamicArray<int> myDynamicArray;
//myDynamicArray.Append(1984);
//cout << myDynamicArray[0] << endl; // debe imprimir 1984.
//1.1) Implementar las funciones push_back() y pop_back(), y que hagan lo que especifica la documentaci�n oficial sobre esos dos m�todos : https://cplusplus.com/reference/vector/vector/ 
//1.2) Hacer la funci�n shirnk_to_fit(), que hace un resize del DynamicArray para que su capacity sea igual que su count, esto hace que no se desperdicie memoria, ya que deja exactamente la necesaria para los elementos actualmente en el DynamicArray.Deja el cuerpo de la funci�n vac�o.De ah� su nombre "encogerse para ajustarse" o shrink_to_fit.

#include "DynamicArray.h"

DynamicArray::DynamicArray(int in_capacity)
{
	capacity = in_capacity;
	// Vamos a pedir N elementos en memoria, donde N = capacity,
	// y se los vamos a asignar a nuestro puntero elements.
	if (capacity > 0)
		elements = new int[capacity];
	else
		elements = nullptr; // si es 0, no pierdes tiempo pidiendo memoria din�mica que puede que no se use.

	count = 0; // le decimos que ahorita no tiene nada dentro, por lo tanto es 0.
}

DynamicArray::~DynamicArray()
{
	// si s� se pidi� memoria din�mica, entonces s� necesitamos hacer este delete.
	if (capacity > 0)
		// IMPORTANTE usar los '[]' cuando se hace delete de un arreglo de memoria din�mica.
		delete[] elements;
}

// como estamos pidiendo memoria din�mica, hay que recordar liberar memoria din�mica cuando ya no 
// sea necesaria. (Cuando se le hace delete a este objeto, o cuando sale del scope (las {}) donde se declar�)


void DemostracionDynamicArray()
{
	DynamicArray myDArray = DynamicArray(5);

	for (int i = 0; i < 6; i++)
	{
		myDArray.Append(i);
	}
	myDArray.Append(7);
	myDArray.Append(8);
	myDArray.Append(9);
	// aqu� ya se necesitar�a otra vez el resize, porque se acaban los espacios disponibles,
	// y ahora tendr�amos un array de 10*2 espacios, de los cuales tenemos ocupados 11.
	myDArray.Append(10);
	myDArray.Print();


	cout << "imprimiendo el array din�mico" << endl;
	for (int i = 0; i < myDArray.GetCount(); i++)
	{
		cout << myDArray.ObtenerElemento(i) << endl;
	}


	/* PRUEBAS DE LAS FUNCIONES QUE USTEDES HAR�N PARA LA TAREA */
	void push_back()
	{

	}

	void pop_back()
	{

	}

	void shirnk_to_fit()
	{

	}
}

//https://en.cppreference.com/w/cpp/container/vector.html
//https://www.youtube.com/watch?v=yzaO3_QGkNA
//https://cplusplus.com/reference/vector/vector/