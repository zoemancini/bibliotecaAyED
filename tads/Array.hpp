#ifndef _TARR_TAD_
#define _TARR_TAD_

#include <iostream>
#include <stdlib.h>
#include "../funciones/arrays.hpp"

using namespace std;

template<typename T>
struct Array
{
   T* arr;
   int len;
   int cap;
};

template<typename T>
Array<T> arrayCreate()
{
   Array<T> ret;
   ret.cap=100;
   ret.len=0;
   ret.arr = new T[ret.cap];
   return ret;
}

template<typename T>
int arrayAdd(Array<T>& a,T t)
{
   if (a.len==a.cap)
   {
      //redimensiono el array duplicando su capacidad
      T* b = new T[2*a.cap];
      for(int i=0; i<a.cap; i++)
      {
         b[i]=a.arr[i];
      }
      delete a.arr;
      a.arr=b;
      a.cap=a.cap*2;      
   }
   return add<T>(a.arr,a.len,t);
}

template<typename T>
T* arrayGet(Array<T> a,int p)
{
   return (a.arr+p);
}

template<typename T>
void arraySet(Array<T>& a,int p,T t)
{
   a.arr[p] = t;
}

template<typename T>
void arrayInsert(Array<T>& a,T t,int p)
{
   if (a.len==a.cap)
   {
      //redimensiono el array duplicando su capacidad
      T* b = new T[2*a.cap];
      for(int i=0; i<a.cap; i++)
      {
         b[i]=a.arr[i];
      }
      delete a.arr;
      a.arr=b;
      a.cap=a.cap*2;      
   }
   insert<T>(a.arr,a.len,t,p);
}

template<typename T>
int arraySize(Array<T> a)
{
   return a.len;
}

template<typename T>
T arrayRemove(Array<T>& a,int p)
{
   return (remove<T>(a.arr,a.len,p));
}

template<typename T>
void arrayRemoveAll(Array<T>& a)
{
   a.len=0;
}

template<typename T,typename K>
int arrayFind(Array<T> a,K k,int cmpTK(T,K))
{
   return find<T,K>(a.arr,a.len,k,cmpTK);
}

template<typename T>
int arrayOrderedInsert(Array<T>& a,T t,int cmpTT(T,T))
{
   if (a.len==a.cap)
   {
      //redimensiono el array duplicando su capacidad
      T* b = new T[2*a.cap];
      for(int i=0; i<a.cap; i++)
      {
         b[i]=a.arr[i];
      }
      delete a.arr;
      a.arr=b;
      a.cap=a.cap*2;      
   }
   return orderedInsert<T>(a.arr,a.len,t,cmpTT);
}

template<typename T>
T* arrayDiscover(Array<T>& a,T t,int cmpTT(T,T))
{
   int pos = find<T>(a.arr,a.len,t,cmpTT);
   if(pos<0)
   {
      pos = arrayAdd<T>(a,t);
   }
   return arrayGet(a,pos);
}


template<typename T>
void arraySort(Array<T>& a,int cmpTT(T,T))
{
   sort<T>(a.arr,a.len,cmpTT);
}

#endif
