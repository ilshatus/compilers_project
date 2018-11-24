//
// Created by Ilshat on 24.11.2018.
//

#include "../NOPInstruction.h"

bool NOPInstruction::is_this(const string &line) {
    vector<Operator> vals = parse(line);
    bool flag = vals.size() == 1
                && vals[0].get_type() == SKIP;
    return flag;
}

string NOPInstruction::process(const string &line) {
    assert(is_this(line));
    vector<Operator> vals = parse(line);
    string res = "010000";
    res = res + "0000000000";
    return res;
}