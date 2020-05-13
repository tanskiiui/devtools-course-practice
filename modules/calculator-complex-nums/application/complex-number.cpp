// Copyright 2020 Kuzhelev Anton

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/complex_number_calculator.h"

int main(int argc, const char** argv) {
    ComplexCalculator app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
