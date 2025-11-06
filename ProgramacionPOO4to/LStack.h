#pragma once
#include <forward_list> 
#include <iostream>
using namespace std;

template <typename T>
class LStack
{
private:
    std::forward_list<T> data; //creamos la forward_list
    int count;                //contador auxiliar para el GetCount
                             
public:
    LStack() //Constructor inicializara el contador en 0
    {
        count = 0; //la forward_list ya se inicializara vacía o sola automáticamente
    }

    ~LStack() = default; //Creamos un Destructor que este por defecto que se encargara de liberar la memoria automáticamente

    //devolvemos la cantidad de los elementos en nuestra pila
    int GetCount() const
    {
        return count;
    }

    //insertamos un elemento al tope de la pila
    void Push(T value) //esto es idéntico a la funcion de Stack creada en clase y esta no devolverá nada
    {
        //push_front colocara al inicio en un tiempo constante
        data.push_front(value);
        count++; //aumentamos nuestro contador auxiliar 
    }

    //eliminamos y devolvemos el elemento del que esta en el tope 
    //si nuestra pila se encuentra está vacía, mostrara un mensaje y regresara T{} que es el valor por defecto
    T Pop()
    {
        if (data.empty())
        {
            cout << "Error: intentar hacer Pop en una pila vacía" << endl;
            return T{}; //regresamos al por defecto que es de tipo T
        }

        T value = data.front(); //obtenemos el elemento del inicio o el que esta en el tope

        data.pop_front(); //eliminamos el que esta al inicio

        count--; //actualizamos otra vez el contador pero esta vez decrementamos el mismo

        return value; //regresamos el valor que fue eliminado
    }

    //devolvemos el elemento que esta al inicio sin eliminarlo 
    //si nuestra pila se encuentra vacía, mostrara el mensaje y regresara T{}
    T Peek() const
    {
        if (data.empty())
        {
            cout << "Error: intentar hacer Peek en una pila vacía" << endl;
            return T{};
        }

        return data.front();
    }

    bool IsEmpty() const
    {
        return data.empty(); //devolvemos true si la pila está vacía
    }

    void Clear() //limpiamos la pila
    {
        data.clear();
        count = 0;
    }

};

void DemostracionLStack();

//https://cplusplus.com/reference/forward_list/forward_list/ 
//https://www.geeksforgeeks.org/cpp/forward_listbegin-forward_listend-c-stl/
//https://www.programiz.com/cpp-programming/forward-list