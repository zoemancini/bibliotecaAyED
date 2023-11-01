#ifndef _TLIST_T_
#define _TLIST_T_

#include <iostream>
#include <stdio.h>

template <typename T>
struct Node
{
   T info;
   Node<T>* sig;
};

/*Agrega el elemento e al final de la lista direccionada por p. Retorna la direccion del nodo que contiene al elemento
que se agrego*/
template <typename T>
Node<T>* add(Node<T>*& p,T e)
{
   //creo un nuevo nodo
   Node<T>* nuevo = new Node<T>();
   nuevo->info = e;
   nuevo->sig = NULL;

   //si la lista existe lo agrego al final
   if(p!=NULL)
   {
      //recorro hasta el ultimo nodo
      Node<T>* aux = p;
      while(aux->sig!=NULL)
      {
         aux = aux->sig;
      }
      aux->sig = nuevo;
   }
   else //si no existe nuevo es el primer nodo de la lista
   {
      p = nuevo;
   }
   return nuevo;
}

/*Agrega el elemento e al inicio de la lista direccionada por p. Retorna la direccion del nodo que contiene al elemento
que se agrego*/
template <typename T>
Node<T>* addFirst(Node<T>*& p,T e)
{
   //creo un nuevo nodo
   Node<T>* nuevo = new Node<T>();
   nuevo->info = e;
   nuevo->sig = p;

   p = nuevo;
   return p;
}

/*Remueve la primera ocurrencia del elemento concordante con cmpTK. Retorna el valor del elemento que fue removido*/
template <typename T, typename K>
T remove(Node<T>*& p,K k,int cmpTK(T,K))
{
   Node<T>* aux = p; //nodo auxiliar para recorrer
   Node<T>* ant = NULL; // nodo que apunta al anterior del auxiliar
   while(aux!=NULL && cmpTK(aux->info,k)!=0) //recorro la lista hasta encontrar el elemento guardando el nodo anterior
   {
      ant = aux;
      aux = aux->sig;
   }

   if(ant==NULL) //si removi el primer elemento, hago que p apunte al sig del aux
   {
      p=aux->sig;
   }
   else //si el que removi no es el primero, hago que el anterior apunte al sig del aux
   {
      ant->sig = aux->sig;
   }

   T ret = aux->info; //extraigo la info del elemento que removi de la lista para poder retornarla
   delete aux; //boro el nodo direccionado por aux

   return ret;
}

/*Remueve el primer elemento de la lista direccionada por p. Retorna el valor del elemento que acabamos de remover*/
template <typename T>
T removeFirst(Node<T>*& p)
{
   Node<T>* aux = p->sig; //creo un nodo auxiliar apuntando al segundo elemento de la lista
   T ret = p->info; //extraigo la info del primer elemento de la lista para poder retornarla
   p = aux; // hago que p apunte al segundo nodo de la lista

   delete aux; //elimino aux

   return ret;
}

/*Retorna la direccion del nodo que contiene la primera ocurrencia de k, segun cmpTK, o NULL si ningun elemento
concuerda con dicha clave de busqueda.*/
template <typename T, typename K>
Node<T>* find(Node<T>* p,K k,int cmpTK(T,K))
{
   Node<T>* aux = p; //nodo auxiliar para recorrer
   while(aux!=NULL && cmpTK(aux->info,k)!=0) //recorro la lista hasta encontrar el elemento guardando el nodo anterior
   {
      aux = aux->sig;
   }
   return aux;
}

/*Inserta el elemento e en la lista direccionada por p segun el criterio que establece la funcion cmpTT.
La lista debe estar vacia u ordenada segun cmpTT. Retorna la direccion del nodo que acabamos de insertar.*/
template <typename T>
Node<T>* orderedInsert(Node<T>*& p,T e,int cmpTT(T,T))
{
   Node<T>* nuevo = new Node<T>(); //creo el nodo para poder insertarlo en la lista
   nuevo->info = e;

   Node<T>* ant = NULL; //nodo que apunta al anterior de aux
   Node<T>* aux = p; //nodo para recorrer la lista

   while(aux!=NULL && cmpTT(aux->info,e)<0) //seguimos iterando mientras encontremos elementos menores que v
   {
      ant = aux;
      aux = aux->sig;
   }

   if(ant==NULL) //si tenemos que insertar al principio de la lista
   {
      nuevo->sig = p; //hacemos que el sig del nodo que vamos a insertar sea p
      p = nuevo; //luego p pasa a direccionar al nodo que insertamos
   }
   else
   {
      ant->sig = nuevo; //hacemos que el nodo anterior apunte al que queremos insertar
      if(aux==NULL) //si tenemos que insertar al final de la lista
      {
         nuevo->sig = NULL; //hacemos que el nodo que queremos insertar apunte a NULL
      }
      else
      {
         nuevo->sig=aux; //hacemos que el nodo que queremos insertar apunte a aux
      }
   }
   return nuevo;
}

