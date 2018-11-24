//
// Created by Ilshat on 24.11.2018.
//

#ifndef COMPILERS_PROJECT_ANDINSTRUCTION_H
#define COMPILERS_PROJECT_ANDINSTRUCTION_H

#include "Instruction.h"

class ANDInstruction: public Instruction {
public:
    ANDInstruction() = default;
    bool is_this(const string &line) override;
    string process(const string &line) override;
};


#endif //COMPILERS_PROJECT_ANDINSTRUCTION_H
