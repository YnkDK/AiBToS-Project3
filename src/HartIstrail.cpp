//
// Written as part of Algorithm in Bioinformatics - Trees and Strings (Project 3)
//
// HartIstrail.cpp
// The implementation of the 1/4 algorithm by Hart and Istrail
//
// Copyright 2015
//
// @author: Martin Storgaard, Konstantinos Mampentzidis and Henrik McQuoid Jespersen
//

#include <string.h>
#include "HartIstrail.h"

void HartIstrail::print_relative_format() {
    int64_t j, l, r = (R->size()-1);
    for(j = 0; j < (*L)[0]; j++) {
        printf("f");
    }
    // Start printing from the left
    for(l = 0; l < L->size()-1; l++) {
        const size_t dist = (*L)[l+1]-(*L)[l];
        if(dist >= 4) {
            // Make a tongue?
            printf("l");
            const size_t steps_forward = (dist - 2) / 2 - 1;
            for(size_t tmp = 0; tmp < steps_forward; tmp++) printf("f");
            printf("rr");
            for(size_t tmp = 0; tmp < steps_forward; tmp++) printf("f");
            printf("l");
        } else {
            // Continue
            for(int64_t tmp = 0; tmp < dist; tmp++) printf("f");
        }
    }
    // Connect left and right part

    const size_t steps_forward = ((*R)[r] - (*L)[l] - 1) / 2;
    for(size_t tmp = 0; tmp < steps_forward; tmp++) printf("f");
    printf("rr");
    for(size_t tmp = 0; tmp < steps_forward - 1; tmp++) printf("f");

    // Start printing the right part
    for(; r > 0; r--) {
        const size_t dist = (*R)[r-1]-(*R)[r];
        if(dist >= 4) {
            printf("l");
            const size_t steps_forward = (dist - 2) / 2 - 1;
            for(size_t tmp = 0; tmp < steps_forward; tmp++) printf("f");
            printf("rr");
            for(size_t tmp = 0; tmp < steps_forward; tmp++) printf("f");
            printf("l");
        } else {
            for(int64_t tmp = 0; tmp < dist; tmp++) printf("f");
        }
    }
    // Print the rest
    for(r = (*R)[0]; r < n-1; r++) printf("f");
}

void HartIstrail::findEvenOdd() {

    size_t i, j;

    i = 0;
    j = n - 1;

    //find matchings with evens from the left and odds from the right

    while(true){

        //move i to the right as long as you keep reading p or the index of i is odd
        while(i < j - 1 && (!data[i] || isOdd(i))){
            i++;
        }

        //move j to the left as long as you keep reading p or the index of j is even

        while(i < j - 1 && (!data[j] || isEven(j))){
            j--;
        }

        //if i is more than or equal to j, we have to end the loop.

        if(i >= j - 1){
            break;
        }

        //now i<j and i is even and j is odd
        evenL.push_back(i);
        oddR.push_back(j);
        i++;
        j--;

    }

}

void HartIstrail::findOddEven() {

    size_t i, j;

    i = 0;
    j = n - 1;

    //find matchings with evens from the right and odds from the left

    while(true){

        //move i to the right as long as you keep reading p or the index of i is even
        while(i < j - 1 && (!data[i] || isEven(i))){
            i++;
        }

        //move j to the left as long as you keep reading p or the index of j is odd

        while(i < j - 1 && (!data[j] || isOdd(j))){
            j--;
        }

        //if i is more than or equal to j, we have to end the loop.

        if(i >= j - 1){
            break;
        }

        //now i<j and i is odd and j is even
        evenR.push_back(j);
        oddL.push_back(i);
        i++;
        j--;

    }

}

void HartIstrail::run() {

    findEvenOdd();
    findOddEven();

    if(evenL.size() + oddR.size() > oddL.size() + evenR.size()) {
        L = &evenL;
        R = &oddR;
    } else {
        L = &oddL;
        R = &evenR;
    }
}

void HartIstrail::initialize(char *sequence) {
    n = strlen(sequence);
    data.resize(n);
    for(size_t i = 0; i < n; i++) {
        data[i] = sequence[i] == 'h' || sequence[i] == 'H';
    }
}
