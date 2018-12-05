#include <utility>
#include <iostream>
#include <fstream>
#include "process.h"

int main() {
    std::ifstream ifs("../input.txt");
    std::ofstream ofs("../output.txt", std::ios::out | std::ios::binary);
    ofs << process_assembly_code(ifs);
    return 0;
}