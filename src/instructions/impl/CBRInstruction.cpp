//
// Created by Ilshat on 24.11.2018.
//

#include "../CBRInstruction.h"

bool CBRInstruction::is_this(const string &line) {
    vector<Operator> vals = parse(line);
    bool flag = vals.size() == 5
                && vals[0].get_type() == IF
                && vals[1].get_type() == REGISTER_VALUE
                && vals[2].get_type() == GOTO
                && vals[3].get_type() == REGISTER_VALUE
                && vals[4].get_type() == SEMICOLON;
    return flag;
}

string CBRInstruction::process(const string &line) {
    assert(is_this(line));
    vector<Operator> vals = parse(line);
    string res = "111111";
    res = res + to_binary(vals[1].get_value(), 5);
    res = res + to_binary(vals[3].get_value(), 5);
    return res;
}
