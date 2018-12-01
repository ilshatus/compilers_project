//
// Created by Ilshat on 01.12.2018.
//

#include "../DataInstruction.h"

bool DataInstruction::is_this(const string &line) {
    vector<Operator> vals = parse(line);
    bool flag = vals[0].get_type() == DATA;
    for (int i = 1; i < vals.size(); i += 2) {
        flag = flag && vals[i].get_type() == NUMBER;
        if (i + 1 != vals.size()) {
            flag = flag && vals[i + 1].get_type() == COMMA;
        }
    }
    return flag;
}

string DataInstruction::process(const string &line) {
    assert(is_this(line));
    vector<Operator> vals = parse(line);
    string res;
    for (int i = 1; i < vals.size(); i += 2) {
        if (i != 1) res += '\n';
        res += to_binary(vals[i].get_value(), 32);
    }
    return res;
}

vector<string> DataInstruction::process_to_vector(const string &line) {
    assert(is_this(line));
    vector<Operator> vals = parse(line);
    vector<string> res;
    for (int i = 1; i < vals.size(); i += 2) {
        res.push_back(to_binary(vals[i].get_value(), 32));
    }
    return res;
}
