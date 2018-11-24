//
// Created by Ilshat on 24.11.2018.
//

#include "../ASRInstruction.h"

bool ASRInstruction::is_this(const string &line) {
    vector<Operator> vals = parse(line);
    bool flag = vals.size() == 6
                && vals[0].get_type() == REGISTER_VALUE
                && vals[1].get_type() == GREATER
                && vals[2].get_type() == GREATER
                && vals[3].get_type() == EQUAL
                && vals[4].get_type() == REGISTER_VALUE
                && vals[5].get_type() == SEMICOLON;
    return flag;
}

string ASRInstruction::process(const string &line) {
    assert(is_this(line));
    vector<Operator> vals = parse(line);
    string res = "110111"; //todo specify format(8, 16 or 32 bit)
    res = res + to_binary(vals[4].get_value(), 5);
    res = res + to_binary(vals[0].get_value(), 5);
    return res;
}