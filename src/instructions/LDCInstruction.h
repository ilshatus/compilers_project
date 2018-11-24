//
// Created by Ilshat on 24.11.2018.
//

#ifndef COMPILERS_PROJECT_LDCINSTRUCTION_H
#define COMPILERS_PROJECT_LDCINSTRUCTION_H

#include "Instruction.h"

class LDCInstruction: public Instruction {
public:
    LDCInstruction() = default;
    bool is_this(const string &line) override;
    string process(const string &line) override;
};


#endif //COMPILERS_PROJECT_LDCINSTRUCTION_H
