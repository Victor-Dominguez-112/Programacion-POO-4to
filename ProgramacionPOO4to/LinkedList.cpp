#include "LinkedList.h"

#include <iostream>
using namespace std;

void DemostracionLinkedList()
{
	LinkedList<string> myLinkedList;
	myLinkedList.Append("Juan"); // para mostrar el caso donde la lista está vacía
	myLinkedList.Append("Pedro"); // este para cuando solo hay un elemento
	myLinkedList.Append("Luis"); // un tercer elemento para corroborar que el while de append está bien!
	myLinkedList.Append("Maria");

	string result = myLinkedList.GetByIndex(2); // debe de dar a Luis

	//	le decimos que ponga a pepe después de Juan
	bool resultadoDeInsercion = myLinkedList.InsertAfterValue("Juan", "Pepe");
	if (resultadoDeInsercion)
	{
		cout << "si se inserto el valor Pepe despues de Juan" << endl;
	}
	else
	{
		cout << "no se inserto el valor porque no se encontro el valorAEncontrar" << endl;
	}

	cout << myLinkedList.Front() << " es el nodo hasta el frente de la lista" << endl;
	cout << myLinkedList.Back() << " es el nodo hasta el final de la lista" << endl;

	// borrar primer elemento
	myLinkedList.BorrarNodoPorValor("Juan");
	// borrar elemento del medio
	myLinkedList.BorrarNodoPorValor("Luis");
	// borrar el último elemento
	myLinkedList.BorrarNodoPorValor("Maria");

	myLinkedList.BorrarNodoPorValor("Pepe");
	myLinkedList.BorrarNodoPorValor("Pedro");
	// probar borrar cuando no está el valor
	myLinkedList.BorrarNodoPorValor("Inexistente");

	// si yo mando a llamar la función Front cuando la lista ligada está vacía.
	myLinkedList.Front();
	myLinkedList.Back();

	/* PRUEBAS DE FUNCIONES QUE HICIERON PARA SU TAREA */
	myLinkedList.PushFront("Victor");
	myLinkedList.PushFront("Eduardo");
	myLinkedList.Print();
	myLinkedList.PopFront();
	myLinkedList.Print();
}