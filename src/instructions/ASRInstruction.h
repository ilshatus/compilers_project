//
// Created by Ilshat on 24.11.2018.
//

#ifndef COMPILERS_PROJECT_ASRINSTRUCTION_H
#define COMPILERS_PROJECT_ASRINSTRUCTION_H

#include "Instruction.h"

class ASRInstruction: public Instruction {
public:
    ASRInstruction() = default;
    bool is_this(const string &line) override;
    string process(const string &line) override;
};


#endif //COMPILERS_PROJECT_ASRINSTRUCTION_H
