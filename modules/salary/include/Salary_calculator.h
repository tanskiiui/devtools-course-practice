// Copyright 2020 Petrov Anton

#ifndef MODULES_SALARY_INCLUDE_SALARY_CALCULATOR_H_
#define MODULES_SALARY_INCLUDE_SALARY_CALCULATOR_H_

#include <string>

class SalaryCalculator {
 public:
    SalaryCalculator();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        float s_m_salary;
        unsigned int h_m_hours;
        unsigned int h_m_hours_over;
        unsigned int h_m_hours_admin;
    }Arguments;
};

#endif  // MODULES_SALARY_INCLUDE_SALARY_CALCULATOR_H_
