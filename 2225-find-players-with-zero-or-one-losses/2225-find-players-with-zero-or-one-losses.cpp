#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> win;
        vector<int> loss;
        vector<vector<int>> res;
        unordered_map<int, int> mp; // map to track losses

        // Track the number of losses for each player
        for (auto &match : matches) {
            mp[match[1]]++;
        }

        // Find players who never lost
        for (auto &match : matches) {
            if (mp.find(match[0]) == mp.end()) {
                win.push_back(match[0]);
                mp[match[0]] = 0; // to avoid adding the same player again
            }
        }

        // Find players who lost exactly once
        for (auto &entry : mp) {
            if (entry.second == 1) {
                loss.push_back(entry.first);
            }
        }

        // Sort the result vectors as required
        sort(win.begin(), win.end());
        sort(loss.begin(), loss.end());

        res.push_back(win);
        res.push_back(loss);
        return res;
    }
};
