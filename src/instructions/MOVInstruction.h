//
// Created by Ilshat on 24.11.2018.
//

#ifndef COMPILERS_PROJECT_MOVINSTRUCTION_H
#define COMPILERS_PROJECT_MOVINSTRUCTION_H

#include "Instruction.h"

class MOVInstruction: public Instruction {
public:
    MOVInstruction() = default;
    bool is_this(const string &line) override;
    string process(const string &line) override;
};


#endif //COMPILERS_PROJECT_MOVINSTRUCTION_H
