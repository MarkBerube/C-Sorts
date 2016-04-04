/******************************************************************/
/* quicksort.c                                                    */
/*                                                                */
/* Programmer: Mark Berube                                        */
/******************************************************************/

#include "quicksort.h"

byte *select_pivot( byte data[], int n, int elementsize, int (*p_cmp_f)( ) ) {

  return data ;

}

void memswap( byte *s, byte *t, int count ) {

  byte tmp ;

  while( count-- > 0 ) {
    tmp = *s ;
    *s++ = *t ;
    *t++ = tmp ;
  }

}

void quicksort( byte data[], int n, int elementsize, int (*p_cmp_f)( ) ) {

  byte *p_left, *p_right, *p_pivot ;

  int leftsize ;

  if(n <= 1 ) return ;

  p_left = data ;

  p_right = data + ( n - 1 ) * elementsize ;

  p_pivot = select_pivot( data, n, elementsize, p_cmp_f ) ;

  memswap( p_pivot, p_right, elementsize ) ;

  p_pivot = p_right ;

  while( p_left < p_right ) {

    while( (*p_cmp_f)( p_left, p_pivot ) < 0 && p_left < p_right ) p_left += elementsize ;

    while( (*p_cmp_f)( p_right, p_pivot ) >= 0 && p_left < p_right ) p_right -= elementsize ;

    if( p_left < p_right ) {

      memswap( p_left, p_right, elementsize ) ;

      p_left += elementsize ;

    }

  }

  if( p_right == data ) {

    memswap( p_right, p_pivot, elementsize ) ;

    p_right += elementsize ;

  }

  leftsize = ( p_right - data ) / elementsize ;

  quicksort( data, leftsize, elementsize, p_cmp_f ) ;

  quicksort( p_right, n-leftsize, elementsize, p_cmp_f ) ;

}



