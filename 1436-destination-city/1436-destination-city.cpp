class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> mp;

        // Build the map with source as key and destination as value
        for (auto &i : paths) {
            mp[i[0]] = i[1];
        }

        // Iterate over the paths to find the destination city
        for (auto &i : paths) {
            string s = i[1];
            if (mp.find(s) == mp.end()) {
                return s;
            }
        }

        return ""; // In case there is no destination city found
    }
};
