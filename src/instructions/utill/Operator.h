//
// Created by Ilshat on 24.11.2018.
//

#ifndef COMPILERS_PROJECT_OPERATOR_H
#define COMPILERS_PROJECT_OPERATOR_H

#include <vector>
#include <string>
#include <algorithm>
#include "TYPE.h"

using namespace std;

class Operator {
    TYPE find_type();
    TYPE type;
    string value;
public:
    explicit Operator(string value);
    TYPE get_type();
    string get_value();
};

#endif //COMPILERS_PROJECT_OPERATOR_H
