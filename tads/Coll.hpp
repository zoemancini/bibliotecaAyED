#ifndef _TCOLL_T_
#define _TCOLL_T_

#include <iostream>
#include "../funciones/strings.hpp"

using namespace std;

template<typename T>
struct Coll
{
   string s;
   char sep;
   int curr;
};

template<typename T>
Coll<T> coll(char sep)
{
   Coll<T> c;
   c.s = "";
   c.sep=sep;
   c.curr = 0;
   return c;}

template<typename T>
Coll<T> coll()
{
   return coll<T>('|');
}

template<typename T>
int collSize(Coll<T> c)
{
   return tokenCount(c.s,c.sep);
}

template<typename T>
void collRemoveAll(Coll<T>& c)
{
   c.s="";
   c.curr=0;
}

template<typename T>
void collRemoveAt(Coll<T>& c, int p)
{
   removeTokenAt(c.s,c.sep,p);
}

template<typename T>
int collAdd(Coll<T>& c,T t,string tToString(T))
{
   addToken(c.s,c.sep,tToString(t));
   return tokenCount(c.s,c.sep)-1;
}

template <typename T>
void collSetAt(Coll<T>& c,T t,int p,string tToString(T))
{
   string sI = tToString(t);
   setTokenAt(c.s,c.sep,sI,p);
}

template <typename T>
T collGetAt(Coll<T> c,int p,T tFromString(string))
{
   return tFromString(getTokenAt(c.s,c.sep,p));
}





template <typename T, typename K>
int collFind(Coll<T> c,K k,int cmpTK(T,K),T tFromString(string))
{
   int i=0;
   bool existe = false;
   while( i<collSize<T>(c) && !existe )
   {
      T t = collGetAt<T>(c,i,tFromString);
      if( cmpTK(t,k)==0 )
      {
         existe = true;
      }

      i++;
   }

   return existe?i-1:-1;

//   int ret;
//   if( existe )
//   {
//      ret = i-1;
//   }
//   else
//   {
//      ret = -1;
//   }
//
//   return ret;
}





















template <typename T>
void collSort(Coll<T>& c,int cmpTT(T,T),T tFromString(string),string tToString(T))
{
   Coll<T> cAux = coll<T>();

   while( collSize(c)>0 )
   {
      // busco el menor
      T tMin = collGetAt<T>(c,0,tFromString);
      int pMin = 0;
      for(int i=1; i<collSize<T>(c); i++)
      {
         T t1 = collGetAt<T>(c,i,tFromString);
         int cmp = cmpTT(t1,tMin);
         tMin = cmp<=0?t1:tMin;
         pMin = cmp<=0?i:pMin;
      }

      // remuevo el mimono
      collRemoveAt<T>(c,pMin);

      // agrego a aux
      collAdd<T>(cAux,tMin,tToString);
   }

   c = cAux;
}

template<typename T>
bool collHasNext(Coll<T> c)
{
   return c.curr<collSize(c);
}

template<typename T>
T collNext(Coll<T>& c,T tFromString(string))
{
   return collGetAt<T>(c,c.curr++,tFromString);
}

template<typename T>
T collNext(Coll<T>& c,bool& endOfColl,T tFromString(string))
{
   endOfColl = !collHasNext<T>(c);
   if( endOfColl )
   {
      return {};
   }
   else
   {
      return collGetAt<T>(c,c.curr++,tFromString);
   }
}

template<typename T>
void collReset(Coll<T>& c)
{
   c.curr=0;
}

template<typename T>
string collToString(Coll<T> c)
{
   return c.sep+c.s;
}

template<typename T>
Coll<T> collFromString(string s)
{
   Coll<T> c;
   c.sep=s[0];
   c.s=substring(s,1);
   return c;
}


#endif
