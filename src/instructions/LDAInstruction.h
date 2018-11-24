//
// Created by Ilshat on 24.11.2018.
//

#ifndef COMPILERS_PROJECT_LDAINSTRUCTION_H
#define COMPILERS_PROJECT_LDAINSTRUCTION_H

#include "Instruction.h"

class LDAInstruction: public Instruction {
public:
    LDAInstruction() = default;
    bool is_this(const string &line) override;
    string process(const string &line) override;
};


#endif //COMPILERS_PROJECT_LDAINSTRUCTION_H
