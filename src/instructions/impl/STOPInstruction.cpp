//
// Created by Ilshat on 24.11.2018.
//

#include "../STOPInstruction.h"

bool STOPInstruction::is_this(const string &line) {
    vector<Operator> vals = parse(line);
    bool flag = vals.size() == 1
                && vals[0].get_type() == STOP;
    return flag;
}

string STOPInstruction::process(const string &line) {
    assert(is_this(line));
    vector<Operator> vals = parse(line);
    string res = "000000";
    res = res + "0000000000";
    return res;
}