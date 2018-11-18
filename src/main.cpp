#include <utility>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

enum TYPE {
    STRING, REGISTER_VALUE, EQUAL, STAR, COLON, SEMICOLON, IF, GOTO,
    QUESTION, PLUS, MINUS, AND, NUMBER, GREATER, LESS, OR, XOR, SKIP, STOP
};

class Operator {
    TYPE find_type() {
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

    TYPE type;
    string value;

public:
    explicit Operator(string value) {
        this->value = std::move(value);
        this->type = find_type();
    }

    TYPE get_type() {
        return type;
    }

    string get_value() {
        return value;
    }
};

class Instruction {
public:
    virtual bool is_this(const string &line) {
        return true;
    }

    virtual string process(const string &line) {
        return "Base Instruction " + line;
    }

protected:
    vector<Operator> parse(const string &line) {
        vector<Operator> res;

        string cur;
        for (char ch : line) {
            if (ch == ' ') {
                if (!cur.empty())
                    res.emplace_back(cur);
                cur = "";
            } else if (ch == '*' || ch == '=' || ch == ':' || ch == ';' ||
                       ch == '?' || ch == '&' || ch == '+' || ch == '-' ||
                       ch == '<' || ch == '>' || ch == '|' || ch == '^') {
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

    string to_binary(const string &value, int len) {
        int val = stoi(value);
        string res;
        while (val > 0) {
            res.push_back(static_cast<char>(val % 2 + '0'));
            val = val / 2;
        }
        while (res.size() < len) {
            res.push_back('0');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

class LDInstruction : public Instruction {
public:
    LDInstruction() = default;

    bool is_this(const string &line) override {
        vector<Operator> vals = parse(line);
        bool flag = vals.size() == 6
                    && vals[0].get_type() == REGISTER_VALUE
                    && vals[1].get_type() == COLON
                    && vals[2].get_type() == EQUAL
                    && vals[3].get_type() == STAR
                    && vals[4].get_type() == REGISTER_VALUE
                    && vals[5].get_type() == SEMICOLON;
        return flag;
    }

    string process(const string &line) override {
        assert(is_this(line));
        vector<Operator> vals = parse(line);
        string res = "110001";
        res = res + to_binary(vals[4].get_value(), 5);
        res = res + to_binary(vals[0].get_value(), 5);
        return res;
    }
};

class LDAInstruction : public Instruction {
public:
    LDAInstruction() = default;

    bool is_this(const string &line) override {
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

    string process(const string &line) override {
        assert(is_this(line));
        vector<Operator> vals = parse(line);
        string res = "110010";
        res = res + to_binary(vals[3].get_value(), 5);
        res = res + to_binary(vals[0].get_value(), 5);
        res = res + '\n';
        res = res + to_binary(vals[5].get_value(), 16); //todo should it be like this?
        return res;
    }
};

class LDCInstruction : public Instruction {
public:
    LDCInstruction() = default;

    bool is_this(const string &line) override {
        vector<Operator> vals = parse(line);
        bool flag = vals.size() == 5
                    && vals[0].get_type() == REGISTER_VALUE
                    && vals[1].get_type() == COLON
                    && vals[2].get_type() == EQUAL
                    && vals[3].get_type() == NUMBER
                    && vals[4].get_type() == SEMICOLON;
        return flag;
    }

    string process(const string &line) override {
        assert(is_this(line));
        vector<Operator> vals = parse(line);
        string res = "110010";
        res = res + to_binary(vals[3].get_value(), 5);
        res = res + to_binary(vals[0].get_value(), 5);
        return res;
    }
};

class STInstruction : public Instruction {
public:
    STInstruction() = default;

    bool is_this(const string &line) override {
        vector<Operator> vals = parse(line);
        bool flag = vals.size() == 6
                    && vals[0].get_type() == STAR
                    && vals[1].get_type() == REGISTER_VALUE
                    && vals[2].get_type() == COLON
                    && vals[3].get_type() == EQUAL
                    && vals[4].get_type() == REGISTER_VALUE
                    && vals[5].get_type() == SEMICOLON;
        return flag;
    }

    string process(const string &line) override {
        assert(is_this(line));
        vector<Operator> vals = parse(line);
        string res = "110011";
        res = res + to_binary(vals[4].get_value(), 5);
        res = res + to_binary(vals[1].get_value(), 5);
        return res;
    }
};

class MOVInstruction : public Instruction {
public:
    MOVInstruction() = default;

    bool is_this(const string &line) override {
        vector<Operator> vals = parse(line);
        bool flag = vals.size() == 5
                    && vals[0].get_type() == REGISTER_VALUE
                    && vals[1].get_type() == COLON
                    && vals[2].get_type() == EQUAL
                    && vals[3].get_type() == REGISTER_VALUE
                    && vals[4].get_type() == SEMICOLON;
        return flag;
    }

    string process(const string &line) override {
        assert(is_this(line));
        vector<Operator> vals = parse(line);
        string res = "110100"; //todo specify formar(8, 16 or 32 bit)
        res = res + to_binary(vals[3].get_value(), 5);
        res = res + to_binary(vals[0].get_value(), 5);
        return res;
    }
};

class ADDInstruction : public Instruction {
public:
    ADDInstruction() = default;

    bool is_this(const string &line) override {
        vector<Operator> vals = parse(line);
        bool flag = vals.size() == 5
                    && vals[0].get_type() == REGISTER_VALUE
                    && vals[1].get_type() == PLUS
                    && vals[2].get_type() == EQUAL
                    && vals[3].get_type() == REGISTER_VALUE
                    && vals[4].get_type() == SEMICOLON;
        return flag;
    }

    string process(const string &line) override {
        assert(is_this(line));
        vector<Operator> vals = parse(line);
        string res = "110101"; //todo specify format(8, 16 or 32 bit)
        res = res + to_binary(vals[3].get_value(), 5);
        res = res + to_binary(vals[0].get_value(), 5);
        return res;
    }
};

class SUBInstruction : public Instruction {
public:
    SUBInstruction() = default;

    bool is_this(const string &line) override {
        vector<Operator> vals = parse(line);
        bool flag = vals.size() == 5
                    && vals[0].get_type() == REGISTER_VALUE
                    && vals[1].get_type() == MINUS
                    && vals[2].get_type() == EQUAL
                    && vals[3].get_type() == REGISTER_VALUE
                    && vals[4].get_type() == SEMICOLON;
        return flag;
    }

    string process(const string &line) override {
        assert(is_this(line));
        vector<Operator> vals = parse(line);
        string res = "110110"; //todo specify format(8, 16 or 32 bit)
        res = res + to_binary(vals[3].get_value(), 5);
        res = res + to_binary(vals[0].get_value(), 5);
        return res;
    }
};

class ASRInstruction : public Instruction {
public:
    ASRInstruction() = default;

    bool is_this(const string &line) override {
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

    string process(const string &line) override {
        assert(is_this(line));
        vector<Operator> vals = parse(line);
        string res = "110111"; //todo specify format(8, 16 or 32 bit)
        res = res + to_binary(vals[4].get_value(), 5);
        res = res + to_binary(vals[0].get_value(), 5);
        return res;
    }
};

class ASLInstruction : public Instruction {
public:
    ASLInstruction() = default;

    bool is_this(const string &line) override {
        vector<Operator> vals = parse(line);
        bool flag = vals.size() == 6
                    && vals[0].get_type() == REGISTER_VALUE
                    && vals[1].get_type() == LESS
                    && vals[2].get_type() == LESS
                    && vals[3].get_type() == EQUAL
                    && vals[4].get_type() == REGISTER_VALUE
                    && vals[5].get_type() == SEMICOLON;
        return flag;
    }

    string process(const string &line) override {
        assert(is_this(line));
        vector<Operator> vals = parse(line);
        string res = "111000"; //todo specify format(8, 16 or 32 bit)
        res = res + to_binary(vals[4].get_value(), 5);
        res = res + to_binary(vals[0].get_value(), 5);
        return res;
    }
};

class ORInstruction : public Instruction {
public:
    ORInstruction() = default;

    bool is_this(const string &line) override {
        vector<Operator> vals = parse(line);
        bool flag = vals.size() == 5
                    && vals[0].get_type() == REGISTER_VALUE
                    && vals[1].get_type() == OR
                    && vals[2].get_type() == EQUAL
                    && vals[3].get_type() == REGISTER_VALUE
                    && vals[4].get_type() == SEMICOLON;
        return flag;
    }

    string process(const string &line) override {
        assert(is_this(line));
        vector<Operator> vals = parse(line);
        string res = "111001"; //todo specify format(8, 16 or 32 bit)
        res = res + to_binary(vals[3].get_value(), 5);
        res = res + to_binary(vals[0].get_value(), 5);
        return res;
    }
};

class ANDInstruction : public Instruction {
public:
    ANDInstruction() = default;

    bool is_this(const string &line) override {
        vector<Operator> vals = parse(line);
        bool flag = vals.size() == 5
                    && vals[0].get_type() == REGISTER_VALUE
                    && vals[1].get_type() == AND
                    && vals[2].get_type() == EQUAL
                    && vals[3].get_type() == REGISTER_VALUE
                    && vals[4].get_type() == SEMICOLON;
        return flag;
    }

    string process(const string &line) override {
        assert(is_this(line));
        vector<Operator> vals = parse(line);
        string res = "111010"; //todo specify format(8, 16 or 32 bit)
        res = res + to_binary(vals[3].get_value(), 5);
        res = res + to_binary(vals[0].get_value(), 5);
        return res;
    }
};

class XORInstruction : public Instruction {
public:
    XORInstruction() = default;

    bool is_this(const string &line) override {
        vector<Operator> vals = parse(line);
        bool flag = vals.size() == 5
                    && vals[0].get_type() == REGISTER_VALUE
                    && vals[1].get_type() == XOR
                    && vals[2].get_type() == EQUAL
                    && vals[3].get_type() == REGISTER_VALUE
                    && vals[4].get_type() == SEMICOLON;
        return flag;
    }

    string process(const string &line) override {
        assert(is_this(line));
        vector<Operator> vals = parse(line);
        string res = "111011"; //todo specify format(8, 16 or 32 bit)
        res = res + to_binary(vals[3].get_value(), 5);
        res = res + to_binary(vals[0].get_value(), 5);
        return res;
    }
};

class LSLInstruction : public Instruction {
public:
    LSLInstruction() = default;

    bool is_this(const string &line) override {
        vector<Operator> vals = parse(line);
        bool flag = vals.size() == 5
                    && vals[0].get_type() == REGISTER_VALUE
                    && vals[1].get_type() == LESS
                    && vals[2].get_type() == EQUAL
                    && vals[3].get_type() == REGISTER_VALUE
                    && vals[4].get_type() == SEMICOLON;
        return flag;
    }

    string process(const string &line) override {
        assert(is_this(line));
        vector<Operator> vals = parse(line);
        string res = "111100"; //todo specify format(8, 16 or 32 bit)
        res = res + to_binary(vals[3].get_value(), 5);
        res = res + to_binary(vals[0].get_value(), 5);
        return res;
    }
};

class LSRInstruction : public Instruction {
public:
    LSRInstruction() = default;

    bool is_this(const string &line) override {
        vector<Operator> vals = parse(line);
        bool flag = vals.size() == 5
                    && vals[0].get_type() == REGISTER_VALUE
                    && vals[1].get_type() == GREATER
                    && vals[2].get_type() == EQUAL
                    && vals[3].get_type() == REGISTER_VALUE
                    && vals[4].get_type() == SEMICOLON;
        return flag;
    }

    string process(const string &line) override {
        assert(is_this(line));
        vector<Operator> vals = parse(line);
        string res = "111101"; //todo specify format(8, 16 or 32 bit)
        res = res + to_binary(vals[3].get_value(), 5);
        res = res + to_binary(vals[0].get_value(), 5);
        return res;
    }
};

class CNDInstruction : public Instruction {
public:
    CNDInstruction() = default;

    bool is_this(const string &line) override {
        vector<Operator> vals = parse(line);
        bool flag = vals.size() == 5
                    && vals[0].get_type() == REGISTER_VALUE
                    && vals[1].get_type() == QUESTION
                    && vals[2].get_type() == EQUAL
                    && vals[3].get_type() == REGISTER_VALUE
                    && vals[4].get_type() == SEMICOLON;
        return flag;
    }

    string process(const string &line) override {
        assert(is_this(line));
        vector<Operator> vals = parse(line);
        string res = "111110"; //todo specify format(8, 16 or 32 bit)
        res = res + to_binary(vals[3].get_value(), 5);
        res = res + to_binary(vals[0].get_value(), 5);
        return res;
    }
};

class CBRInstruction : public Instruction {
public:
    CBRInstruction() = default;

    bool is_this(const string &line) override {
        vector<Operator> vals = parse(line);
        bool flag = vals.size() == 5
                    && vals[0].get_type() == IF
                    && vals[1].get_type() == REGISTER_VALUE
                    && vals[2].get_type() == GOTO
                    && vals[3].get_type() == REGISTER_VALUE
                    && vals[4].get_type() == SEMICOLON;
        return flag;
    }

    string process(const string &line) override {
        assert(is_this(line));
        vector<Operator> vals = parse(line);
        string res = "111111";
        res = res + to_binary(vals[1].get_value(), 5);
        res = res + to_binary(vals[3].get_value(), 5);
        return res;
    }
};

class NOPInstruction : public Instruction {
public:
    NOPInstruction() = default;

    bool is_this(const string &line) override {
        vector<Operator> vals = parse(line);
        bool flag = vals.size() == 1
                    && vals[0].get_type() == SKIP;
        return flag;
    }

    string process(const string &line) override {
        assert(is_this(line));
        vector<Operator> vals = parse(line);
        string res = "010000";
        res = res + "0000000000";
        return res;
    }
};

class STOPInstruction : public Instruction {
public:
    STOPInstruction() = default;

    bool is_this(const string &line) override {
        vector<Operator> vals = parse(line);
        bool flag = vals.size() == 1
                    && vals[0].get_type() == STOP;
        return flag;
    }

    string process(const string &line) override {
        assert(is_this(line));
        vector<Operator> vals = parse(line);
        string res = "000000";
        res = res + "0000000000";
        return res;
    }
};

class DefaultInstruction : public Instruction {
public:
    DefaultInstruction() = default;

    bool is_this(const string &line) override {
        return true;
    }

    string process(const string &line) override {
        return "Default Instruction " + line;
    }
};

void process_assembly_code() {
    vector<Instruction *> instructions;
    instructions.push_back(new LDInstruction());
    instructions.push_back(new LDAInstruction());
    instructions.push_back(new LDCInstruction());
    instructions.push_back(new STInstruction());
    instructions.push_back(new MOVInstruction());
    instructions.push_back(new ADDInstruction());
    instructions.push_back(new SUBInstruction());
    instructions.push_back(new ASRInstruction());
    instructions.push_back(new ASLInstruction());
    instructions.push_back(new ORInstruction());
    instructions.push_back(new ANDInstruction());
    instructions.push_back(new XORInstruction());
    instructions.push_back(new LSLInstruction());
    instructions.push_back(new LSRInstruction());
    instructions.push_back(new CNDInstruction());
    instructions.push_back(new CBRInstruction());
    instructions.push_back(new NOPInstruction());
    instructions.push_back(new STOPInstruction());
    instructions.push_back(new DefaultInstruction());

    string line;
    while (getline(cin, line)) {
        for (Instruction *cur : instructions) {
            if (cur->is_this(line)) {
                string res = cur->process(line);

                cout << res << endl;
                break;
            }
        }
    }
}

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    process_assembly_code();

    return 0;
}