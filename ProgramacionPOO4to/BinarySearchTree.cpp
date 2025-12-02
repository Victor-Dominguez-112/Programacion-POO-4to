#include "BinarySearchTree.h"

void DemostracionBinarySearchTree()
{
	BinarySearchTree<float> myBST;

	/******* PRUEBAS DE ADD DEL ÁRBOL ****************************/

	myBST.Add(5); // caso del árbol vacío
	myBST.Add(3); // caso de primera vez de ir a la izquierda
	myBST.Add(8); // caso de primera vez de ir a la derecha

	// casos de ir por combinaciones de izquierdas-derechas
	myBST.Add(4);
	myBST.Add(7);
	myBST.Add(2);
	myBST.Add(9);

	myBST.InOrderRecursivo();

	myBST.PreOrderRecursivo();

	myBST.PostOrderRecursivo();

	cout << endl;
	// Buscamos el valor 6, que sabemos que no está en el árbol.
	bool seisEstaEnElArbol = myBST.Find(6); // se espera que sea false.
	if (seisEstaEnElArbol)
	{
		cout << "el valor 6 sí está en el árbol. \n";
	}
	else
	{
		cout << "el valor 6 no está en el árbol. \n";
	}

	bool cuatroEstaEnElArbol = myBST.Find(4); // se espera que sea true.
	if (cuatroEstaEnElArbol)
	{
		cout << "el valor 4 sí está en el árbol. \n";
	}
	else
	{
		cout << "el valor 4 no está en el árbol. \n";
	}

	float maxValue = myBST.MaxValue(); // se espera que sea 9
	cout << "El valor más alto del árbol es: " << maxValue << endl;

	float minValue = myBST.MinValue(); // se espera que sea 2
	cout << "El valor más bajo del árbol es: " << minValue << endl;

	pair<float, float> minimoYMaximo = myBST.ObtenerMinimoYMaximo();
	cout << "El valor más alto del árbol es: " << minimoYMaximo.second <<
		"; el más bajo es: " << minimoYMaximo.first << endl;

	float* raizMinimoYMaximo = myBST.ObtenerRaizMinimoYMaximo();
	cout << "La raíz del árbol es: " << raizMinimoYMaximo[0]
		<< " El valor más alto del árbol es: " << raizMinimoYMaximo[2] <<
		"; el más bajo es: " << raizMinimoYMaximo[1] << endl;

	delete[] raizMinimoYMaximo;

	vector<float> raizMinimoYMaximoConVector = myBST.ObtenerRaizMinimoYMaximoConVector();
	cout << "La raíz del árbol es: " << raizMinimoYMaximoConVector[0]
		<< " El valor más alto del árbol es: " << raizMinimoYMaximoConVector[2] <<
		"; el más bajo es: " << raizMinimoYMaximoConVector[1] << endl;


	// Pruebas de Sucesor
	// Casos 1	
	cout << "el siguiente de 3 debe ser 4 y fue: " << myBST.Siguiente(3) << endl; // Debe ser 4
	cout << "el siguiente de 5 debe ser 7 y fue: " << myBST.Siguiente(5) << endl; // Debe ser 7
	cout << "el siguiente de 8 debe ser 9 y fue: " << myBST.Siguiente(8) << endl;  // Debe ser 9

	// Casos 2
	cout << "el siguiente de 2 debe ser 3 y fue: " << myBST.Siguiente(2) << endl;  // Debe ser 3
	cout << "el siguiente de 4 debe ser 5 y fue: " << myBST.Siguiente(4) << endl;  // Debe ser 5
	cout << "el siguiente de 9 debe ser nullptr y fue: " << myBST.Siguiente(9) << endl;  // Debe ser nullptr


	// Pruebas de Predecesor
	// Casos 1	
	cout << "el predecesor de 3 debe ser 2 y fue: " << myBST.Anterior(3) << endl; // Debe ser 2
	cout << "el predecesor de 5 debe ser 4 y fue: " << myBST.Anterior(5) << endl; // Debe ser 4
	cout << "el predecesor de 8 debe ser 7 y fue: " << myBST.Anterior(8) << endl;  // Debe ser 7

	// Casos 2
	cout << "el predecesor de 2 debe ser nullptr y fue: " << myBST.Anterior(2) << endl;  // Debe ser nullptr
	cout << "el predecesor de 4 debe ser 3 y fue: " << myBST.Anterior(4) << endl;  // Debe ser 5
	cout << "el predecesor de 9 debe ser 8 y fue: " << myBST.Anterior(9) << endl;  // Debe ser 8


	//----------> PRUEBAS DE LA FUNCION SEARCH <----------
	cout << endl;
	cout << (myBST.Search(1) ? "El numero 1 SI ESTA" : "El numero 1 NO ESTA") << endl; //verificamos que el 1 existe en nuestro arbol y nos imprime el resultado
	cout << (myBST.Search(2) ? "El numero 2 SI ESTA" : "El numero 2 NO ESTA") << endl; //verificamos que el 2 existe en nuestro arbol y nos imprime el resultado
	cout << (myBST.Search(4) ? "El numero 4 SI ESTA" : "El numero 4 NO ESTA") << endl; //verificamos que el 4 existe en nuestro arbol y nos imprime el resultado
	cout << (myBST.Search(5) ? "El numero 5 SI ESTA" : "El numero 5 NO ESTA") << endl; //verificamos que el 5 existe en nuestro arbol y nos imprime el resultado
	cout << endl;
	//----------> PRUEBAS DE LA FUNCION SEARCH <----------


	
	// Para el caso 1 del borrado de nodos, necesitamos un nodo que no tenga hijos, por ejemplo el '2'
	myBST.BorrarPorValor(2); // Debe quitar al 2, que es hijo izquierdo del nodo 3.

	cout << "Despues de haber borrado al 2" << endl;
	myBST.InOrderRecursivo();


	// Para el caso 2, tenemos que borrar a alguien que solo tiene un hijo, por ejemplo el '3' que ya solo
	// tiene de hijo al 4, porque ya borramos al 2.
	myBST.BorrarPorValor(3);

	cout << "Despues de haber borrado al 3" << endl;
	myBST.InOrderRecursivo();

	cout << endl;
	// Probamos el caso 3, que es cuando el nodo tiene 2 hijos. El nodo 8 y el nodo 5 cumplen esta condición ahorita.
	myBST.BorrarPorValor(8);
	cout << "Despues de haber borrado al 8" << endl;
	myBST.InOrderRecursivo();

	myBST.BorrarPorValor(5);
	cout << "Despues de haber borrado al 5" << endl;
	myBST.InOrderRecursivo();

	myBST.BorrarPorValor(7);
	cout << "Despues de haber borrado al 7" << endl;
	myBST.InOrderRecursivo();

	myBST.BorrarPorValor(9);
	cout << "Despues de haber borrado al 9" << endl;
	myBST.InOrderRecursivo();

	myBST.BorrarPorValor(4);
	cout << "Despues de haber borrado al 4" << endl;
	myBST.InOrderRecursivo();
	
	// 5, 3, 8, 4, 7, 2, 9 // este nos genera un árbol de 3 pisos, perfectamente balanceado

	// 2, 3, 4, 5, 7, 8, 9 // esto nos genera el peor árbol posible, completamente desbalanceado, con N-pisos o niveles

	//myBST.Add(3); // caso de manejo de valores repetidos.


	//--------------------------------------------> EJERCICIO 3 <--------------------------------------------
	cout << endl;
	cout << "PRUEBAS EJERCICIO 3" << endl;
	//creamos otro arbol de 7 objetos
	myBST.Add(5); //raiz del arbol
	myBST.Add(3);
	myBST.Add(8);
	myBST.Add(4);
	myBST.Add(7);
	myBST.Add(2);
	myBST.Add(9);

	myBST.InOrderRecursivo(); //imprimiremos nuestro arbol y se ordenara
	myBST.DeletePostOrder();  //llamaremos la función que liberara la memoria y borra el arbol
	myBST.InOrderRecursivo(); //volvemos a imprimir el arbol y ahora esta vacio puesto que eliminamos arriba
	//--------------------------------------------> EJERCICIO 3 <--------------------------------------------

	//-----------------------------------> FUNCION POST - ORDER ITERATIVA <-----------------------------------
	cout << endl;
	cout << "PRUEBA FUNCION POST - ORDER ITERATIVA " << endl;
	//creamos otro arbol de 6 objetos
	myBST.Add(10); //nuestra raiz
	myBST.Add(5);
	myBST.Add(15);
	myBST.Add(2);
	myBST.Add(12);
	myBST.Add(20);
	
	cout << "PostOrder iterativo: ";
	myBST.PostOrderIterativo(); //mandamos a llamar la funcion para imprimir
	cout << endl;
	//-----------------------------------> FUNCION POST - ORDER ITERATIVA <-----------------------------------

}
