#ifndef _TLIST_TAD_
#define _TLIST_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template<typename T>
struct List
{
   Node<T>* p;
   int size;
   Node<T>* aux;
};

/*Funcion de inicializacion*/
template<typename T>
List<T> list()
{
   List<T> lst;
   lst.p = NULL;
   lst.size=0;
   return lst;
}

/*Agrega un elemento al final de la lista. Retorna la direccion de memoria del elemento que se agrego*/
template<typename T>
T* listAdd(List<T>& lst,T e)
{
   lst.size++;
   return &(add<T>(lst.p,e)->info);
}

/*Agrega el elemento e al inicio de la lista. Retorna la direccion de memoria del elemento que se agrego*/
template<typename T>
T* listAddFirst(List<T>& lst,T e)
{
   lst.size++;
   return addFirst<T>(lst.p,e);
}

/*Remueve el elemento que concuerde con k segun la funcion cmpTK. Retorna el elemento que fue removido*/
template<typename T,typename K>
T listRemove(List<T>& lst,K k,int cmpTK(T,K))
{
   lst.size--;
   return remove<T>(lst.p,k,cmpTK);
}

/*Desenlaza y libera el primer nodo de la lista enlazada, retornando el valor del elemento que contenia*/
template<typename T>
T listRemoveFirst(List<T>& lst)
{
   lst.size--;
   return removeFirst<T>(lst.p);
}

/*Retorna la direccion del primer elemento concordante con k segun cmpTK*/
template<typename T,typename K>
T* listFind(List<T> lst,K k,int cmpTK(T,K))
{
   return find<T>(lst.p,k,cmpTK);
}

/*Indica si la lista esta vacia o tiene elementos*/
template<typename T>
bool listIsEmpty(List<T> lst)
{
   return lst.size==0;
}

/*Indica cuantos elementos tiene la lista*/
template<typename T>
int listSize(List<T> lst)
{
   return lst.size;
}

/*Libera la memoria que ocupa la lista*/
template<typename T>
void listFree(List<T>& lst)
{
   free<T>(lst.p);
}

/*Descubre el elemento t en la lista lst. Retorna la direccion del elemento encontrado o recientemente agregado
al final de la lista lst*/
template<typename T>
T* listDiscover(List<T>& lst,T t,int cmpTT(T,T))
{
   
   bool enc;
   T* ret = searchAndInsert<T>(lst.p,t,enc,cmpTT);
   if(enc==false)
   {
      lst.size++;
   }
   return ret;
}

/*Inserta un elemento segun el orden que establece cmpTT. La lista debe estar ordenada (segun cmpTT) o vacia.
Retorna la direccion del elemento insertado.*/
template<typename T>
T* listOrderedInsert(List<T>& lst,T t,int cmpTT(T,T))
{
   lst.size++;
   return orderedInsert<T>(lst.p,t,cmpTT);
}

/*Ordena la lista segun el criterio que establece cmpTT*/
template<typename T>
void listSort(List<T>& lst,int cmpTT(T,T))
{
   sort<T>(lst.p,cmpTT);
}

/*Prepara la lista para iterarla*/
template<typename T>
void listReset(List<T>& lst)
{
   lst.aux=lst.p;
}

/*Indica si quedan mas elementos para seguir iterando la lista*/
template<typename T>
bool listHasNext(List<T> lst)
{
   return lst.aux==NULL;
}

/*Retorna la direccion del siguiente elemento de la lista en la iteracion*/
template<typename T>
T* listNext(List<T>& lst)
{
   T* ret = &(lst.aux->info);
   lst.aux=lst.aux->sig;
   return ret;
}

/*Retorna la direccion del siguiente elemento de la lista en la iteracion*/
template<typename T>
T* listNext(List<T>& lst,bool& endOfList)
{
   lst.aux=lst.aux->sig;
   endOfList = !listHasNext<T>(lst);
   return &(lst.aux->info);
}

#endif
