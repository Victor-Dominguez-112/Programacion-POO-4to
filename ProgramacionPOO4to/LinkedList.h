#pragma once
#include <iostream>
using namespace std;

// Las cosas templates SÍ pueden dejar la declaración Y definición en el .h

//template <typename T>
//class Node
//{
//	T data;
//	Node<T>* next;
//};
//
//template <typename T>
//class Node
//{
//	T data;
//	Node<T>* parent;
//	Node<T>* right;
//	Node<T>* left;
//};


template <typename T>
class LinkedList
{
public:
	LinkedList()
	{
		count = 0; // si inicia vacía, su count sería 0.
		// y si va a empezar vacía, no necesitamos pedir memoria para el primer elemento.
		first = nullptr; // como no se va a usar ahorita todavía, lo ponemos como nullptr.
	}

	// nada más por el estándar de cómo se llama la función en las listas ligadas.
	void PushBack(const T value)
	{
		Append(value);
	}

	// Añade un nodo con el valor "value" al final de la lista ligada.
	void Append(const T value)
	{
		// tenemos que checar el caso en el que first es nullptr. Es decir, cuando la lista está vacía.
		if (first == nullptr)
		{
			first = new Node(value);
			count++;
			return; // ya lo pusimos al frente y después de él es nullptr, entonces ya es el primero de la lista (y también el último)
		}

		// comenzamos al inicio de la lista (el nodo first)
		Node* nodoActual = first;
		// y avanzamos el "next" de los nodos, hasta el final de la lista (cuando el next del nodo actual sea nullptr)
		// nodoActual se va convirtiendo en SU next hasta que ya sea nullptr.
		while (nodoActual->next != nullptr)
		{
			nodoActual = nodoActual->next; // el nodo actual se mueve al que le sigue en la lista.
		}

		// cuando se sale de este while, es que ya llegamos al final de la lista.
		// y entonces añadimos un nuevo nodo con el valor value.
		Node* nuevoNodo = new Node(value);
		// El nodo que antes era el último, ahora es el penúltimo, 
		// y nuevoNodo es el último (porque su next es nullptr).
		nodoActual->next = nuevoNodo;
		count++;
	}

	// por ejemplo: insertar "Pepe" después de "Juan"
	bool InsertAfterValue(T valorAEncontrar, T valorAInsertar)
	{
		// encontrar el nodo donde está valorAEncontrar
		// comenzamos al inicio de la lista (el nodo first)
		Node* nodoActual = first;
		// y avanzamos el "next" de los nodos, checando si su valor es valorAEncontrar,
		// 
		// y si no lo encontramos, regresamos false porque nunca lo encontramos.		// 
		while (nodoActual != nullptr)
		{
			// checamos si este nodo tiene el valorAEncontrar
			if (nodoActual->data == valorAEncontrar)
			{
				// si sí lo es, pues insertamos el nuevo valor después de este.
				// primero creamos un nuevo nodo que va a tener el valorAInsertar
				Node* newNode = new Node(valorAInsertar);
				// el nuevo->next ahora al que antes apuntaba nodoActual->next
				newNode->next = nodoActual->next;

				// el nodoActual->next ahora apunta al nuevo
				nodoActual->next = newNode;

				count++;

				// como ya lo insertamos, ya no hay nada que hacer y nos salimos.
				return true;
			}

			nodoActual = nodoActual->next; // el nodo actual se mueve al que le sigue en la lista.
		}

		// ya no hay más nodos que checar, no se encontró entonces no insertamos nada y regresamos false.
		cout << "Advertencia, no existe el valor: " << valorAEncontrar << " en esta lista ligada" << endl;
		return false;
	}

	// Función que nos quite el primer nodo que tenga el valor dado.
	bool BorrarNodoPorValor(const T valorDelNodoABorrar)
	{
		if (count == 0)
		{
			// no hay nada que borrar porque está vacía.
			cout << "Advertencia, tratando de borrar de una lista ligada vacia en BorrarNodoPorValor()." << endl;
			return false;
		}
		// hay que encontrar el primer nodo que tenga data == valorDelNodoABorrar
		// encontrar el nodo donde está valorAEncontrar
		// comenzamos al inicio de la lista (el nodo first)
		Node* nodoActual = first;
		if (nodoActual->data == valorDelNodoABorrar)
		{
			// es un caso especial porque hay que reasignar al first.

			first = nodoActual->next;
			delete nodoActual;
			if (count == 1)
				first = nullptr;
			count--;
			return true;
		}

		while (nodoActual->next != nullptr)
		{
			// checamos si EL NODO QUE SIGUE este nodo es a quien buscamos (el que tiene valorDelNodoABorrar)
			if (nodoActual->next->data == valorDelNodoABorrar)
			{
				// sí lo encontramos, entonces lo borramos.
				Node* nodoABorrar = nodoActual->next;
				// el nodo actual apunta al que sigue del que sigue

				nodoActual->next = nodoActual->next->next;

				// y ahora sí borramos a ese nodo auxiliar.
				delete nodoABorrar;

				count--;
				return true;
			}

			nodoActual = nodoActual->next; // el nodo actual se mueve al que le sigue en la lista.
		}

		// si se acaba el while, entonces no lo encontramos, 


		// entonces no borramos nada y regresamos false.
		cout << "Advertencia, no existe el valor: " << valorDelNodoABorrar << " en esta lista ligada" << endl;
		return false;
	}

