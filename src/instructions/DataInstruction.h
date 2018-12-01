//
// Created by Ilshat on 01.12.2018.
//

#ifndef COMPILERS_PROJECT_DATAINSTRUCTION_H
#define COMPILERS_PROJECT_DATAINSTRUCTION_H

#include "Instruction.h"

class DataInstruction: public Instruction {
public:
    DataInstruction() = default;
    bool is_this(const string &line) override;
    string process(const string &line) override;
    vector<string> process_to_vector(const string &line);
};


#endif //COMPILERS_PROJECT_DATAINSTRUCTION_H
