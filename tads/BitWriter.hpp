#ifndef _TARR_BITWRITER_
#define _TARR_BITWRITER_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "../funciones/strings.hpp"
#include "../funciones/files.hpp"

using namespace std;

struct BitWriter
{
   FILE* f;
   string buffer;
};

BitWriter bitWriter(FILE* f)
{
   return {f,""};
}

void bitWriterWrite(BitWriter& bw,int bit)
{ 
   bw.buffer+=intToChar(bit); //acumulo los bits en una string
   if(length(bw.buffer)==8) //una vez q tengo un byte
   {
      char c = 0;
      for(int i=0; i<8; i++) //convierto el byte que tengo en la string a un caracter equivalente
      {
         int caracter = charToInt(bw.buffer[7-i]);
         c += caracter*(int)pow(2,i); //convierto el byte a decimal y lo igualo a un caracter
      }
      //escribo el caracter en el archivo
      write<char>(bw.f,c);
      //vacio la string buffer
      bw.buffer="";
   }
}

void bitWriterWrite(BitWriter& bw,string bits)
{
   bw.buffer+=bits;
   if (length(bw.buffer)==8) //si tiene 8 caracteres el buffer los escribo en el archivo
   {
      char c = 0;
      for(int i=0; i<8; i++) //convierto el byte que tengo en la string a un caracter equivalente
      {
         int caracter = charToInt(bw.buffer[7-i]);
         c += caracter*(int)pow(2,i); //convierto el byte a decimal y lo igualo a un caracter
      }
      //escribo el caracter en el archivo
      write<char>(bw.f,c);
      //vacio la string buffer
      bw.buffer="";
   }

   if(length(bw.buffer)>8) //si tiene mas de 8, funcion recursiva escribiendo 8 bits hasta que me
   //quede el buffer con menos de 8
   {
      while(length(bw.buffer)>=8)
      {
         char c = 0;
         for(int i=0; i<8; i++) //convierto el byte que tengo en la string a un caracter equivalente
         {
            int caracter = charToInt(bw.buffer[7-i]);
            c += caracter*(int)pow(2,i); //convierto el byte a decimal y lo igualo a un caracter
            bw.buffer=removeAt(bw.buffer,0); //voy borrando los bits q ya procese
         }
         //escribo el caracter en el archivo
         write<char>(bw.f,c);
      }
   }

}

//void bitWriterFlush(BitWriter& bw)
//{
//}

#endif
