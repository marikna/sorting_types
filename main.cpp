//
//  main.cpp
//  prog1-sort
//
//  Created by Marysia Knapczyk on 02/03/2023.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "sort.h"
#include <time.h>
using namespace std;

//#define _PRINT_TAB
#define MAXTAB 100
#define MAXLINE 10

// zdefiniowac typ wskaznikowy na funkcje (pFun)


void initTab( int* pTab, int nSize );
void printTab( int* pTab, int nSize );
void copyTab( int* pDestTab, int* pSrcTab , int nSize );
int createTab( int** pTab, int nSize );
void delTab( int** pTab );

typedef void( *pFun )( int*, int );


// funkcja biblioteczna liczaca czas

int main( int argc, char* argv[] )
{
  if(argc != 2)
  {
    printf( "Usage: %s <tab_size>\n", argv[0] );
    return 1;
  }
  int nSize = atoi( argv[1] );
  
  //zdefiniuj tablice wzorcowa pattern i zainicjuj ja losowo
  //int patternTab[MAXTAB] = { 0 };
  
  int* pPattern = NULL;
  if( !createTab( &pPattern, nSize ))
  {
    perror( "Allocation ERROR - pPattern!\n");
    return 2;
  }
  
  //initTab( patternTab, MAXTAB );
  //printTab( patternTab, MAXTAB );
  
  initTab( pPattern , nSize);
  int* pTab = NULL;
  
  if( !createTab( &pTab, nSize ) )
  {
    perror("Allocation ERROR - pTab!\n" );
    return 3;
  }
  
  //  zdefiniowac tablice typu pFun bezrozmiarowo i zainicjowac nazwami funkcji sortujacych (pSortFun[])      tablica={} insertion
  //  zdefiniowac tablice (pSortNames[]) bezrozmiarowo i zaincijowac stringami z nazwami sortowan
  //  przy czym pSortnames[i] odpowiada pSortFun[i]
  
  pFun pSortFun[] = { BubbleSort, SimpleInsertionSort, SimpleSelectionSort, MixedSort, HalfInsertionSort, HeapSort, QuickSort };
  const char* pSortNames[] = { "BubbleSort", "SimpleInsertionSort", "SimpleSelectionSort", "MixedSort", "HalfInsertionSort", "HeapSort", "QuickSort" };
  
  if ( !createTab( &pTab, nSize ) ) {
    perror( "Error CreateTab2!\n" );
    return -3;
  }
  
 const int x = sizeof( pSortFun ) / sizeof( pFun );
  
  //  wypisac tablice na warunkowej kompilacji _PRINT_TAB
#ifdef _PRINT_TAB
  printf( "Losowa tablica przed sortowaniem:\n" );
 // copyTab( pTab, pPattern, MAXTAB );
  printTab( pPattern, ( nSize < MAXTAB ) ? nSize : MAXTAB );
#endif
  
  //  petla for - ilosc iteracji obliczyc wczesniej uzywajac sizeof tablicy/jeden elemnt
  for ( int i = 0; i < x; i++ ) {
    copyTab( pTab, pPattern, nSize );
    clock_t start = clock();
    pSortFun[ i ]( pTab, nSize );
    printf( "\nSortowanie %s potrwa: \n %f\n", pSortNames[ i ], ( double )( clock() - start ) / CLOCKS_PER_SEC * 1000 );
#ifdef _PRINT_TAB
  printTab( pTab, ( nSize < MAXTAB ) ? nSize : MAXTAB );
#endif
  }
    
    free(pPattern);
    free(pTab);
  }
  
  
  //----------------------------------------
  
  int createTab( int** pTab, int nSize )
  {
    *pTab = (int*)malloc( nSize * sizeof( int ) );
    if( !*pTab ) // if( *pTab == NULL )
      return 0;
    memset( *pTab, 0, nSize * sizeof( int ) );
    return 1;
  }
  
  void initTab( int* pTab, int nSize )
  {
    srand( (unsigned int)time( NULL ) );
    for ( int i = 0; i < nSize; i++ )
      *pTab++ = rand() % nSize;
  }
  
  void printTab( int* pTab, int nSize )
  {
    for( int i = 0; i < nSize; i++, pTab++ )
    {
      printf( "%d ", *pTab );
      if( (i + 1) % MAXLINE == 0 )
        printf("\n");
    }
    
  }
  
  
  void copyTab( int* pDestTab, int* pSrcTab, int nSize )
  {
    memcpy( pDestTab, pSrcTab, sizeof(int) * nSize );
  }
  
  
  void delTab( int** pTab )
  {
    free( *pTab );
    *pTab = NULL;
  }
