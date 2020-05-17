// Copyright 2020 Okmyanskiy Andrey & Tanskii Yurii

#include "include/stack.h"
#include "include/stack_app.h"
#include <vector>
#include <string>
#include <sstream>

StackApp::StackApp() : message_("") {}

void StackApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a stack application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <elements>\n\n" +

        "Where all the arguments are a sequence of integers.\n";
}

bool StackApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    else if (argc != 2) {
        help(argv[0], "ERROR: Should be 1 argument.\n\n");
        return false;
    }
    return true;
}

Stack parseStack(const char* arg) {
    std::string str = arg;
    for (auto& s : str) {
        if (!(isdigit(s) || s == ',' || s == '.' || s == ' ' || s == '-')) {
            throw std::string("ERROR: Wrong format!");
        }
    }

    std::vector<double> vec;
    std::istringstream in(str);
    int size = 0;
    for (double n; in >> n; vec.push_back(n), in.get(), size++) {}

    Stack stack(size);
    for (double elem : vec) {
        stack.put(elem);
    }

    return stack;
}

std::string StackApp::operator()(int argc, const char** argv) {
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    std::ostringstream result;
    std::ostringstream resultMin;
    Stack stack;

    try {
        stack = parseStack(argv[1]);
    }
    catch (std::string& str) {
        return str;
    }

    while (!stack.isEmpty()) {
        result << stack.get() << " ";
    }
    message_ += " Stack: " + result.str();
    return message_;
}