/*Busca en la lista direccionada por p la primera ocurrencia de e, y retorna la direccion del nodo que lo contiene.
Si e no existe en la lista entonces lo inserta en orden, segun el criterio establecido por cmpTT, y retorna la direccion
del nodo insertado. Asigna true o false a enc segun e fue encontrado o insertado.*/
template <typename T>
Node<T>* searchAndInsert(Node<T>*& p,T e,bool& enc,int cmpTT(T,T))
{
   Node<T>* aux = p; //nodo para recorrer a la lista
   e = (cmpTT(aux->info,e)==0); //indica si enuentra o no el elemento e
   while(aux!=NULL && e==false) //recorro la lista hasta encontrar el elemento e o llegar al final de la lista
   {
      aux = aux->sig;
   }

   if(aux==NULL && e==false) //si llego al final de la lista y no lo encontro, lo inserto ordenado
   {
      aux = orderedInsert<T>(p,e,cmpTT);
   }

   return aux;
}

/*Ordena la lista direccionada por p segun el criterio que establece la funcion de comparacion cmpTT*/
template <typename T>
void sort(Node<T>*& p,int cmpTT(T,T))
{
   Node<T>* aux = p; //nodo para recorrer la lista
   Node<T>* ordenados = NULL;
   while(aux->sig!=NULL)
   {
      orderedInsert<T>(ordenados,aux->info,cmpTT);
      aux = aux->sig;
   }
   p = ordenados;
}

/*Indica si la lista direccionada por p tiene o no elementos*/
template <typename T>
bool isEmpty(Node<T>* p)
{
   return p==NULL;
}

/*Libera la memoria que utiliza la lista direccionada por p. Asigna NULL a p.*/
template <typename T>
void free(Node<T>*& p)
{
   Node<T>* aux;
   while(p!=NULL)
   {
      aux = p->sig;
      delete p;
      p = aux;
   }
}

/*Inserta un nodo conteniendo a e al inicio de la lista direccionada por p. Retorna la direccion del nodo que contiene
al elemento que se agrego.*/
template <typename T>
Node<T>* push(Node<T>*& p,T e)
{
   return addFirst<T>(p,e);
}

/*Remueve el primer nodo de la lista direccionada por p. Retorna el elemento que contenia el nodo que fue removido.*/
template <typename T> T pop(Node<T>*& p)
{
   return removeFirst<T>(p);
}

/*Agrega el elemento e al final de la lista direccionada por q. Retorna la direccion del nodo que contiene al elemento 
que se agrego*/
template <typename T>
Node<T>* enqueue(Node<T>*& p,Node<T>*& q,T e)
{
   if(p!=NULL)
   {
      q = add<T>(q,e);
   }
   else
   {
      q = add<T>(p,e);
   }
   return q;
}

/*Agrega el elemento e al final de la lista circular direccionada por q. Retorna la direccion del nodo que contiene
al elemento que se agrego*/
template <typename T>
Node<T>* enqueue(Node<T>*& q,T e)
{
   Node<T>* nuevo = new Node<T>(); //creo el nodo que quiero agregar
   nuevo->info = e;

   if(q!=NULL) //si la lista tiene elementos
   {
      nuevo->sig = q->sig;
      q->sig = nuevo;
   }
   else
   {
      nuevo->sig = nuevo;
   }

   q=nuevo;
   return nuevo;
}

/*Remueve el primer nodo de la lista direccionada por p. Retorna el elemento que contenia el nodo que fue removido*/
template <typename T>
T dequeue(Node<T>*& p, Node<T>*& q)
{
   return removeFirst<T>(p);
}

/*Remueve el primer nodo de la lista circular direccionada por q. Retorna el elemento que contenia el nodo que fue
removido */
template <typename T>
T dequeue(Node<T>*& q)
{
   Node<T>* aux = q->sig;
   q->sig = aux->sig;
   T ret = aux->info;

   if(aux==q)
   {
      q=NULL;
   }
   
   delete aux;
   return ret;
}

#endif
