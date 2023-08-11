#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Horspool {
private:
    std::unordered_map<char, int> shiftTable;
    std::string pattern;

    void generateShiftTable() {
        int m = pattern.length();
        for (int i = 0; i < m - 1; ++i) {
            shiftTable[pattern[i]] = m - 1 - i;
        }
    }

public:
    Horspool(const std::string& pat) : pattern(pat) {
        generateShiftTable();
    }

    std::vector<int> search(const std::string& text) {
        std::vector<int> positions;
        int n = text.length();
        int m = pattern.length();
        int i = m - 1;

        while (i < n) {
            int k = 0;
            while (k < m && pattern[m - 1 - k] == text[i - k]) {
                ++k;
            }

            if (k == m) {
                positions.push_back(i - m + 1);
            }

            i += shiftTable[text[i]];
        }

        return positions;
    }
};

int main() {
    std::string text = "ABCDABCDABDE";
    std::string pattern = "AB";

    Horspool horspool(pattern);
    std::vector<int> positions = horspool.search(text);

    if (positions.empty()) {
        std::cout << "Pattern not found in the text." << std::endl;
    } else {
        std::cout << "Pattern found at positions:";
        for (int pos : positions) {
            std::cout << " " << pos;
        }
        std::cout << std::endl;
    }

    return 0;
}
