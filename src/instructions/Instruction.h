//
// Created by Ilshat on 24.11.2018.
//

#ifndef COMPILERS_PROJECT_INSTRUCTION_H
#define COMPILERS_PROJECT_INSTRUCTION_H

#include "utill/Operator.h"
#include <cassert>

using namespace std;

class Instruction {
public:
    virtual bool is_this(const string &line) = 0;

    virtual string process(const string &line) = 0;

protected:

    vector<Operator> parse(const string &line);

    string to_binary(const string &value, int len);

    string to_binary(long long value, int len);

    string get_format(const string &value);

    string twos_complement(const string &value, int len);

    string twos_complement(int value, int len);
};

#endif //COMPILERS_PROJECT_INSTRUCTION_H
