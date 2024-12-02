#include <cassert>
#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

namespace {
auto isSafe(const std::vector<int>& level) -> bool {
    if (level.size() <= 2) {
        return true;
    }
    if (level[0] == level[1]) {
        return false;
    }
    bool is_inc = false;
    if (level[0] < level[1]) {
        is_inc = true;
    }

    for (int i = 1; i < level.size(); i++) {
        auto diff = level[i] - level[i - 1];
        if (is_inc) {
            if (diff <= 0 || diff > 3) {
                return false;
            }
        } else {
            if (diff >= 0 || diff < -3) {
                return false;
            }
        }
    }
    return true;
}

auto unsafeIndex(const std::vector<int>& level) -> std::optional<int> {
    if (level.size() <= 2) {
        return {};
    }
    if (level[0] == level[1]) {
        return 0;
    }
    bool is_inc = false;
    if (level[0] < level[1]) {
        is_inc = true;
    }

    for (int i = 1; i < level.size(); i++) {
        auto diff = level[i] - level[i - 1];
        if (is_inc) {
            if (diff <= 0 || diff > 3) {
                return i - 1;
            }
        } else {
            if (diff >= 0 || diff < -3) {
                return i - 1;
            }
        }
    }
    return {};
}

auto isDampSafe(const std::vector<int>& level) -> bool {
    auto unsafe_idx = unsafeIndex(level);
    if (unsafe_idx.has_value()) {
        int i = unsafe_idx.value();
        std::vector<int> level_remove_0{level};
        std::vector<int> level_remove_1{level};
        std::vector<int> level_remove_start{level};
        level_remove_0.erase(level_remove_0.begin() + i);
        level_remove_1.erase(level_remove_1.begin() + i + 1);
        level_remove_start.erase(level_remove_start.begin());
        if (!isSafe(level_remove_0) && !isSafe(level_remove_1) && !isSafe(level_remove_start)) {
            return false;
        }
    }
    return true;
}

} // namespace

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

    std::vector<int> level{};
    int safe_count = 0;
    int damp_safe_count = 0;
    std::string line;
    while (std::getline(input_file, line)) {
        std::istringstream os(line);
        int i{};

        while (os >> i) {
            level.push_back(i);
        }
        safe_count += static_cast<int>(isSafe(level));
        damp_safe_count += static_cast<int>(isDampSafe(level));
        level.clear();
    }

    input_file.close();

    std::cout << "Total safe levels: " << safe_count << '\n';
    std::cout << "Total damp safe levels: " << damp_safe_count << '\n';

    return 0;
}
