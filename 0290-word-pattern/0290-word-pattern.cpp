#include <unordered_map>
#include <sstream>
#include <vector>
#include <string>

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;  // Map to track pattern character to word mapping

        // Split the string s into words
        vector<string> words = splitString(s);

        // Check if the pattern and words list have the same length
        if (pattern.size() != words.size()) {
            return false;
        }

        // Iterate through the pattern and words
        for (int i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];
            string w = words[i];

            // Check the mapping from character to word
            if (mp.find(c) != mp.end()) {
                if (mp[c] != w) {
                    return false;
                }
            } else {
                // Check if the word is already mapped to another character
                for (const auto& pair : mp) {
                    if (pair.second == w) {
                        return false;
                    }
                }
                mp[c] = w;
            }
        }

        return true;
    }

private:
    vector<string> splitString(const string& s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        return words;
    }
};
