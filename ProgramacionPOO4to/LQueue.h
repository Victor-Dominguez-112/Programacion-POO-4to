#pragma once
#include "SentinelLinkedList.h"
#include <iostream>
using namespace std;

template <typename T>
class LQueue
{
private:
    SentinelLinkedList<T> data;

public:
    LQueue(){}

    int GetCount() { return data.GetCount(); }

    void Enqueue(T value);

    T Dequeue();

    T Front() { return data.Front(); }
};

// IMPLEMENTACIONES DE LAS FUNCIONES RESTANTES

// Enqueue agrega un elemento al final de la cola 
template <typename T>
void LQueue<T>::Enqueue(T value) 
{
    data.Append(value); //O(1): agregara al final del nodo
}

// Dequeue eliminara el primer elemento de la cola
template <typename T>
T LQueue<T>::Dequeue()
{
    return data.PopFront(); //O(1): quitara el primer nodo
}

void DemostracionLQueue();