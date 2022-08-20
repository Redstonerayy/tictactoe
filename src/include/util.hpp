#ifndef UTIL_HPP
#define UTIL_HPP

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> SplitString(std::string stringtosplit, char character){
    std::stringstream ss(stringtosplit);
    std::string stringpart;
    std::vector<std::string> stringparts;

    while(std::getline(ss, stringpart, character)){
        stringparts.push_back(stringpart);
    }

    return stringparts;
}

#endif
