//
//  Sorting.hpp
//  CS202HW1
//
//  Created by Fırat Yıldız on 10/14/18.
//  Copyright © 2018 Fırat Yıldız. All rights reserved.
//

#ifndef Sorting_hpp
#define Sorting_hpp

#include <stdio.h>
void quicksort(int theArray[], int first, int last, int &compCount, int &moveCount);
void insertionsort(int theArray[], int first, int last, int &compCount, int &moveCount);
void merge(int theArray[], int first, int mid, int last);
void mergesort(int theArray[], int first, int last, int &compCount, int &moveCount);
void partition(int theArray[], int first, int last, int &pivotIndex);
void partitionHybrid(int theArray[], int first, int last, int &pivotIndex);
void hybridsort(int theArray[], int first, int last, int &compCount, int &moveCount);
void performanceAnalysis(int arrSize);
#endif /* Sorting_hpp */
