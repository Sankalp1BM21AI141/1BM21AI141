#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int ALPHABET_SIZE = 256;
class hars{
    public:
    string text = "BMS college of engineering";
    string pattern = "college";
    void precomputeBadCharacterTable(const string& pattern, vector<int>& badCharTable);
    int horspoolSearch(const string& text, const string& pattern);
    
    
    
}ha;

// Preprocess the pattern and create the bad character table
void hars:: precomputeBadCharacterTable(const string& pattern, vector<int>& badCharTable) {
    int patternLength = pattern.length();
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        badCharTable[i] = patternLength; // Initialize with the pattern length as default value
    }
    for (int i = 0; i < patternLength - 1; i++) {
        badCharTable[pattern[i]] = patternLength - 1 - i;
    }
}

// Horspool string searching algorithm
int hars:: horspoolSearch(const string& text, const string& pattern) {
    int textLength = text.length();
    int patternLength = pattern.length();
    if (patternLength > textLength) {
        return -1; // Pattern is longer than the text, no match possible
    }

    vector<int> badCharTable(ALPHABET_SIZE);
    precomputeBadCharacterTable(pattern, badCharTable);

    int i = patternLength - 1; // Start from the rightmost character of the pattern
    while (i < textLength) {
        int j = 0;
        while (j < patternLength && text[i - j] == pattern[patternLength - 1 - j]) {
            j++;
        }
        if (j == patternLength) {
            return i - patternLength + 1; // Pattern found at position i - patternLength + 1
        }
        i += badCharTable[text[i]];
    }

    return -1; // Pattern not found in the text
}

int main() {
    

    int result = ha.horspoolSearch(ha.text, ha.pattern);

    if (result != -1) {
        cout << "Pattern found at position " << result << endl;
    } else {
        cout << "Pattern not found in the text." << endl;
    }

    return 0;
}
