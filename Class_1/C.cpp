#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using Pattern = std::deque<std::string>;

void remove_consecutive_duplicates(Pattern& lines) {
    lines.erase(std::unique(lines.begin(), lines.end()), lines.end());
}

void remove_identical_columns(Pattern& lines) {
    size_t col = 0;
    while (col + 1 < lines.front().size()) {
        bool identical = true;
        for (const auto& line : lines) {
            if (line[col] != line[col + 1]) {
                identical = false;
                break;
            }
        }
        if (identical) {
            for (auto& line : lines) {
                line.erase(line.begin() + col);
            }
        } else {
            ++col;
        }
    }
}

void trim_empty_edges(Pattern& lines) {
    auto is_empty_line = [](const std::string& line) {
        return std::all_of(line.begin(), line.end(), [](char ch) { return ch == '.'; });
    };
    while (!lines.empty() && is_empty_line(lines.front())) lines.pop_front();
    while (!lines.empty() && is_empty_line(lines.back())) lines.pop_back();

    while (!lines.empty() && !lines.front().empty() &&
           std::all_of(lines.begin(), lines.end(), [](const std::string& line) { return line.front() == '.'; })) {
        for (auto& line : lines) line.erase(line.begin());
    }
    while (!lines.empty() && !lines.front().empty() &&
           std::all_of(lines.begin(), lines.end(), [](const std::string& line) { return line.back() == '.'; })) {
        for (auto& line : lines) line.pop_back();
    }
}

std::string identify_character(const Pattern& lines) {
    const std::map<Pattern, std::string> letters = {
            {{"#"}, "I"},
            {{"###", "#.#", "###"}, "O"},
            {{"##", "#.", "##"}, "C"},
            {{"#.", "##"}, "L"},
            {{"#.#", "###", "#.#"}, "H"},
            {{"###", "#.#", "###", "#.."}, "P"}
    };
    if (auto it = letters.find(lines); it != letters.end()) {
        return it->second;
    }
    return "X";
}

int main() {
    int n;
    std::cin >> n;
    Pattern lines(n);
    for (auto& line : lines) {
        std::cin >> line;
    }

    remove_consecutive_duplicates(lines);
    remove_identical_columns(lines);
    trim_empty_edges(lines);

    std::cout << identify_character(lines);
    return 0;
}
