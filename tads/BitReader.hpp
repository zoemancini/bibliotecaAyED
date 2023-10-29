#ifndef _TARR_BITREADER_
#define _TARR_BITREADER_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "../funciones/strings.hpp"
#include "../funciones/files.hpp"

using namespace std;

struct BitReader
{
   FILE* f;
   string buffer;
};

BitReader bitReader(FILE* f)
{
   return {f,""};
}

int bitReaderRead(BitReader& br)
{
   return 0;
}

#endif
