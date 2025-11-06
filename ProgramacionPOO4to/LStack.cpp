#include "LStack.h"

void DemostracionLStack()
{
    cout << "   Ejercicio LStack" << endl;

    LStack<string> pila; //creamos una pila de solo strings

    //agregamos los elementos a la pila
    pila.Push("primero");
    pila.Push("segundo");
    pila.Push("tercero");

    //peek buscamos el tope de la pila sin eliminarlo
    cout << "Peek: " << pila.Peek() << endl;  //espera a tercero

    //pop quitamos y devolvemos el tope
    cout << "Pop: " << pila.Pop() << endl; //sacara tercero
    cout << "Pop: " << pila.Pop() << endl; //sacara segundo

    //ahora nuestro tope deberá de ser primero
    cout << "Peek (tope de ahora): " << pila.Peek() << endl; // espera "primero"

    //count/GetCount
    cout << "Elementos restantes: " << pila.GetCount() << endl;

    //eliminamos o vaciamos y probamos a Pop en la pila vacía
    pila.Clear();
    cout << "Después de Clear, IsEmpty? " << (pila.IsEmpty() ? "Sí" : "No") << endl;
    cout << "Pop en pila vacía: " << pila.Pop() << endl; //mostramos el error y devolvemos el valor que esta por defecto
}
