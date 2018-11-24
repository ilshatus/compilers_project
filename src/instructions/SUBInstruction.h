//
// Created by Ilshat on 24.11.2018.
//

#ifndef COMPILERS_PROJECT_SUBINSTRUCTION_H
#define COMPILERS_PROJECT_SUBINSTRUCTION_H

#include "Instruction.h"

class SUBInstruction: public Instruction {
public:
    SUBInstruction() = default;
    bool is_this(const string &line) override;
    string process(const string &line) override;
};


#endif //COMPILERS_PROJECT_SUBINSTRUCTION_H
