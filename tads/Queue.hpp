#ifndef _TQUEUE_TAD_
#define _TQUEUE_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template<typename T>
struct Queue
{
   Node<T>* q;
   int size;
};

/*Crea una cola vacia y la retorna*/
template<typename T>
Queue<T> queue()
{
   Queue<T> q;
   return q;
}

/*Encola el elemento e. Retorna la direccion de memoria del elemento que se encolo*/
template<typename T>
T* queueEnqueue(Queue<T>& q,T e)
{
   Node<T>* ret = enqueue<T>(q.q,e);
   q.size++;
   return &(ret->info);
}

/*Desencola un elemento y retorna el elemento que se desencolo*/
template<typename T>
T queueDequeue(Queue<T>& q)
{
   Node<T>* ret = dequeue<T>(q.q);
   q.size--;
   return ret->info;
}

/*Retorna true o false segun la cola tenga elementos o no*/
template<typename T>
bool queueIsEmpty(Queue<T> q)
{
   return isEmpty<T>(q.q);
}

/*Retorna la cantidad de elementos que tiene la cola*/
template<typename T>
int queueSize(Queue<T> q)
{
   return q.size;
}

#endif
