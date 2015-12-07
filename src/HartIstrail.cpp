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

void HartIstrail::run() {

    size_t i, j;

    i = 0;
    j = n - 1;

    //find matchings with evens from the left and odds from the right

    while(true){

        //move i to the right as long as you keep reading p
        while(i < j && !data[i]){
            i++;
        }

        //move j to the left as long as you keep reading p

        while(i < j && !data[j]){
            j--;
        }

        //if i is more than or equal to j, we have to end the loop.

        if(i >= j){
            break;
        }

        //now we are in the case that i is some h, j is some other h and i < j, so we have to update the tables

        if(!isEven(i)){
            //if i is odd, we have to increment i
            i++;
        }
        else if(isEven(j)){
            //now i is even, so if j is also even, we have to decrement j
            j--;
        }
        else{
            //now i is even and j is odd, so we have a match
            pair<int, int> p;
            p.first = i;
            p.second = j;
        }

    }



}

void HartIstrail::initialize(char *sequence) {
    n = strlen(sequence);
    data.resize(n);
    for(size_t i = 0; i < n; i++) {
        data[i] = sequence[i] == 'h' || sequence[i] == 'H';
    }
}
