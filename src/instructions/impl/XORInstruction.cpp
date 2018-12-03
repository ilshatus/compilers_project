//
// Created by Ilshat on 24.11.2018.
//

#include "../XORInstruction.h"

bool XORInstruction::is_this(const string &line) {
    vector<Operator> vals = parse(line);
    bool flag = vals[0].get_type() == REGISTER_VALUE
                && vals[1].get_type() == XOR
                && vals[2].get_type() == EQUAL
                && vals[3].get_type() == REGISTER_VALUE;
    flag = flag
           && ((vals[4].get_type() == SEMICOLON && vals.size() == 5)
               || (vals[4].get_type() == FORMAT && vals[5].get_type() == NUMBER
                   && vals[6].get_type() == SEMICOLON && vals.size() == 7));
    return flag;
}

string XORInstruction::process(const string &line) {
    assert(is_this(line));
    vector<Operator> vals = parse(line);
    string format = "11";
    if (vals.size() == 7) format = get_format(vals[5].get_value());
    string res = format + "1011";
    res = res + to_binary(vals[3].get_value(), 5);
    res = res + to_binary(vals[0].get_value(), 5);
    return res;
}
