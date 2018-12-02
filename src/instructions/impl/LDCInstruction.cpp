//
// Created by Ilshat on 24.11.2018.
//

#include "../LDCInstruction.h"

bool LDCInstruction::is_this(const string &line) {
    vector<Operator> vals = parse(line);
    bool flag = vals.size() == 5
                && vals[0].get_type() == REGISTER_VALUE
                && vals[1].get_type() == COLON
                && vals[2].get_type() == EQUAL
                && (vals[3].get_type() == NUMBER || vals[3].get_type() == LABEL)
                && vals[4].get_type() == SEMICOLON;
    return flag;
}

string LDCInstruction::process(const string &line) {
    assert(is_this(line));
    vector<Operator> vals = parse(line);
    string res = "110010";
    if (vals[3].get_type() == NUMBER) {
        res = res + to_binary(vals[3].get_value(), 5);
        res = res + to_binary(vals[0].get_value(), 5);
    } else {
        if (labels.count(vals[3].get_value()) == 0) {
            throw "Label " + vals[3].get_value() + " not found";
        }
        // set 0 to register
        res = res + to_binary(0, 5);
        res = res + to_binary(vals[0].get_value(), 5);

        // add label address to register
        res = res + "000010";
        res = res + to_binary(vals[0].get_value(), 5);
        res = res + to_binary(vals[0].get_value(), 5);
        res = res + to_binary(labels[vals[3].get_value()], 32);
    }
    return res;
}