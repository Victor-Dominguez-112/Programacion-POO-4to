//1) Necesitan investigar sobre la sobrecarga de operadores(ya lo vimos por encima en clase) para poder hacer una sobrecarga del operador '[]' para la clase DynamicArray y así poder acceder a los elementos como si fuera un array normalito.Por ejemplo :
//DynamicArray<int> myDynamicArray;
//myDynamicArray.Append(1984);
//cout << myDynamicArray[0] << endl; // debe imprimir 1984.
//1.1) Implementar las funciones push_back() y pop_back(), y que hagan lo que especifica la documentación oficial sobre esos dos métodos : https://cplusplus.com/reference/vector/vector/ 
//1.2) Hacer la función shirnk_to_fit(), que hace un resize del DynamicArray para que su capacity sea igual que su count, esto hace que no se desperdicie memoria, ya que deja exactamente la necesaria para los elementos actualmente en el DynamicArray.Deja el cuerpo de la función vacío.De ahí su nombre "encogerse para ajustarse" o shrink_to_fit.

#include "DynamicArray.h"

DynamicArray::DynamicArray(int in_capacity)
{
	capacity = in_capacity;
	// Vamos a pedir N elementos en memoria, donde N = capacity,
	// y se los vamos a asignar a nuestro puntero elements.
	if (capacity > 0)
		elements = new int[capacity];
	else
		elements = nullptr; // si es 0, no pierdes tiempo pidiendo memoria dinámica que puede que no se use.

	count = 0; // le decimos que ahorita no tiene nada dentro, por lo tanto es 0.

#if COUNT_DYNAMIC_ARRAY_COPIES
	copyCounter = 0;
#endif
}

DynamicArray::~DynamicArray()
{
	// si sí se pidió memoria dinámica, entonces sí necesitamos hacer este delete.
	if (capacity > 0)
		// IMPORTANTE usar los '[]' cuando se hace delete de un arreglo de memoria dinámica.
		delete[] elements;
}

#if COUNT_DYNAMIC_ARRAY_COPIES
int DynamicArray::getCopyCounter()
{
	return copyCounter; //mostramos cuantas copias realizamos
}
#endif

// como estamos pidiendo memoria dinámica, hay que recordar liberar memoria dinámica cuando ya no 
// sea necesaria. (Cuando se le hace delete a este objeto, o cuando sale del scope (las {}) donde se declaró)


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
	// aquí ya se necesitaría otra vez el resize, porque se acaban los espacios disponibles,
	// y ahora tendríamos un array de 10*2 espacios, de los cuales tenemos ocupados 11.
	myDArray.Append(10);
	myDArray.Print();


	cout << "imprimiendo el array dinamico" << endl;
	for (int i = 0; i < myDArray.GetCount(); i++)
	{
		cout << myDArray.ObtenerElemento(i) << endl; 
	}

	/* PRUEBAS DE LAS FUNCIONES QUE USTEDES HARÁN PARA LA TAREA */
	//push_back
	myDArray.push_back(11); //agregamos un elemento mas 
	myDArray.Print(); //imprimimos

	//pop_back
	cout << "Quitando el ultimo elemento: " << myDArray.pop_back() << endl; //quitamos el ultimo elemento el cual es 11 
	myDArray.Print(); //imprimimos

	//shrink_to_fit
	myDArray.shrink_to_fit(); //reducimos la capacidad (capacity) para que sea igual que count
	cout << "Capacidad despues de hacer shrink_to_fit: " << myDArray.GetCount() << endl; //imprimimos la capacidad actual 

#if COUNT_DYNAMIC_ARRAY_COPIES
	cout << "Copias que fueron realizadas durante el resize: " << myDArray.getCopyCounter() << endl; //mandamos a imprimir cuantas copias se realizaron durante el porpoceso
#endif

}

//https://en.cppreference.com/w/cpp/container/vector.html
//https://www.youtube.com/watch?v=yzaO3_QGkNA
//https://cplusplus.com/reference/vector/vector/

//https://learn.microsoft.com/es-es/cpp/preprocessor/hash-ifdef-and-hash-ifndef-directives-c-cpp?view=msvc-170
//https://www.reddit.com/r/cpp_questions/comments/j7wfef/what_is_the_need_for_ifndef_define_endif_inside/?tl=es-419

//https://www.programiz.com/cpp-programming/operator-overloading
//https://www.geeksforgeeks.org/cpp/operator-overloading-cpp/
//https://learn.microsoft.com/en-us/cpp/cpp/operator-overloading?view=msvc-170