//
//  main.cpp
//  CS202HW1
//
//  Created by Fırat Yıldız on 10/13/18.
//  Copyright © 2018 Fırat Yıldız. All rights reserved.
//

#include <iostream>
#include <string>
#include "Sorting.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    /*int arrNum [20] = {99,106,9,7,8,40,3,167,0,5,88,90,45,7,5,6,4,3,80,23};
    int comp = 0;
    int mov = 0;
    quicksort(arrNum, 0, 19, comp, mov);
    cout<<"First Number is: "<<arrNum[0]<<endl;
    cout<<"(Hybrid) Number of comparisons are: "<<comp<<endl;
    cout<<"(Hybrid) Number of moves are: "<<mov<<endl;*/
    
    performanceAnalysis(21000);
    return 0;
}
