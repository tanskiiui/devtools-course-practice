// Copyright 2020 Andreev Sergey

#include "include/converter.h"

double Convert::convert_to_Kelvins(const double& celsius) {
    return (num_to_Kelvins + celsius);
}

double Convert::convert_to_Fahrenheit(const double& celsius) {
    return (celsius * 1.8 + 32);
}

double Convert::convert_to_Newton(const double& celsius) {
    return (num_to_Newton * celsius);
}
