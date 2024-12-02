#include <cassert>
#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

namespace {
// Returns index of first element in a pair that causes sequence to be unsafe
auto unsafeIndex(const std::vector<int>& level) -> std::optional<int> {
    if (level.size() <= 2) {
        return {};
    }
    bool is_inc = level[0] < level[1];
    for (int i = 1; i < level.size(); i++) {
        auto diff = is_inc ? level[i] - level[i - 1] : level[i - 1] - level[i];
        if (diff <= 0 || 3 < diff) {
            return i - 1;
        }
    }
    return {};
}

// Checks if a list is safe, relax with possibility to remove element
auto isDampSafe(const std::vector<int>& level) -> bool {
    auto unsafe_idx = unsafeIndex(level);
    if (unsafe_idx.has_value()) {
        int i = unsafe_idx.value();
        std::vector<int> level_remove_start{level};
        std::vector<int> level_remove_0{level};
        std::vector<int> level_remove_1{level};
        level_remove_start.erase(level_remove_start.begin());
        level_remove_0.erase(level_remove_0.begin() + i);
        level_remove_1.erase(level_remove_1.begin() + i + 1);
        if (unsafeIndex(level_remove_0) && unsafeIndex(level_remove_1) && unsafeIndex(level_remove_start)) {
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
        safe_count += static_cast<int>(!unsafeIndex(level).has_value());
        damp_safe_count += static_cast<int>(isDampSafe(level));
        level.clear();
    }

    input_file.close();

    std::cout << "Total safe levels: " << safe_count << '\n';
    std::cout << "Total damp safe levels: " << damp_safe_count << '\n';

    return 0;
}
