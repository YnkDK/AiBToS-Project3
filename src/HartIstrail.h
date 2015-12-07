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

class HartIstrail : public FoldingAlgorithm {
private:
    vector<bool> data;
    vector<pair<int, int>> evenL, oddR;
    vector<pair<int, int>> evenR, oddL;
    size_t n;

    bool isEven(size_t index){
        return index%2==0;
    }

public:
    void initialize(char *sequence);
    void run();
    void print_relative_format();
};


#endif //AIBTOS_PROJECT3_HARTISTRAIL_H
