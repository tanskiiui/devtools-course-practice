// Copyright 2020 PETROV ANTON

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/Salary_calculator.h"

int main(int argc, const char** argv) {
    SalaryCalculator app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
