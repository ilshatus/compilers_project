//
// Created by Ilshat on 24.11.2018.
//

#ifndef COMPILERS_PROJECT_LSRINSTRUCTION_H
#define COMPILERS_PROJECT_LSRINSTRUCTION_H

#include "Instruction.h"

class LSRInstruction: public Instruction {
public:
    LSRInstruction() = default;
    bool is_this(const string &line) override;
    string process(const string &line) override;
};


#endif //COMPILERS_PROJECT_LSRINSTRUCTION_H
