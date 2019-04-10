//
//  Sorting.cpp
//  CS202HW1
//
//  Created by Fırat Yıldız on 10/14/18.
//  Copyright © 2018 Fırat Yıldız. All rights reserved.
//

#include "Sorting.hpp"
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int comparisonMerge = 0;
int moveMerge = 0;



void insertionsort(int theArray[], int first, int last, int &compCount, int &moveCount) {

    int comparisonInsertion = 0;
    int moveInsertion = 0;
    
    for (int unsorted = first; unsorted < last; ++unsorted) {
        int nextItem = theArray[unsorted];
        comparisonInsertion ++;
        int loc = unsorted;
        for (  ;(loc > 0) && (theArray[loc-1] > nextItem); --loc){
            comparisonInsertion ++;
            theArray[loc] = theArray[loc-1];
            moveInsertion += 3;
        }
        theArray[loc] = nextItem;
    }
    compCount = comparisonInsertion;
    moveCount = moveInsertion;
}

const int MAX_SIZE = 21000;
//buna bak
void merge(int theArray[], int first, int mid, int last) {
    
    int tempArray[MAX_SIZE];     // temporary array
    
    int first1 = first;     // beginning of first subarray
    int last1 = mid;         // end of first subarray
    int first2 = mid + 1;    // beginning of second subarray
    int last2 = last;        // end of second subarray
    int index = first1; // next available location in tempArray
    for ( ; (first1 <= last1) && (first2 <= last2); ++index) {
        comparisonMerge ++;
        comparisonMerge ++;
        if (theArray[first1] < theArray[first2]) {
            comparisonMerge ++;
            tempArray[index] = theArray[first1];
            moveMerge++;
            ++first1;
        }
        else {
            tempArray[index] = theArray[first2];
            moveMerge++;
            ++first2;
        }
    }
    // finish off the first subarray, if necessary
    for (; first1 <= last1; ++first1, ++index){
        comparisonMerge ++;
        tempArray[index] = theArray[first1];
        moveMerge++;
    }
    // finish off the second subarray, if necessary
    for (; first2 <= last2; ++first2, ++index){
        comparisonMerge ++;
        tempArray[index] = theArray[first2];
        moveMerge++;
    }
    // copy the result back into the original array
    for (index = first; index <= last; ++index){
        comparisonMerge ++;
        theArray[index] = tempArray[index];
        moveMerge++;
    }
    
}  // end merge

void mergesort(int theArray[], int first, int last, int &compCount, int &moveCount) {
    
    if (first < last) {
        int mid = (first + last)/2;     // index of midpoint
        mergesort(theArray, first, mid, compCount, moveCount);
        mergesort(theArray, mid+1, last, compCount, moveCount);
        // merge the two halves
        merge(theArray, first, mid, last);
        compCount = comparisonMerge;
        moveCount = moveMerge;
    }
}  // end mergesort


void partition(int theArray[], int first, int last, int &pivotIndex, int &compCount, int &moveCount) {
    //choosePivot(theArray, first, last);
    int pivot = theArray[last]; // copy pivot
    // initially, everything but pivot is in unknown
    int lastS1 = first - 1;           // index of last item in S1
    int firstUnknown = first; // index of first item in unknown
    
    // move one item at a time until unknown region is empty
    for (  ; firstUnknown <= last - 1; ++firstUnknown) {
        // Invariant: theArray[first+1..lastS1] < pivot
        //            theArray[lastS1+1..firstUnknown-1] >= pivot
        // move item from unknown to proper region
        compCount++;
        if (theArray[firstUnknown] < pivot) {
            ++lastS1;
            swap(theArray[lastS1], theArray[firstUnknown]);
            compCount =+3;
        }    // else belongs to S2
    }
    // place pivot in proper position and mark its location
    swap(theArray[last], theArray[lastS1 + 1]);
    moveCount =+3;
    pivotIndex = lastS1 + 1;
}

int movQ = 0;
int compQ = 0;
void quicksort(int theArray[], int first, int last, int &compCount, int &moveCount) {
    // Precondition: theArray[first..last] is an array.
    // Postcondition: theArray[first..last] is sorted.
    int pivotIndex;
    if (first < last) {
        // create the partition: S1, pivot, S2
        
        partition(theArray, first, last, pivotIndex, compQ, movQ);
        // sort regions S1 and S2
        compCount += compQ;
        moveCount += movQ;
        quicksort(theArray, first, pivotIndex-1, compCount, movQ);
        compCount += compQ;
        moveCount += movQ;
        quicksort(theArray, pivotIndex+1, last, compCount, movQ);
        compCount += compQ;
        moveCount += movQ;
        
    }
    
}

