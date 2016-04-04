/****************************************************************************/
/* Programmer: Mark Berube                                                  */ 
/*                                                                          */
/* Program: heapsort                                                        */
/****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "heapsort.h"

int compare(  byte *a , byte *b ) {

  int *x, *y ;

  x = (int*)a ;

  y = (int*)b ;

  if ( *x > *y ) return 1 ;
 
  if ( *x == *y ) return 0 ;

  return -1 ;

}

int main( int argc, char *argv[] ) {

  int *A ;
  int n , i ;

  n = atoi( argv[1] ) ;
  A = (int*) malloc(sizeof(int)*n);

  for ( i = 0 ; i < n ; i++ ) A[i] = rand() % 10000 ; 
 
  for ( i = 0 ; i < n ; i++ ) printf(" %d ", A[i] ) ;
  printf("\n") ;

  heapsort( (byte *) A, n , sizeof(int) , compare ) ;

  printf("\n") ;
  for ( i = 0 ; i < n ; i++ ) printf(" %d ", A[i] ) ;
  printf("\n") ;

  return 0 ;

}

