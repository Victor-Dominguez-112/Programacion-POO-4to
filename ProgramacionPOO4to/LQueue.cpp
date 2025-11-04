#include "LQueue.h"

void DemostracionLQueue() //Funcion para poder demostrar cómo funciona la clase LQueue
{
    LQueue<string> cola;  //Creamos una cola (queue) de tipo string llamada 'cola'

    //Agregamos 3 elemtos a la cola usando la funcion llamada Enqueue
    cola.Enqueue("primero");
    cola.Enqueue("segundo");
    cola.Enqueue("tercero");

    cout << "Front: " << cola.Front() << endl; //Mostramos el elemento que esta al frente de la cola
    cout << "Dequeue: " << cola.Dequeue() << endl; //Eliminamos el primer elemento y lo mostramos
    cout << "Dequeue: " << cola.Dequeue() << endl; //Volvemos a eliminar el elemento y mostramos
    cout << "Front: " << cola.Front() << endl; //Mostramos otra vez cual es el elemento al inicio de la cola
    cout << "Elementos restantes: " << cola.GetCount() << endl; //Mostramos cuantos elementos tenemos en la cola
}
