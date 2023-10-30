#ifndef _TSTACK_TAD_
#define _TSTACK_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template<typename T>
struct Stack
{
   Node<T>* top;
   int size;
};

/*Crea una pila vacia y la retorna*/
template<typename T>
Stack<T> stack()
{
   Stack<T> st;
   st.top=NULL;
   st.size=0;
   return st;
}

/*Apila el elemento e y retorna la direccion de memoria del elemento que se apilo*/
template<typename T>
T* stackPush(Stack<T>& st,T e)
{
   Node<T>* ret = push<T>(st.top,e);
   st.size++;
   return &(ret->info);
}

/*Desapila un elemento y retorna el elemento que se desapilo*/
template<typename T>
T stackPop(Stack<T>& st)
{
   Node<T>* ret = pop<T>(st.top);
   return ret->info;
}

/*Retorna true o false segun la pila tenga elementos o no*/
template<typename T>
bool stackIsEmpty(Stack<T> st)
{
   return isEmpty<T>(st.top);
}

/*Retorna la cantidad de elementos que tiene la pila*/
template<typename T>
int stackSize(Stack<T> st)
{
   return st.size;
}

#endif
