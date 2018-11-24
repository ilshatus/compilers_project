//
// Created by Ilshat on 24.11.2018.
//

#ifndef COMPILERS_PROJECT_NOPINSTRUCTION_H
#define COMPILERS_PROJECT_NOPINSTRUCTION_H

#include "Instruction.h"

class NOPInstruction: public Instruction {
public:
    NOPInstruction() = default;
    bool is_this(const string &line) override;
    string process(const string &line) override;
};


#endif //COMPILERS_PROJECT_NOPINSTRUCTION_H
