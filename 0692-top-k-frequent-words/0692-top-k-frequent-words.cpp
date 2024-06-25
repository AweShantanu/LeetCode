class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        
        // Count frequencies of each word
        for (auto &word : words)
            mp[word]++;
        
        // Store the frequency map in a vector of pairs
        vector<pair<string, int>> vec;
        for (auto &entry : mp) {
            vec.push_back({entry.first, entry.second});
        }
        
        // Lambda function for sorting
        auto lambda = [](pair<string, int>& P1, pair<string, int>& P2) {
            if (P1.second == P2.second)
                return P1.first < P2.first;
            return P1.second > P2.second;
        };
        
        // Sort the vector using the lambda function
        sort(vec.begin(), vec.end(), lambda);
        
        // Collect the top k frequent words
        vector<string> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(vec[i].first);
        }
        
        return result;
    }
};
