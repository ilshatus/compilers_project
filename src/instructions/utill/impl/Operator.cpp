//
// Created by Ilshat on 24.11.2018.
//

#include <iostream>
#include "../Operator.h"

TYPE Operator::find_type() {
    TYPE res;
    if (value.length() == 0) {
        cerr << "Error: 0 length operator." << endl;
        exit(0);
    } else if (value == "if") {
        res = IF;
    } else if (value == "goto") {
        res = GOTO;
    } else if (value == "skip") {
        res = SKIP;
    } else if (value == "stop") {
        res = STOP;
    } else if (value.length() == 1 && (value[0] < '0' || value[0] > '9')) {
        switch (value[0]) {
            case ';' :
                res = SEMICOLON;
                break;
            case ':' :
                res = COLON;
                break;
            case '*' :
                res = STAR;
                break;
            case '?' :
                res = QUESTION;
                break;
            case '+' :
                res = PLUS;
                break;
            case '-' :
                res = MINUS;
                break;
            case '&' :
                res = AND;
                break;
            case '|' :
                res = OR;
                break;
            case '^' :
                res = XOR;
                break;
            case '=' :
                res = EQUAL;
                break;
            case '>' :
                res = GREATER;
                break;
            case '<' :
                res = LESS;
                break;
            default:
                cerr << "Error: couldn't recognize operator " + value << endl;
                exit(0);
        }
    } else {
        if (value[0] == 'R') {
            int number = 0;
            for (int i = 1; i < value.length(); ++i) {
                if (value[i] < '0' || value[i] > '9') {
                    cerr << value << " " << "not digit in register operator " << endl;
                    exit(0);
                }
                number = number * 10 + (value[i] - '0');
            }
            if (number < 0 || number >= 32) {
                cerr << "register value not in range 0 31" << endl;
                exit(0);
            }

            res = TYPE::REGISTER_VALUE;
            value = to_string(number);
        } else if (value[0] >= '0' && value[0] <= '9') {
            int number = 0;
            for (char i : value) {
                if (i < '0' || i > '9') {
                    cerr << value << " " << "not digit in number operator " << endl;
                    exit(0);
                }
                number = number * 10 + (i - '0');
            }

            res = TYPE::NUMBER;
            value = to_string(number);
        } else {
            cerr << "Error couldn't recognize operator " + value << endl;
            exit(0);
        }
    }
    return res;
}

Operator::Operator(string value) {
    this->value = std::move(value);
    this->type = find_type();
}

TYPE Operator::get_type() {
    return type;
}

string Operator::get_value() {
    return value;
}