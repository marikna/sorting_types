//
//  sort.h
//  prog1-sort
//
//  Created by Marysia Knapczyk on 02/03/2023.
//

#ifndef SORT_H
#define SORT_H

void BubbleSort( int* pTab, int nSize );
void SimpleInsertionSort( int* pTab, int nSize );
void SimpleSelectionSort( int* pTab, int nSize );
void MixedSort( int* pTab, int nSize ); //zmodyfikowane babelkowe
void HalfInsertionSort( int*pTab, int nSize ); //zmodyfikowane proste wstawianie
void HeapSort( int*pTab, int nSize );
void QuickSort( int*pTab, int nSize );
/*
 HeapSort()
 QuickSort( 2 par ) // quickSort( 3 par )
 */
#endif
