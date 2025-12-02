using namespace std;
#include <iostream>
#include "HashTableProbing.h"

void DemomostracionHashTableProbing()
{
    //creamos la tabla con una capacidad de 5
    HashTableLinear<int> valores(5);

    //colocacion de los valores a nuestra tabla
    valores.Insert(10, 10);  //insercion limpia y sin colision  
    valores.Insert(15, 15);  //nuestra primera colision y como esta ocupado por el 10 se movera a la derecha
    valores.Insert(20, 20);  //colision doble pasa lo mismo con el anterior caso pero se movera el doble por el 10 y 15 se movera a la derecha dos veces
    valores.Insert(7, 7);    //la colision intermedia este deberia de estar en el indice 2 pero ya esta ocupado asi que saltara al indice 3 que se encuentra vacio

    cout << "Tabla final:" << endl;
    valores.Print();
}
  