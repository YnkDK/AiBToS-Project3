//
// Written as part of Algorithm in Bioinformatics - Trees and Strings (Project 3)
//
// HartIstrail.h
// The implementation of the 1/4 algorithm by Hart and Istrail
//
// Copyright 2015
//
// @author: Martin Storgaard, Konstantinos Mampentzidis and Henrik McQuoid Jespersen
//

#ifndef AIBTOS_PROJECT3_HARTISTRAIL_H
#define AIBTOS_PROJECT3_HARTISTRAIL_H


#include "FoldingAlgorithm.h"

#define isEven(x) (x%2 == 0)
#define isOdd(x) (x%2 != 0)

class HartIstrail : public FoldingAlgorithm {
private:
    vector<bool> data;
    vector<size_t> evenL, oddR;
    vector<size_t> evenR, oddL;
    vector<size_t> *L, *R;
    size_t n;

    void findEvenOdd(); //find matchings with evens from the left and odds from the right
    void findOddEven(); //find matchings with evens from the right and odds from the left

public:
    void initialize(char *sequence);
    void run();
    void print_relative_format();
};


#endif //AIBTOS_PROJECT3_HARTISTRAIL_H
