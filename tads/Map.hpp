#ifndef _TMAP_TAD_
#define _TMAP_TAD_

#include <iostream>
#include "Array.hpp"

using namespace std;

template<typename K,typename V>
struct Map
{
   Array<K> keys;
   Array<V> values;
   int i; //apunta al current del array keys
   int j; //apunta al current del array values
};

template<typename K,typename V>
Map<K,V> map()
{
   Map<K,V> m;
   m.keys = arrayCreate<K>();
   m.values = arrayCreate<V>();
   m.i=0;
   m.j=0;
   return m;
}

template<typename K,typename V>
V* mapGet(Map<K,V> m,K k)
{
   V* ret = NULL;

   for(int i=0;i<arraySize<K>(m.keys);i++)
   {
      if(k==*arrayGet<K>(m.keys,i))
      {
         ret = arrayGet<V>(m.values,i);
         i=arraySize<K>(m.keys);
      }
   }
   return ret;
}

template<typename K,typename V>
V* mapPut(Map<K,V>& m,K k,V v)
{
   V* ret = mapGet<K,V>(m,k);
   if (ret == NULL)
   {
      arrayAdd<V>(m.values,v);
      int pos = arrayAdd<K>(m.keys,k);
      ret = arrayGet<V>(m.values,pos);
      m.i++;
      m.j++;
   }
   else
   {
      *ret=v;
   }
   return ret;
}

template<typename K,typename V>
bool mapContains(Map<K,V> m,K k)
{
   int i=0;
   int pos=-1;
   while(m.keys.len>i && pos==-1)
   {
      if(k==*(arrayGet<K>(m.keys,i)))
      {
         pos=i;
      }
      i++;
   }
   return pos>=0;
}

template<typename K,typename V> //preguntar si tmb remueve la key
V mapRemove(Map<K,V>& m,K k)
{
   int i=0;
   int pos=-1;
   while(i<m.keys.len && pos==-1)
   {
      if(k==*(arrayGet<K>(m.keys,i)))
      {
         pos = i;
      }
      i++;
   }
   arrayRemove<K>(m.keys,pos);
   V ret = arrayRemove<V>(m.values,pos);
   m.i--;
   m.j--;
   return ret;
}

template<typename K,typename V>
void mapRemoveAll(Map<K,V>& m)
{
   m.keys.len=0;
   m.values.len=0;
   m.i=0;
   m.j=0;
}

template<typename K,typename V>
int mapSize(Map<K,V> m)
{
   return m.keys.len;
}

template<typename K,typename V>
bool mapHasNext(Map<K,V> m)
{
   bool ret = false;
   if(mapSize<K,V>(m)>m.i && mapSize<K,V>(m)>m.j)
   {
      ret=true;
   }
   return ret;
}

template<typename K,typename V>
K mapNextKey(Map<K,V>& m)
{
   K ret = *(arrayGet(m.keys,m.i));
   m.i++;
   return ret;
}

template<typename K,typename V>
V* mapNextValue(Map<K,V>& m) //mutualmente excluyente???????
{
   V* ret = arrayGet(m.values,m.j);
   m.j++;
   return ret;
}

template<typename K,typename V>
void mapReset(Map<K,V>& m)
{
   m.i=0;
   m.j=0;
}

template<typename K,typename V>
V* mapDiscover(Map<K,V>& m,K k,V v)
{
   V* ret;
   if(!mapContains<K,V>(m,k))
   {
      ret = mapPut<K,V>(m,k,v);
   }
   else
   {
      ret = mapGet<K,V>(m,k);
   }
   return ret;
}


template<typename K,typename V>
void mapSortByKeys(Map<K,V>& m,int cmpKK(K,K))
{
   Array<K> keysOrdenadas = arrayCreate<K>(); //array para copiar las keys y ordenarlas
   keysOrdenadas=m.keys;
   arraySort<K>(keysOrdenadas,cmpKK);

   Array<V> valuesOrdenados = arrayCreate<V>();
   for (int i=0;i<arraySize<K>(m.keys);i++)
   {
      K keyOrdered = arrayGet<K>(keysOrdenadas,i);
      V valueOrdered = mapGet<K,V>(m,keyOrdered);
      arraySet<V>(valuesOrdenados,i,valueOrdered);
   }

   m.keys=keysOrdenadas;
   m.values=valuesOrdenados;
}

template<typename K,typename V>
void mapSortByValues(Map<K,V>& m,int cmpVV(V,V))
{
   Array<K> aux = arrayCreate<K>(); //array para copiar las keys y ordenarlas con criterio de values

   mapReset<K,V>(m); //reseteo el map para poder iterar
   K key = mapNextKey<K,V>(m); //tomo la primer key
   arrayAdd<K>(aux,key); //agrego la primer key al array auxiliar
   while(mapHasNext<K,V>(m))//ordeno las keys en un array auxiliar
   {
      key = mapNextKey<K,V>(m);//tomo la siguiente key
      V value = *mapGet<K,V>(m,key); //tomo el value correspondiente a la sig key

      int i = 0;
      while(i<arraySize<K>(aux) && cmpVV(value, *mapGet<K,V>(m,*arrayGet<K>(aux,i))) <= 0)/*mientras el value de la
       siguiente key sea menor, sigo iterando*/
      {
         i++;
      }
      arrayInsert<K>(aux,i,key);
   }

   Array<V> valuesOrdenados = arrayCreate<V>();
   for (int i=0;i<arraySize<K>(m.keys);i++)
   {
      K keyOrdered = *arrayGet<K>(aux,i);
      V valueOrdered = *mapGet<K,V>(m,keyOrdered);
      arraySet<V>(valuesOrdenados,i,valueOrdered);
   }

   m.keys=aux;
   m.values=valuesOrdenados;
}

#endif
