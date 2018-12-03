#include <utility>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include "instructions/Instruction.h"
#include "instructions/LDInstruction.h"
#include "instructions/LDAInstruction.h"
#include "instructions/STInstruction.h"
#include "instructions/LDCInstruction.h"
#include "instructions/MOVInstruction.h"
#include "instructions/ADDInstruction.h"
#include "instructions/SUBInstruction.h"
#include "instructions/ASRInstruction.h"
#include "instructions/ASLInstruction.h"
#include "instructions/ORInstruction.h"
#include "instructions/ANDInstruction.h"
#include "instructions/XORInstruction.h"
#include "instructions/LSLInstruction.h"
#include "instructions/LSRInstruction.h"
#include "instructions/CNDInstruction.h"
#include "instructions/CBRInstruction.h"
#include "instructions/NOPInstruction.h"
#include "instructions/STOPInstruction.h"
#include "instructions/DefaultInstruction.h"
#include "instructions/DataInstruction.h"

using namespace std;

bool is_label(const string &line) {
    if (line.length() == 0)
        return false;
    bool flag = line[0] == '<' && line.length() > 2;
    for (int i = 1; i < line.length() - 1; i++) {
        flag = flag
               && ((line[i] >= 'a' && line[i] <= 'z')
                   || (line[i] >= 'A' && line[i] <= 'Z'));
    }
    return flag && line.back() == '>';
}

void add_instructions(vector<Instruction *> &instructions, unordered_map<string, int> &labels) {
    instructions.push_back(new LDCInstruction(labels));
    instructions.push_back(new LDInstruction());
    instructions.push_back(new LDAInstruction());
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
}

void process_assembly_code(ofstream *out) {
    vector<Instruction *> instructions;
    vector<string> result_instructions;
    unordered_map<string, int> labels;

    vector<string> lines;
    string tmp_line;
    while (getline(cin, tmp_line)) {
        lines.push_back(tmp_line);
    }

    vector<string> code_lines;
    unordered_map<string, int> jmp_labels;
    auto data_instruction = new DataInstruction();
    int curr_code_line = 0;
    for (int i = 0; i < lines.size(); i++) {
        if (is_label(lines[i])) {
            string label = lines[i].substr(1, lines[i].length() - 2);
            i++;
            if (i != lines.size() && data_instruction->is_this(lines[i])) {
                labels[label] = (int) result_instructions.size();
                while (i < lines.size() && data_instruction->is_this(lines[i])) {
                    vector<string> tmp = data_instruction->process_to_vector(lines[i]);
                    result_instructions.insert(result_instructions.end(), tmp.begin(), tmp.end());
                    i++;
                }
            } else {
                jmp_labels[label] = curr_code_line;
            }
            i--;
        } else {
            curr_code_line++;
            code_lines.push_back(lines[i]);
        }
    }

    code_lines.emplace_back("stop");

    unsigned int data_length = result_instructions.size();

    for (auto &jmp_label : jmp_labels) {
        labels[jmp_label.first] = jmp_label.second + (int) result_instructions.size();
    }

    add_instructions(instructions, labels);

    for (string &code_line : code_lines) {
        for (Instruction *cur : instructions) {
            try {
                if (cur->is_this(code_line)) {
                    result_instructions.push_back(cur->process(code_line));
                    break;
                }
            } catch (string &str) {
                *out << str;
                exit(0);
            }
        }
    }

    unsigned char version = 0;
    unsigned char padding = 0;
    *out << version << padding;
    *out << (unsigned char)((data_length >> 11) & 15);
    *out << (unsigned char)((data_length >> 7) & 15);
    *out << (unsigned char)((data_length >> 3) & 15);
    *out << (unsigned char)((data_length << 1) & 15);

    for (string &result_instruction : result_instructions) {
        unsigned char tmp = 0;
        for (int i = 0; i < result_instruction.length(); i++) {
            if (i % 8 == 0) {
                if (i) *out << tmp;
                tmp = 0;
            }
            int bit = 7 - i % 8;
            tmp |= (result_instruction[i] == '1') << bit;
        }
        *out << tmp;
    }
}

int main() {
    freopen("../input.txt", "r", stdin);
    ofstream out ("../output.txt", ios::out | ios::binary);

    process_assembly_code(&out);

    return 0;
}