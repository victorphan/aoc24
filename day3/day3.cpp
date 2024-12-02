#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

auto main(int argc, char* argv[]) -> int {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << '\n';
        return 1;
    }

    std::ifstream input_file(argv[1]);
    if (!input_file) {
        std::cerr << "Error opening file!" << '\n';
        return 1;
    }

    std::string line;
    while (std::getline(input_file, line)) {
        std::istringstream os(line);
        int i{};

        while (os >> i) {
        }
    }

    input_file.close();
    return 0;
}
