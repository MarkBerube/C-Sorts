/******************************************************************/
/* heapsort.c                                                     */
/******************************************************************/
#include "heapsort.h"


void heapsort( byte data[], int n, int elementsize, int ( *p_cmp_f )( ) ) {

  int i ;
  int sorted ;
  byte *p_sorted ;

  for( i = 0 ; i < n ; i++ )

    siftup( data, i, elementsize, p_cmp_f ) ;
 
  p_sorted = data + n * elementsize ;

  for(sorted = n - 1 ; sorted != 0 ; sorted-- ) {

    p_sorted -= elementsize ;

    memswap( p_sorted, data, elementsize ) ;

    siftdown( data, sorted, elementsize, p_cmp_f ) ;

  }

}

void siftup( byte data[], int element, int elementsize, int ( *p_cmp_f )( ) ) {

  byte *p_parent, *p_element ;
  int parent ;
  int cmp_value ;

  if( element == 0 ) return ;

  p_element = data + element * elementsize ;

  do {

    parent = ( element - 1 ) / 2 ;

    p_parent = data + parent * elementsize ;

    cmp_value = (*p_cmp_f)(p_element, p_parent) ;

    if( cmp_value > 0 ) {

      memswap( p_element, p_parent, elementsize ) ;

      element = parent ;

      p_element = p_parent ;

    }

  } while( element != 0 && cmp_value > 0 ) ;

}

void siftdown( byte data[], int n, int elementsize, int ( *p_cmp_f )( ) ) {

  int parent, leftchild, rightchild ;
  int lastinterior ;
  byte *p_parent, *p_left, *p_right ;
  int right_cmp, left_cmp, lr_cmp ;

  if( n == 1 ) return ;

  lastinterior = ( n / 2 ) - 1 ;

  parent = 0 ;

  do {

    leftchild = 2 * parent + 1 ;

    rightchild = leftchild + 1 ;

    p_parent = data + parent * elementsize ;

    p_left = data + leftchild * elementsize ;

    p_right = data + rightchild * elementsize ;

    right_cmp = 0 ;

    left_cmp = (*p_cmp_f)(p_parent,p_left);

    if( rightchild >= n ) {

      if( left_cmp < 0 ) {

	memswap( p_parent, p_left, elementsize ) ;

	parent = leftchild ;

      }

    } else {

      right_cmp = (*p_cmp_f)( p_parent, p_right ) ;

      lr_cmp = (*p_cmp_f)( p_left, p_right ) ;

      if( left_cmp < 0 || right_cmp < 0 ) {

	if( lr_cmp > 0 ) {

	  memswap( p_parent, p_left, elementsize ) ;

	  parent = leftchild ;
	  
	} else {

	  memswap( p_parent, p_right, elementsize ) ;

	  parent = rightchild ;

	}
      }
    }
  } while ( parent <= lastinterior && ( left_cmp < 0 || right_cmp < 0 ) ) ;
}

void memswap( byte *to, byte *from, int count ) {  

  byte tmp ;

  while ( count-- > 0 ) {

    tmp = *to ;

    *to++ = *from ;

    *from++ = tmp ;

  }
}
