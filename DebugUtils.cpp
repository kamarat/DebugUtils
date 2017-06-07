#include "DebugUtils.h"

int freeRAM()
{
  int size = RAMEND;
  byte *buf;
  while ((buf = (byte *) malloc(--size)) == NULL);
  free(buf);
  return size;
}

