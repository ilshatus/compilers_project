#include <utility>
#include <iostream>
#include <bits/stdc++.h>
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

using namespace std;

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