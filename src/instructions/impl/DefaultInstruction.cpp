//
// Created by Ilshat on 24.11.2018.
//

#include "../DefaultInstruction.h"

bool DefaultInstruction::is_this(const string &line) {
    return true;
}

string DefaultInstruction::process(const string &line) {
    return "Default Instruction " + line;
}