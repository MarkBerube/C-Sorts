/****************************************************************************/
/* Programmer: Mark Berube                                                  */ 
/*                                                                          */
/* Program: quicksort                                                       */
/****************************************************************************/

#include "quicksort.h"

int compare(  byte *a , byte *b ) {

  double *x, *y ;

  x = (double*)a ;

  y = (double*)b ;

  if ( *x > *y ) return 1 ;
 
  if ( *x == *y ) return 0 ;

  return -1 ;

}


int main( int argc, char *argv[] ) {

  double *A ;

  int n , i ;

  time_t start ;

  time_t stop  ;

  n = atoi( argv[1] ) ;

  A = (double*) malloc(sizeof(double)*n+1);

  if ( A == NULL ) {

    printf(" Error mallocing \n" ) ;

    return -1 ;

  } 

  for ( i = 0 ; i <= n ; i++ ) A[i] = rand() % 10000 ; 
 
  for ( i = 0 ; i <= 19 ; i++ ) printf(" %f ", A[i] ) ;

  printf("\n") ;

  start = time( NULL ) ;

  quicksort( (byte *) A, n+1 , sizeof(double) , compare ) ;

  stop = time( NULL ) ;

  printf("\n") ;

  for ( i = 0 ; i <= 19 ; i++ ) printf(" %f ", A[i] ) ;

  printf("\n") ;

  printf( "\nTime: %d seconds \n", (int) difftime( stop, start ) ) ;

  return 0 ;

}


