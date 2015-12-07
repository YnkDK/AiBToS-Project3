//
// Written as part of Algorithm in Bioinformatics - Trees and Strings (Project 3)
//
// FoldingAlgorithm.h
// The interface used for both folding algorithms
//
// Copyright 2015
//
// @author: Martin Storgaard, Konstantinos Mampentzidis and Henrik McQuoid Jespersen
//
#ifndef AIBTOS_PROJECT3_FOLDINGALGORITHM_H
#define AIBTOS_PROJECT3_FOLDINGALGORITHM_H

#include <vector>
#include <iostream>

using namespace std;

class FoldingAlgorithm {
public:
    virtual void initialize(char *sequence) = 0;
    virtual void run() = 0;
    virtual void print_relative_format() = 0;
};

#endif //AIBTOS_PROJECT3_FOLDINGALGORITHM_H
