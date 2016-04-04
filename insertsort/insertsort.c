/**********************************************************/
/* Programmer: Mark Berube                                */
/*                                                        */
/* Insertion Sort                                         */
/**********************************************************/

#include <stdio.h>

#include <stdlib.h>

typedef enum { OK, ERROR } status ;

status insertsort( int A[], int n ) ;

int main( int argc, char *argv[] ) {

  int A[100000] ;

  int i ;

  int n ;

  FILE* fin ;

  fin = fopen( argv[1], "r" ) ;

  n = atoi( argv[2] ) ;

  for ( i = 0 ; i < n ; i++ ) fscanf( fin, "%d", &A[i] ) ;

  if( insertsort( A, n ) == ERROR ) printf( "\n Trouble sorting.\n" ) ;

  printf( "\n\nThe first five numbers are" ) ;

  for ( i = 0 ; i < 5 ; i++ ) printf( " %d", A[i] ) ;

  printf( ".\n\n" ) ;

  printf( "The last five numbers are" ) ;

  for ( i = n-5 ; i < n ; i++ ) printf( " %d", A[i] ) ;

  printf( ".\n\n" ) ;

  fclose( fin ) ;

  return 0 ;

}

status insertsort( int A[], int n ) {

  int i, j, next ;

  for( i = 0 ; i < n ; i++ ) {

    next = A[i] ;

    j = i ;

    while( ( j > 0 ) && ( A[j-1] > next ) ) {

      A[j] = A[j-1] ;

      j = j - 1 ;

    }

    A[j] = next ;

  }

  return OK ;
  
}

