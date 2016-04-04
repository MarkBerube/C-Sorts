/******************************************************************/
/* quicksort.h                                                    */
/*                                                                */
/* Programmer: Mark Berube                                        */
/******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef char byte ;

extern byte *select_pivot( byte data[], int n, int elementsize, int (*p_cmp_f)( ) ) ;

extern void memswap( byte *s, byte *t, int count ) ;

extern void quicksort( byte data[], int n, int elementsize, int (*p_cmp_f)( ) ) ;
