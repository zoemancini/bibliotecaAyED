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

/*Graba un bit en el archivo*/
void bitWriterWrite(BitWriter& bw,int bit)
{ 
   bw.buffer+=intToString(bit); //acumulo los bits en una string
}

/*Graba en el archivo los unos y ceros que contiene bits*/
void bitWriterWrite(BitWriter& bw,string bits)
{
   bw.buffer+=bits;
}

void bitWriterFlush(BitWriter& bw)
{
   int len = length(bw.buffer);
   while(len % 8 != 0) //completo con ceros hasta tener un multiplo de 8 en el buffer
   {
      bw.buffer+='0';
      len++;
   }

   for(int i=0;i<len;i++) //escribo los bytes en el archivo
   {
      int aux = stringToInt(substring(bw.buffer,i,i+8),2);
      unsigned char upload = aux;
      write<unsigned char>(bw.f,upload);
   }
}

#endif
