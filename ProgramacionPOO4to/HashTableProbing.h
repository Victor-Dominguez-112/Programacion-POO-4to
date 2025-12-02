#include <iostream>
using namespace std;

template <typename T>
class HashTableLinear
{
private:
    T* tabla;         //puntero para la creacion del arreglo
    int capacidad;    //tamaño de nuestra tabla
    int count;        //contador de los elementos que vamos a guardar

public:
    //nuestro constructor
    HashTableLinear(int size)
    {
        capacidad = size;
        count = 0;
        tabla = new T[capacidad]; //guardamos memoria para nuestro arreglo

        //aqui llenamos todo con valores que son por defecto 
        for (int i = 0; i < capacidad; i++)
            tabla[i] = T();
    }

    //nuestro destructor
    ~HashTableLinear()
    {
        delete[] tabla; //eliminamos la memoria 
    }

    //función hash es el encargado de la tabla 
    int Hash(int key)
    { 
        return key % capacidad; //convertimos una key a un índice de nuestro arreglo
    } //el operador % nos ayudara a que nuestro índice nunca se salga del rango de 0 a capacidad-1

    //inserción con el desplazamiento lineal
    bool Insert(int key, T valor)
    {
        if (count == capacidad) //verificamos si cabe 
        {
            cout << "ERROR: La tabla se encuentra llena y no se podra insertar: " << valor << endl;
            return false;
        }

        int indice = Hash(key); //calculamos la posicion ideal 

        //si la posicion esta vacia o con un valor por deefecto lo metemos ahi
        if (tabla[indice] == T())
        {
            tabla[indice] = valor;
            count++;
            return true;
        }

        //si tenemos una colision guardamos donde comanzamos para saber si si dimos toda la vuelta
        int indiceoriginal = indice;
        indice = (indice + 1) % capacidad; //nos movemos a la siguente posicion 
        //usaremos el % capacidad por si llegamos al final volvemos nuestro índice un 0
        while (indice != indiceoriginal) //miestras no regresemos al inicio o donde fue que empezamos
        {
            if (tabla[indice] == T()) //si tenemos o encontramos un hueco vacio
            {
                tabla[indice] = valor; //lo colocaremos aqui en este espacio
                count++;
                return true;
            }
            indice = (indice + 1) % capacidad; //si esta ocupado seguiremos al siguente 
        }
        //si terminamos el bucle y no encontramos algun lugar mostramos el errror
        cout << "ERROR: No se encontró un espacio" << endl;
        return false;
    }

    //funcion para la imprecion de los datos
    void Print()
    {
        for (int i = 0; i < capacidad; i++)
        {
            cout << "[" << i << "]: " << tabla[i] << endl;
        }
    }
};
  
void DemomostracionHashTableProbing();