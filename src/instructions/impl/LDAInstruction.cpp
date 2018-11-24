//
// Created by Ilshat on 24.11.2018.
//

#include "../LDAInstruction.h"

bool LDAInstruction::is_this(const string &line) {
    vector<Operator> vals = parse(line);
    bool flag = vals.size() == 7
                && vals[0].get_type() == REGISTER_VALUE
                && vals[1].get_type() == COLON
                && vals[2].get_type() == EQUAL
                && vals[3].get_type() == REGISTER_VALUE
                && vals[4].get_type() == PLUS
                && vals[5].get_type() == NUMBER
                && vals[6].get_type() == SEMICOLON;
    return flag;
}

string LDAInstruction::process(const string &line) {
    assert(is_this(line));

    vector<Operator> vals = parse(line);
    string res = "110010";
    res = res + to_binary(vals[3].get_value(), 5);
    res = res + to_binary(vals[0].get_value(), 5);
    res = res + '\n';
    res = res + to_binary(vals[5].get_value(), 16); //todo should it be like this?
    return res;
}