//
// Written as part of my master thesis in computer science at Data-Intensive System Group, Aarhus University
//
// HilbertCurve
// TODO: Describe the file
//
// Copyright 2015-2016
// Licence found in root directory applies to this file
//
// Main supervisor: Ira Assent
// Project supervisor: Mai Thai Son
// @author: Martin Storgaard
//
#include <string.h>
#include <cmath>
#include "HilbertCurve.h"

void HilbertCurve::initialize(char *sequence) {
    n = (int) strlen(sequence);
}

void HilbertCurve::print_relative_format() {
    size_t next = (size_t) ceil(log(n) / log(2));
    cout << n<< " "<< next << endl;
    size_t x, y, last_x = 0, last_y = 0;


    for(size_t i = 1; i < n; i++) {
        HilbertCurve::d2xy(next, i, &x, &y);
        if(y > last_y) {
            printf("n");
        }
        if(x > last_x) {
            printf("e");
        }
        if(x < last_x) {
            printf("w");
        }
        if(y < last_y) {
            printf("s");
        }
        last_x = x;
        last_y = y;
    }

}
