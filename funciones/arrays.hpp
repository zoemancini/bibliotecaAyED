#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>

//Agrega el elemento e al final de arr incrementando su longitud len. Retorna la posicion del array donde quedo eubicado el elemento e.
template <typename T>
int add(T arr[],int& len,T e)
{
    arr[len]=e;
    len++;
    int copylen = len;
    return copylen-1;
}

//Inserta el elemento e en la posicion p del arr. Desplaza los elementos ubicados a partir de p+1 e incrementa la longitud len.
template <typename T>
void insert(T arr[],int& len,T e,int p)
{
    for(int i=len; i>p;len--)
    {
        arr[i]=arr[i-1];
    }
    arr[p]=e;
    len++;
}

/*Remueve el elemento ubicado en la posicion p del array arr. Desplaza los elementos ubicados a partir de p y decrementa la longitud len. Devuelve
el elemento que fue removido del array. */
template <typename T>
T remove(T arr[],int& len,int p)
{
   T ret=arr[p];
   for(int i=p;p<len;p++)
   {
    arr[p]=arr[p+1];
   }
   len--;
   return ret;
}

/*Retorna la posicion de la primera ocurrencia de k dentro del array arr o un valor negativo si arr no contiene a k*/
template <typename T, typename K>
int find(T arr[],int len,K k,int cmpTK(T,K))
{
    int ret=-1;
    int i=0;
    while(i<len || ret==-1)
    {
        if(cmpTK(arr[i],k)==0)
        {
            ret=i;
        }
        i++;
    }
   return ret;
}

/*Inserta e dentro de arr segun el criterio de precedencia que establece cmpTT, y retorna la posicion donde dicho elemento quedo insertado.
El array arr debe estar ordenado o vacio.*/
template <typename T>
int orderedInsert(T arr[],int& len,T e,int cmpTT(T,T))
{
    int i=0;
    while(cmpTT(arr[i],e)<0 && i<len)
    {
        i++;
    }
    insert<T>(arr,len,e,i);
    return i;
}

/*Ordena arr segun el criterio de precedencia que establece cmpTT*/
template <typename T>
void sort(T arr[],int len,int cmpTT(T,T))
{
    T aux[len];
    int i=0;
    while(i<len) //los ordeno en un array auxiliar
    {
        orderedInsert<T>(aux,len,arr[i],cmpTT);
        i++;
    }
    for(int j=0;j<len;j++) //copio el array ordenado al original
    {
        arr[j]=aux[j];
    }
}



#endif
