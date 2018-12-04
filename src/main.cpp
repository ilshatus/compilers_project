#include <utility>
#include <iostream>
#include <fstream>
#include "process.h"

int main() {
    std::ifstream ifs("../input.txt");
    std::ofstream ofs("../output.txt");

    ofs << process_assembly_code(ifs);
    return 0;
}