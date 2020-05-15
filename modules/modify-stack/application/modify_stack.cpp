// Copyright 2020 Okmyanskiy Andrey

#include <iostream>
#include <string>
#include <sstream>
#include <vector>


#include "include/modify_stack_app.h"
using namespace std;
int main(int argc, const char** argv) {
    StackApp app;
    std::string output = app(argc, argv);
    std::cout << output << std::endl;
    // std::cout << std::endl << "argc: " << argc << std::endl << argv[1] << std::endl;
    // string str = argv[1];
    // std::vector<double> vec;
    
    // std::istringstream in(str);
    // int size = 0;
    // for (double n; in >> n; vec.push_back(n), in.get(), size++) {}
    // for(int i = 0; i < vec.size(); i++)
    //     cout << vec[i] << ' ';
    // cout << endl << "size: " << size << endl;
    return 0;
}
