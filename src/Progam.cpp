//
// Written as part of Algorithm in Bioinformatics - Trees and Strings (Project 3)
//
// Program.cpp
// The main file.
//
// Copyright 2015
//
// @author: Martin Storgaard, Konstantinos Mampentzidis and Henrik McQuoid Jespersen
//

#include <iostream>
#include "FoldingAlgorithm.h"
#include "HartIstrail.h"
#include "HilbertCurve.h"

using namespace std;

int main(int argc, char **argv) {
    if(argc != 2) {
        cerr << "Usage: ./AiBToS_Project3 sequence-of-h-and-p" << endl;
    }
//
//    HartIstrail hi = HartIstrail();
//    hi.initialize(argv[1]);
//    hi.run();
//    hi.print_relative_format();

    HilbertCurve hilbertCurve;
    hilbertCurve.initialize(argv[1]);
    hilbertCurve.print_relative_format();
    return EXIT_SUCCESS;
}