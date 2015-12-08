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
#ifndef AIBTOS_PROJECT3_HILBERTCURVE_H
#define AIBTOS_PROJECT3_HILBERTCURVE_H


#include "FoldingAlgorithm.h"

class HilbertCurve : public FoldingAlgorithm {
private:
    int n;

    //rotate/flip a quadrant appropriately
    void rot(size_t n, size_t *x, size_t *y, size_t rx, size_t ry) {
        if (ry == 0) {
            if (rx == 1) {
                *x = n-1 - *x;
                *y = n-1 - *y;
            }

            //Swap x and y
            size_t t  = *x;
            *x = *y;
            *y = t;
        }
    }

    //convert d to (x,y)
    void d2xy(size_t n, size_t d, size_t *x, size_t *y) {
        size_t rx, ry, s, t=d;
        *x = *y = 0;
        for (s=1; s<n; s*=2) {
            rx = 1 & (t/2);
            ry = 1 & (t ^ rx);
            rot(s, x, y, rx, ry);
            *x += s * rx;
            *y += s * ry;
            t /= 4;
        }
    }
public:
    void initialize(char *sequence);
    void run() {};
    void print_relative_format();
};


#endif //AIBTOS_PROJECT3_HILBERTCURVE_H
