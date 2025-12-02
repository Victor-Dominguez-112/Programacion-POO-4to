#include "HashTableChaining.h"
#include <iostream>
using namespace std;

void DemostracionHashTableChaining()
{
	HashTableChaining<int> myHashTable = HashTableChaining<int>(4);

	// Insertamos valores sin colisión.
	myHashTable.Add(39); // lista 3
	myHashTable.Add(252); // lista 0

	// Insertamos valores con colisión.
	myHashTable.Add(40); // colisión con 252
	myHashTable.Add(252); // colisión con 252 otra vez, pero debe quedar después de 40.
	// EN SU TAREA, AL AÑADIR ESTE SEGUNDO 252, DEBERÍA MANDAR UN THROW DE UNA EXCEPCIÓN PORQUE NO PERMITE REPETIDOS.

	cout << "dewspués de añadir con colisión al 40 y 252" << endl;
	myHashTable.Imprimir();

	// Prueba de funciones de encontrar y borrar
	myHashTable.Encontrar(40);
	myHashTable.BorrarValor(252); // debe borrar el primer 252, no el segundo.
	cout << "después de borrar el primer 252" << endl;
	myHashTable.Imprimir();

	HashTableChaining<string> myHashTableString = HashTableChaining<string>(27);

	// Insertamos valores sin colisión.
	myHashTableString.Add("Hola"); // lista H
	myHashTableString.Add("Mundo"); // lista M

	// Insertamos valores con colisión.
	myHashTableString.Add("Hello"); // colisión con Hola
}

void DemostracionHashSet()
{
	HashSet<int> valores(4); //creamos el hashset de 4 espacios 

	//insercion de los valores
	valores.Add(8);    //va a la lista del indice 0
	valores.Add(12);   //tenemos colision se agregara a la lista del indice 0
	valores.Add(16);   //tendremos otra colision y en el indice 0 
	valores.Add(9);    //este ira a la lista del indice 1
	valores.Add(13);   //tentremos colicion en el indice 1

	cout << "Insertados sin repetirse:" << endl;
	valores.Imprimir(); //imprimiremos las listas de los indices 0 y 1 ya llenas 

	cout << endl;
	cout << "Intentando insertar repetido:" << endl;
	//entramos con las excepciones 
	try //como colocamos que Add lanzara ell therow si encuentra algun duplicado necesitaremos este bloque para poder capturar el error 
	{
		//intentaremos meter el numero 8 otra vez pero Add detecta que se duplica y nos lanzara el throw y las lineas siguentes no se egetutaran porque pasamos al catch
		valores.Add(8);  
		valores.Add(16);  
		valores.Add(9);   
	}
	catch (exception& except)
	{
		//en este apartado madaremos a llamar el mensaje de error del .h en el apartado del throw
		cout << except.what() << endl; //y se mostrara en la consola
	}
	cout << endl;
	cout << "Tabla final:" << endl;
	valores.Imprimir(); //imprimimos 
}