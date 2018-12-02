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
    flag = flag || (vals.size() == 8
                && vals[0].get_type() == REGISTER_VALUE
                && vals[1].get_type() == COLON
                && vals[2].get_type() == EQUAL
                && vals[3].get_type() == REGISTER_VALUE
                && vals[4].get_type() == PLUS
                && vals[5].get_type() == MINUS
                && vals[6].get_type() == NUMBER
                && vals[7].get_type() == SEMICOLON);
    return flag;
}

string LDAInstruction::process(const string &line) {
    assert(is_this(line));

    vector<Operator> vals = parse(line);
    string res = "000010";
    res = res + to_binary(vals[3].get_value(), 5);
    res = res + to_binary(vals[0].get_value(), 5);
    res = res + '\n';
    if(vals[5].get_type() == NUMBER)
        res = res + twos_complement(vals[5].get_value(), 32);
    else
        res = res + twos_complement("-" + vals[6].get_value(), 32);
    return res;
}