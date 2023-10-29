#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int length(string s)
{
   int i = 0;
   while (s[i] != '\0')
   {
      i ++;
   }
   return i;
}

int charCount(string s,char c)
{
   int i = 0;
   int contador=0;
   while (s[i] != '\0')
   {
      if (s[i] == c)
      {
         contador++;
      }
      i++;
   }
   return contador;
}

string substring(string s,int d,int h)
{
   int i = d;
   string aux = "";
   while (i < h)
   {
      aux = aux + s[i];
      i++;
   }
   return aux;
}

string substring(string s,int d) // ok
{
   int i = d;
   string aux = "";
   while (s[i] != '\0')
   {
      aux = aux + s[i];
      i++;
   }
   return aux;
}

int indexOf(string s,char c) // ok
{
   int i = 0;
   while(s[i] != c)
   {
      if (s[i] == '\0' )
      {
      i = -1;
      break;
      }
      else{
         i ++;
      }
   }
   return i;
}

int indexOf(string s,char c,int offset) // ok
{
   int i = offset;
   while(s[i] != c)
   {
      if (s[i] == '\0' )
      {
      i = -1;
      break;
      }
      else{
         i ++;
      }
   }
   return i;
}

int indexOf(string s,string toSearch) // ok
{
   int i = 0; //indice string s
   int j = 0; //indice string toSearch
   int aux = -1; //variable para guardar el indice
   while(s[i] != '\0') //recorre la string s
   {
      if (s[i] == toSearch[j]) //entra si la letra que esta recorriendo de s es igual a la primer letra de toSearch
      {
         aux = i; //guarda el indice de s que tenia cuando entro al if
         i++; //incrementa el i y el j porque ya verificamos que esas son iguales
         j++;
         while(toSearch[j] != '\0') //recorre toSearch hasta el final de la palabra
         {
            if (s[i] == toSearch[j]) //si las letras son iguales las vuelve a incrementar
            {
               i++;
               j++;
            }
            else // si no son iguales
            {
               aux = -1; //devuelve el indice guardado a -1
               j = 0; //devuelve el indice de toSearch a 0 para poder recorrerla nuevamente
               break;
            }
         }
      } else {
         i++;
      }
   }
   return aux;
}


int lastIndexOf(string s,char c)
{
   int i=0;
   int aux=-1;
   while (s[i]!='\0'){
      if (s[i]==c){
         aux=i;
         i++;
      } else {
         i++;
      }
   }
   return aux;
}

int indexOfN(string s, char c, int n)
{
   int i = 0;
   int contador = 0;
   int aux = -1;
   if( n!=0 )
   {
      while( contador!=n )
      {
         if( s[i]!='\0' )
         {
            if( s[i]==c )
            {
               aux = i;
               i++;
               contador++;
            }
            else
            {
               i++;
            }
         }
         else
         {
            aux = length(s);
            break;
         }
      }
   }
   return aux;
}

int charToInt(char c)
{
   int valor=c;
   if (c>='A' && c<='Z'){
      valor=valor-55;
   } else {
      if (c>='0' && c<='9'){
         valor=valor-48;
      } else {
         if ('a'<=c && c<='z'){
            valor=valor-87;
         }
      }
   }
   return valor;
}

char intToChar(int i)
{
   char x;
   if (i>=0 && i<=9){
      x=i+48;
   } else {
      if (i>=65 && i<=90){
         x=i;
      }
   }
   return x;
}

int poww(int x,int y)
{
   int p=1;
   for(int i=0;i<y;i++)
   {
      p*=x;
   }
   return p;
}

int getDigit(int n, int i)
{
   int j=0;
   int aux;
   int copia=n;
   while (j!=i+1){
      aux=copia%10; //guarda el resto
      copia=copia/10;//guarda el numero dividido
      j++;
   }
   return aux;
}

int digitCount(int n)
{
   int contador=0;
   int copia=n;
   while (copia!=0){
      contador++;
      copia=copia/10;
   }
   return contador;
}

string intToString(int i)
{
   string s="";
   int contador=digitCount(i);
   char aux;
   while(contador!=0){
      aux= getDigit(i,contador-1)+48;
      s=s+aux;
      contador--;
   }
   return s;
}

int stringToInt(string s, int b) // ok
{
   int i=length(s)-1;
   int j=0;
   int aux;
   int final=0;
   while (s[j]!='\0'){
      if (s[j]>='A' && s[j]<='Z'){
         aux=s[j]-55;
      } else {
         if (s[j]>='0' && s[j]<='9'){
            aux=s[j]-48;
         }
      }
      final=final+aux*pow(b,i);
      i--;
      j++;
   }
   return final;
}

int stringToInt(string s)
{
   int i=0;
   int aux;
   int final=0;
   while (s[i]!='\0'){
      aux=s[i]-48;
      final=final*10+aux;
      i++;
   }
   return final;
}

string charToString(char c)
{
   string s="";
   s=s+c;
   return s;
}

char stringToChar(string s)
{
   int i=0;
   char aux=s[i];
   return aux;
}

string stringToString(string s)
{
   string str=s;
   return str;
}

