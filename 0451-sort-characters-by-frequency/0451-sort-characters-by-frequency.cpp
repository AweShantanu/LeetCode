class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;  // Map to store the frequency of each character
        
        // Count the frequency of each character in the input string
        for (auto &i : s) {
            mp[i]++;
        }

        vector<pair<char, int>> vec;  // Vector to store the characters and their frequencies
        
        // Move the character-frequency pairs from the map to the vector
        for (auto &u : mp) {
            vec.push_back({u.first, u.second});
        }

        // Lambda function to sort by frequency (descending), and then by character (ascending)
        auto lambda = [](pair<char, int>& P1, pair<char, int>& P2) {
            if (P1.second == P2.second)
                return P1.first < P2.first;
            return P1.second > P2.second;
        };

        // Sort the vector using the defined lambda function
        sort(vec.begin(), vec.end(), lambda);

        string result;  // String to store the final sorted characters
        
        // Append each character to the result string based on its frequency
        for (auto &o : vec) {
            result.append(o.second, o.first);  // Append 'o.second' instances of 'o.first'
        }

        // Return the result string
        return result;
    }
};
