#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

int tokenCount(string s,char sep)
{
   if(length(s)==0)
   {
      return 0;
   }
   else
   {
      return charCount(s,sep)+1;
   }
}

void addToken(string& s,char sep,string t)
{
   if(tokenCount(s,sep)==0)
   {
      s=t;
   }
   else
   {
      s+=sep+t;
   }
}

string getTokenAt(string s,char sep, int i)
{
   int d=(i==0)?0:indexOfN(s,sep,i)+1;
   int h=(i==tokenCount(s,sep)-1)?length(s):indexOfN(s,sep,i+1);
   return substring(s,d,h);
}

void removeTokenAt(string& s,char sep, int i)
{
   string ret="";
   string ns="";
   int n=tokenCount(s,sep);
   for(int k=0; k<n; k++)
   {
      string tk = getTokenAt(s,sep,k);

      if( k!=i )
      {
         addToken(ns,sep,tk);
      }
      else
      {
         ret=tk;
      }
   }

   s=ns;
}

void setTokenAt(string& s,char sep, string t,int i)
{
   string ret="";
   string ns="";
   int n=tokenCount(s,sep);
   for(int x=0; x<n; x++)
   {

      if( x!=i )
      {
         string tk = getTokenAt(s,sep,x);
         addToken(ns,sep,tk);
      }
      else
      {
         addToken(ns,sep,t);
      }
   }

   s=ns;
}

int findToken(string s,char sep, string t)
{
   int n=tokenCount(s,sep);
   for(int i=0;i<n;i++)
   {
      if( t==getTokenAt(s,sep,i) )
      {
         return i;
      }
   }

   return -1;
}

#endif
