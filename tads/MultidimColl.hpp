#ifndef _TMTX_T_
#define _TMTX_T_

#include <iostream>
#include "Coll.hpp"

using namespace std;

template<typename T>
struct Mtx
{
   Coll<T> datos;
   int f;
   int c;
};

template <typename T>
Mtx<T> mtx(int f,int c,T valorDefault,string tToString(T))
{
   Mtx<T> m;
   m.c = c;
   m.f = f;

   m.datos = coll<T>();
   int x = c*f;
   for(int i=0;i<x;i++)
   {
      collAdd<T>(m.datos,valorDefault,tToString);
   }

   return m;
}

template <typename T>
int coordenadasToInt(Mtx<T> m,int f,int c)
{
   return f*m.c+c;
}

template <typename T>
T mtxGetAt(Mtx<T> m,int f,int c,T tFromString(string))
{
   int n = coordenadasToInt<T>(m,f,c);
   return collGetAt<T>(m.datos,n,tFromString);
}

template <typename T>
void mtxSetAt(Mtx<T>& m,T t,int f,int c,string tToString(T))
{
   int n = coordenadasToInt<T>(m,f,c);
   collSetAt<T>(m.datos,t,n,tToString);
}

// ------------------------

template<typename T>
struct Cube
{
   Coll<T> datos;
   int f;
   int c;
   int p;
};

template <typename T>
Cube<T> cube(int f,int c,int p,T valorDefault,string tToString(T))
{
   Cube<T> m = {coll<T>(),f,c,p};
   int x = c*f*p;
   for(int i=0;i<x;i++)
   {
      collAdd<T>(m.datos,valorDefault,tToString);
   }

   return m;
}

template <typename T>
int coordenadasToInt(Cube<T> cu,int f,int c,int p)
{
   return p*cu.f*cu.c+f*cu.c+c;
}

template <typename T>
T cubeGetAt(Cube<T> cu,int f,int c,int p,T tFromString(string))
{
   int n = coordenadasToInt<T>(cu,f,c,p);
   return collGetAt<T>(cu.datos,n,tFromString);
}

template <typename T>
void cubeSetAt(Cube<T>& cu,T t,int f,int c,int p,string tToString(T))
{
   int n = coordenadasToInt<T>(cu,f,c,p);
   collSetAt<T>(cu.datos,t,n,tToString);
}

#endif
