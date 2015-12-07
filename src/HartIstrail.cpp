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

}

void HartIstrail::initialize(char *sequence) {
    const size_t n = strlen(sequence);
    data.resize(n);
    for(size_t i = 0; i < n; i++) {
        data[i] = sequence[i] == 'h' || sequence[i] == 'H';
    }
}
