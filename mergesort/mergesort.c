/****************************************************************************/
/* Programmer: Mark Berube                                                  */ 
/*                                                                          */
/* Program: mergesort                                                       */
/****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef char byte ;

struct info {

  char name[6] ;

  int age ;

} ;

void memcopy( byte *to, byte *from, int count ) {  

  while ( count-- > 0 ) *to++ = *from++ ;

}

int charcomp(  byte *a , byte *b ) {

  struct info *x, *y ;

  x = ( struct info* ) a ;

  y = ( struct info* ) b ;

  return strcmp ( x -> name, y -> name ) ;

}

int intcomp(  byte *a , byte *b ) {

  struct info *x, *y ;

  x = (struct info*) a ;
  y = (struct info*) b ;

  if( x -> age > y -> age ) return 1 ;
  if( x -> age < y -> age ) return -1 ;

  return 0 ;

}

void merge_sort( byte data[], int n, int elementsize, int (*p_cmp_f)( ) ) ;

int main( int argc, char *argv[] ) {

  char buffer[6] ;

  int age, i, count ;

  FILE *fin = fopen( argv[1], "r" ) ;

  struct info people[20] ;

  for( i = 0 ; i < 20 ; i++ ) {

    if( fscanf( fin, "%s %d", buffer, &age ) == EOF ) break ;
 
     memcopy( people[i].name, buffer, 6 ) ;
    
     people[i].age = age ;
    
     count++ ;

  }

  for( i = 0 ; i < count ; i++ ) {

    printf( " %s:%d ", people[i].name, people[i].age ) ;

  }

  printf( "\nName Sorting: " ) ;

  merge_sort( (byte*) people, count, sizeof(struct info), charcomp ) ;

  for( i = 0 ; i < count ; i++ ) {

    printf( " %s:%d ", people[i].name, people[i].age ) ;

  }

  printf( "\nNumber Sorting: " ) ;

  merge_sort( (byte*) people , count, sizeof(struct info), intcomp ) ;

  for( i = 0 ; i < count ; i++ ) {
 
    printf( " %s:%d ", people[i].name, people[i].age ) ;

  }

  printf( "\n" ) ;

  fclose(fin) ;

  return 0 ;

}

void merge_sort( byte data[], int n, int elementsize, int (*p_cmp_f)( ) )  {

  byte *firsthalf, *endoffirsthalf, *secondhalf, *endofsecondhalf, *resultbuffer, *p_result ;

  int halfsize ;

  if (n <= 1 ) return ;
  
  halfsize = n / 2 ;

  firsthalf = data ;

  secondhalf = data + halfsize * elementsize ;

  merge_sort( firsthalf, halfsize, elementsize, p_cmp_f ) ;
  merge_sort( secondhalf, n - halfsize, elementsize, p_cmp_f ) ;

  endoffirsthalf = secondhalf ;

  endofsecondhalf = data + n * elementsize ;

  resultbuffer = (byte*) malloc( n * elementsize ) ;

  p_result = resultbuffer ;

  while( firsthalf < endoffirsthalf && secondhalf < endofsecondhalf ) {

    if( (*p_cmp_f)( firsthalf, secondhalf ) < 0 ) {

      memcopy( p_result, firsthalf, elementsize ) ;
      firsthalf += elementsize ;

    }

    else {

      memcopy( p_result, secondhalf, elementsize ) ;
      secondhalf += elementsize ;

    }

    p_result += elementsize ;

  }

  while( firsthalf < endoffirsthalf ) {

    memcopy( p_result, firsthalf, elementsize ) ;
    firsthalf += elementsize ;
    p_result += elementsize ;

  }

  while( secondhalf < endofsecondhalf ) {

    memcopy( p_result, secondhalf, elementsize ) ;
    secondhalf += elementsize ;
    p_result += elementsize ;

  }
  
  memcopy( data, resultbuffer, n * elementsize ) ;

  free(resultbuffer) ;

}