void partitionHybrid(int theArray[], int first, int last, int &pivotIndex, int &compCount, int &moveCount) {
    //choosePivot(theArray, first, last);
    int pivot = theArray[last]; // copy pivot
    // initially, everything but pivot is in unknown
    int lastS1 = first - 1;           // index of last item in S1
    int firstUnknown = first; // index of first item in unknown
    
    // move one item at a time until unknown region is empty
    for (  ; firstUnknown <= last - 1; ++firstUnknown) {
        // Invariant: theArray[first+1..lastS1] < pivot
        //            theArray[lastS1+1..firstUnknown-1] >= pivot
        // move item from unknown to proper region
        compCount++;
        if (theArray[firstUnknown] < pivot) {
            ++lastS1;
            swap(theArray[lastS1], theArray[firstUnknown]);
            moveCount =+3;
        }    // else belongs to S2
    }
    // place pivot in proper position and mark its location
    swap(theArray[last], theArray[lastS1 + 1]);
    moveCount =+3;
    pivotIndex = lastS1 + 1;
}

int comparisonHybrid = 0;
int moveHybrid = 0;
void hybridsort(int theArray[], int first, int last, int &compCount, int &moveCount){
    if(last-first+1 < 10){
        insertionsort(theArray, first + 1, last + 1, compCount, moveCount);
    }
    else{
        int pivotIndex;
        partitionHybrid(theArray, first, last, pivotIndex, comparisonHybrid, moveHybrid);
        compCount += comparisonHybrid;
        moveCount += moveHybrid;
        hybridsort(theArray, first, pivotIndex - 1, comparisonHybrid, moveHybrid);
        compCount += comparisonHybrid;
        moveCount += moveHybrid;
        hybridsort(theArray, pivotIndex + 1,  last, comparisonHybrid, moveHybrid);
        compCount += comparisonHybrid;
        moveCount += moveHybrid;
    }
    
}

void performanceAnalysis(int arrSize){
    int arr[arrSize];
    int arrM[arrSize];
    int arrQ[arrSize];
    int arrH[arrSize];
    int compI = 0;
    int movI = 0;
    int compM = 0;
    int movM = 0;
    int compQ = 0;
    int movQ = 0;
    int compH = 0;
    int movH = 0;
    
    /*for(int i = 0; i < arrSize; i++){
        arr[i] = rand() * arrSize;
    }*/
    int j = 0;
    for(int i = arrSize - 1; i >= 0; i--){
        arr[j] = i;
        j++;
    }
    clock_t t;
    t = clock();
    insertionsort(arr, 1, arrSize, compI, movI);
    cout<<"(Insertion) Number of comparisons are: "<<compI<<endl;
    cout<<"(Insertion) Number of moves are: "<< movI <<endl;
    t = clock() - t;
    cout<<"Time for insertion sort: "<<t<<endl;
    
    //100 ve ustu variablelarda calismiyor. Hybrid ile ilgili hesap ve karsilastiracak deger sor.
    clock_t t1;
    t1 = clock();
    /*for(int i = 0; i < arrSize; i++){
        arrM[i] = rand() * arrSize;
    }*/
    /*for(int i = 0; i < arrSize; i++){
        arrM[i] = i * 2;
    }*/
    j = 0;
    for(int i = arrSize - 1; i >= 0; i--){
        arrM[j] = i;
        j++;
    }
    mergesort(arrM, 1, arrSize, compM, movM);
    cout<<"(Merge) Number of comparisons are: "<<compM<<endl;
    cout<<"(Merge) Number of moves are: "<<movM<<endl;
    t1 = clock() - t1;
    cout<<"Time for merge sort: "<<t1<<endl;
    
    /*for(int i = 0; i < arrSize; i++){
        arrQ[i] = rand() * arrSize;
    }*/
    /*for(int i = 0; i < arrSize; i++){
        arrQ[i] = i * 2;
    }*/
    j = 0;
    for(int i = arrSize - 1; i >= 0; i--){
        arrQ[j] = i;
        j++;
    }
    clock_t t2;
    t2 = clock();
    quicksort(arrQ, 0, arrSize - 1, compQ, movQ);
    cout<<"(Quick) Number of comparisons are: "<<compQ<<endl;
    cout<<"(Quick) Number of moves are: "<< movQ <<endl;
    t2 = clock() - t2;
    cout<<"Time for quick sort: "<<t2<<endl;
    
    /*for(int i = 0; i < arrSize; i++){
        arrH[i] = rand() * arrSize;
    }*/
    /*for(int i = 0; i < arrSize; i++){
        arrH[i] = i * 2;
    }*/
    j = 0;
    for(int i = arrSize - 1; i >= 0; i--){
        arrH[j] = i;
        j++;
    }
    clock_t t3;
    t3 = clock();
    hybridsort(arrH, 0, arrSize - 1, compH, movH);
    cout<<"(Hybrid) Number of comparisons are: "<< compH <<endl;
    cout<<"(Hybrid) Number of moves are: "<< movH <<endl;
    t3 = clock() - t3;
    cout<<"Time for quick sort: "<<t3<<endl;
}
