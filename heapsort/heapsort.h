/******************************************************************/
/* heapsort.h                                                     */
/******************************************************************/

#include "globals.h"

typedef char byte;

extern void heapsort(byte data[], int n, int elementsize, int (*p_cmp_f)());

extern void siftup(byte data[], int element, int elementsize, int (*p_cmp_f)());

extern void siftdown(byte data[], int n, int elementsize, int (*p_cmp_f)());

extern void memswap( byte *to, byte *from, int count );