string doubleToString(double d)
{
   int ent=(int)d;
   string entera=intToString(ent);
   double coma = d-ent;
   string decimal="";
   double resto=0;
   int aux;
   int i=1;
   do{ 
      resto=coma*10;
      aux=(int)resto;
      coma=resto-aux;
      decimal=decimal+intToString(aux);
      resto=0;
      i++;
   }while (aux!=0 || i!=6);
   string final=entera+','+decimal;
   return final;
}

double stringToDouble(string s)
{
   int i=0;
   int entero=0;
   while(s[i]!=','){
      char a=s[i];
      entero=entero+ charToInt(a)*pow(10,i);
      i++;
   }
   double decimal=0;
   i++;
   int aux=-1;
   while(s[i]!='\0'){
      char b=s[i];
      decimal+=charToInt(b)*pow(10,aux);
      aux--;
      i++;
   }
   double ret=entero+decimal;
   return ret;
}

bool isEmpty(string s)
{
   int i=0;
   bool prueba = s[i]=='\0';
   return prueba;
}

bool startsWith(string s, string x)
{
   return indexOf(s,x)==0;
}

bool endsWith(string s, string x)
{
   return indexOf(s,x)==(length(s)-length(x));
}

bool contains(string s, char c)
{
   return indexOf(s,c)>=0;
}

string replace(string s, char oldChar, char newChar)
{
   int i=0;
   string ret="";
   while (s[i]!='\0'){
      if(s[i]==oldChar){
         ret+=newChar;
      }
      else {
         ret+=s[i];
      }
      i++;
   }
   return ret;
}

string insertAt(string s, int pos, char c)
{
   int i=0;
   string ret="";
   while (s[i]!='\0'){
      if (i==pos){
         ret+=c;
         ret+=s[i];
      }
      else {
         ret+=s[i];
      }
      i++;
   }
   return ret;
}

string removeAt(string s, int pos)
{
   int i=0;
   string ret="";
   while(s[i]!='\0'){
      if (i==pos){
         i++;
      }
      else{
         ret+=s[i];
         i++;
      }
   }
   return ret;
}

string ltrim(string s)
{
   int i=0;
   string ret=s;
   while(ret[i]==' '){
      ret=removeAt(ret,i);
   }
   return ret;
}

string rtrim(string s)
{
   string ret =s;
   int i=length(s)-1;
   while(ret[i]==' '){
      ret=removeAt(ret,i);
      i=length(ret)-1;
   }
   return ret;
}

string trim(string s)
{
   string ret=ltrim(s);
   ret=rtrim(ret);
   return ret;
}

string replicate(char c, int n)
{
   int i=0;
   string ret="";
   while(i<n){
      ret+=c;
      i++;
   }
   return ret;
}

string spaces(int n)
{
   return replicate(' ',n);
}

string lpad(string s, int n, char c)
{
   string ret=s;
   int i=length(ret);
   while (i<n){
      ret=insertAt(ret,0,c);
      i++;
   }
   return ret;
}

string rpad(string s, int n, char c)
{
   string ret=s;
   while (length(ret)<n){
      ret+=c;
   }
   return ret;
}

string cpad(string s, int n, char c)
{
   int i=length(s);
   string ret=s;
   while (i<n){
      if (i%2==0){
         ret=lpad(ret,i+1,c);
      }
      else {
         ret=rpad(ret,i+1,c);
      }
      i++;
   }

   return ret;
}

bool isDigit(char c)
{
   return c>='0' && c<='9';
}

bool isLetter(char c)
{
   return (c>='A' && c<='Z')||(c>='a' && c<='z');
}

bool isUpperCase(char c)
{
   return c>='A' && c<='Z';
}

bool isLowerCase(char c)
{
   return c>='a' && c<='z';
}

char toUpperCase(char c)
{
   char ret;
   if(isLowerCase(c)){
      ret=c-32;
   }
   else{
      ret=c;
   }
   return ret;
}

char toLowerCase(char c)
{
   char ret;
   if (isUpperCase(c)){
      ret=c+32;
   }
   else {
      ret=c;
   }
   return ret;
}

string toUpperCase(string s)
{
   int i=0;
   string ret="";
   while(s[i]!='\0'){
      char c=s[i];
      ret+=toUpperCase(c);
      i++;
   }
   return ret;
}

string toLowerCase(string s)
{
   int i=0;
   string ret="";
   while(s[i]!='\0'){
      char c=s[i];
      ret+=toLowerCase(c);
      i++;
   }
   return ret;
}

int cmpString(string a, string b)
{
   int ret=0;
   if (a<b){
      ret=-1;
   }
   else {
      if (a>b){
         ret=1;
      }
   }
   return ret;
}

int cmpDouble(double a, double b)
{
   int ret=0;
   if (a<b){
      ret=-1;
   }
   else {
      if (a>b){
         ret=1;
      }
   }
   return ret;
}

char* stringToCString(string s)
{
   char* ret = new char[length(s)+1];

   int i=0;
   while( s[i]!='\0' )
   {
      ret[i] = (char)s[i];
      i++;
   }

   ret[i] = '\0';
   return ret;
}

string cStringToString(char c[])
{
   return string(c);
}

#endif
