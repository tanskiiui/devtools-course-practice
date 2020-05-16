// Copyright 2020 Petrov Anton

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

#include "include/Salary.h"
#include "include/Salary_calculator.h"

SalaryCalculator::SalaryCalculator() : message_("") {}

void SalaryCalculator::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a salary calculator application.\n\n" +
        "Please provide arguments in the following format:\n\n" +
        "  $ " + appname +
        " <m_salary> <m_hours> <m_hours_over> <m_hours_admin> " +
        " Where <m_hours> <m_hours_over> <m_hours_admin> " +
        " arguments are unsigned integer numbers,"
        + " and <m_salary> is float";
}

bool SalaryCalculator::validateNumberOfArguments(int argc,
const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 5) {
        help(argv[0], "ERROR: Should be 4 arguments.\n\n");
        return false;
    }
    return true;
}

unsigned int parseUnsignedInt(const char* arg) {
char* end;
unsigned int value = std::strtoul(arg, &end, 0);
if (end[0]) {
        throw std::string("Wrong number format!");
    }

return value;
}

float parseFloat(const char* arg) {
    char* end;
    float value = strtof(arg, &end);
if (end[0]) {
        throw std::string("Wrong number format!");
    }
    return value;
}

std::string SalaryCalculator::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.h_m_hours       = parseUnsignedInt(argv[1]);
        args.h_m_hours_over  = parseUnsignedInt(argv[2]);
        args.h_m_hours_admin = parseUnsignedInt(argv[3]);
        args.s_m_salary      = parseFloat(argv[4]);
    }
    catch(std::string& str) {
        return str;
    }

    Salary sal;
    sal.setSalary(args.s_m_salary);
    sal.setHours(args.h_m_hours);
    sal.setOverHours(args.h_m_hours_over);
    sal.setAdminHours(args.h_m_hours_admin);
    std::ostringstream stream;

    stream << "payment = " << sal.payment();

    message_ = stream.str();

    return message_;
}
