//
// Created by Ilshat on 24.11.2018.
//

#include "../Instruction.h"

vector<Operator> Instruction::parse(const string &line) {
    vector<Operator> res;

    string cur;
    for (char ch : line) {
        if (ch == ' ') {
            if (!cur.empty())
                res.emplace_back(cur);
            cur = "";
        } else if (ch == '*' || ch == '=' || ch == ':' || ch == ';' ||
                   ch == '?' || ch == '&' || ch == '+' || ch == '-' ||
                   ch == '<' || ch == '>' || ch == '|' || ch == '^' ||
                   ch == ',') {
            if (!cur.empty())
                res.emplace_back(cur);
            res.emplace_back(string(1, ch));
            cur = "";
        } else {
            cur.push_back(ch);
        }
    }
    if (!cur.empty()) {
        res.emplace_back(cur);
    }

    return res;
}

string Instruction::to_binary(const string &value, int len) {
    int val = stoi(value);
    return to_binary(val, len);
}

string Instruction::to_binary(int value, int len) {
    string res;
    while (value > 0) {
        res.push_back(static_cast<char>(value % 2 + '0'));
        value = value / 2;
    }
    while (res.size() < len) {
        res.push_back('0');
    }
    reverse(res.begin(), res.end());
    return res;
}