	bool Encontrar(const T valorAEncontrar)
	{
		if (count == 0)
		{
			// no hay nada que borrar porque está vacía.
			cout << "Advertencia, llamando Encontrar de una lista ligada vacía." << endl;
			return false;
		}
		// hay que encontrar el primer nodo que tenga data == valorDelNodoABorrar
		// encontrar el nodo donde está valorAEncontrar
		// comenzamos al inicio de la lista (el nodo first)
		Node* nodoActual = first;

		while (nodoActual != nullptr)
		{
			// checamos si EL NODO QUE SIGUE este nodo es a quien buscamos (el que tiene valorDelNodoABorrar)
			if (nodoActual->data == valorAEncontrar)
			{
				return true;
			}
			nodoActual = nodoActual->next; // el nodo actual se mueve al que le sigue en la lista.
		}

		// si se acaba el while, entonces no lo encontramos, 
		return false;
	}

	// regresa el valor almacenado en el nodo del inicio de la lista ligada
	T Front()
	{
		if (first != nullptr)
			return first->data;

		// si sí es nulo, entonces le imprimes un error al usuario: 
		cout << "Advertencia se pidio el front de la lista ligada pero esta vacia." << endl;
		return T{}; // regresamos el valor T por defecto, según el tipo que sea T.
	}

	// regresa el valor almacenado en el nodo al final de la lista ligada
	T Back()
	{
		if (count == 0)
		{
			cout << "Advertencia se pidio el Back de la lista ligada pero esta vacia." << endl;
			return T{}; // regresamos el valor T por defecto, según el tipo que sea T.
		}

		// ciclo para llegar hasta el último nodo de la lista.
		Node* nodoActual = first;
		while (nodoActual->next != nullptr)
		{
			nodoActual = nodoActual->next;
		}

		// ya llegamos al final, entonces regresamos la data de ese nodo.
		return nodoActual->data;
	}

	// función que nos da el valor (los datos) del Nodo i-ésimo de la lista.
	T GetByIndex(const size_t indice) const  // como es size_t no puede ser negativo.
	{
		if (indice >= count)
		{
			cout << "ERROR: intentando acceder a un nodo con un indice invalido." << endl;
			return T{}; // retornamos un valor por defecto.
		}

		// necesitamos acceder desde el first, 
		Node* nodoActual = first;

		// y desde él avanzar n posiciones, hacer n movimientos hacia el next, con n = indice.
		for (int i = 0; i < indice; i++)
		{
			nodoActual = nodoActual->next;
		}
		// ya llegaste al i-ésimo que te pidieron, y retornas su valor
		return nodoActual->data;
	}

	/* LAS DE TAREA */
	//  https://cplusplus.com/reference/.
	void PushFront(const T value)
	{
		Node* nuevoNodo = new Node(value); //creamos un nodo con el valor que deseaos insertar
		nuevoNodo->next = first; //apuntamos el nuevo nodo al que esta justo enfrente  
		first = nuevoNodo; //actualizamos first para que este apunte hacia el nuevo nodo
		count++; //aumentamos el contador 
	}

	void PopFront()
	{
		if (first == nullptr) //checamos si la lista se encuantra vacia
		{
			cout << "Advertencia, se esta intentando hacer PopFront en una lista vacia" << endl;
			return;
		}
		Node* nodoAEliminar = first; //guardamos el nodo que se valla a eliminar
		first = first->next; //actualizamos a first para que este apunte al siguente nodo
		delete nodoAEliminar; //liberamos la memoria del nodo que fue eliminado
		count--; //disminuimos el contador
	}

	void Print()
	{
		Node* nodoActual = first; //empezamos en el primer nodo
		cout << "LinkedList: "; //recoremos toda la lisa hasta llegar all final de la misma
		while (nodoActual != nullptr)
		{
			cout << nodoActual->data << " - "; //imprimimos los nombres 
			nodoActual = nodoActual->next; //nos movemos asia el siguente nodo
		}
		cout << "NULL" << endl; //indicamos el final de la lista
	}

	void EliminarMemoria() //creamos la funcion para poder liberar la memoria 
	{
		Node* nodoActual = first; //empezamos con el primer nodo de la lista
		while (nodoActual != nullptr) //mientras aun tengamos nodos por recorer para llegar al final
		{
			Node* nodoAEliminar = nodoActual; //guardamos el nodo actual para que se elimine despues
			nodoActual = nodoActual->next; //nos movemos hacia el siguente nodo
			delete nodoAEliminar; //liberamos la memoria de nodo en que estemos o el actual
		}
		first = nullptr; //reiniciamos el puntero al inicio
		count = 0; //tambien reiniciamos el contador de los nodos
	}

	int Size() const //Funcion de ayuda para saber el tamaño despues de la funcion de limpiar
	{
		return count; //regresamos el tamaño de la variable 
	}

	int GetCount()
	{
		return count;
	}

	// Encontrar dónde nos falta liberar memoria en esta clase. Si sí hace falta impleméntenlo, 
	// si no hace falta, expliquen por qué.

private:
	// clase anidada.
	// Sirve para que este node en específico solo exista dentro de las funciones de la clase LinkedList.
	class Node
	{
	public:
		Node(T _data)
		{
			data = _data;
			next = nullptr;
		}

		T data; // los datos que realmente se guardan en la lista
		Node* next; // cuál nodo sigue de este nodo, en la lista ligada.
		// si next == nullptr, entonces este nodo es el último de la lista.
	};

	Node* first; // el puntero al primer nodo de nuestra lista.
	int count; // cuántos elementos tiene dentro esta lista.

};

void DemostracionLinkedList();
