//
// Created by Ilshat on 24.11.2018.
//

#ifndef COMPILERS_PROJECT_ADDINSTRUCTION_H
#define COMPILERS_PROJECT_ADDINSTRUCTION_H

#include "Instruction.h"

class ADDInstruction : public Instruction {
public:
    ADDInstruction() = default;
    bool is_this(const string &line) override;
    string process(const string &line) override;
};


#endif //COMPILERS_PROJECT_ADDINSTRUCTION_H
