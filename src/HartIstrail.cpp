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

}

void HartIstrail::findEvenOdd() {

    size_t i, j;

    i = 0;
    j = n - 1;

    //find matchings with evens from the left and odds from the right

    while(true){

        //move i to the right as long as you keep reading p or the index of i is odd
        while(i < j && (!data[i] || !isEven(i))){
            i++;
        }

        //move j to the left as long as you keep reading p or the index of j is even

        while(i < j && (!data[j] || isEven(j))){
            j--;
        }

        //if i is more than or equal to j, we have to end the loop.

        if(i >= j){
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
        while(i < j && (!data[i] || isEven(i))){
            i++;
        }

        //move j to the left as long as you keep reading p or the index of j is odd

        while(i < j && (!data[j] || !isEven(j))){
            j--;
        }

        //if i is more than or equal to j, we have to end the loop.

        if(i >= j){
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



}

void HartIstrail::initialize(char *sequence) {
    n = strlen(sequence);
    data.resize(n);
    for(size_t i = 0; i < n; i++) {
        data[i] = sequence[i] == 'h' || sequence[i] == 'H';
    }
}
