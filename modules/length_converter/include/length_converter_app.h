// Copyright 2020 Brazhnikov Eugene

#ifndef MODULES_LENGTH_CONVERTER_INCLUDE_LENGTH_CONVERTER_APP_H_
#define MODULES_LENGTH_CONVERTER_INCLUDE_LENGTH_CONVERTER_APP_H_

#include <string>
#include "include/length_converter.h"

using namespace std;

class LengthCalculator {
public:
    LengthCalculator() = default;
    std::string operator()(int argc, const char** argv);
private:
    void Help(const char* appname, const char* message = "");
    bool ValidateNumberOfArgs(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double value;
        string operation;
        int side;
    } Arguments;
};

#endif  // MODULES_CALCULATOR_COMPLEX_NUMS_INCLUDE_LENGTH_CONVERTER_APP_H_
