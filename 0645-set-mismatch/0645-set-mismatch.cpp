#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> countMap; // To store the frequency of each number
        vector<int> rec(2, 0); // To store the result [duplicate, missing]
        
        // Fill the map with counts of each number
        for (int num : nums) {
            countMap[num]++;
        }
        
        // Find the duplicate and missing number
        for (int i = 1; i <= n; i++) {
            if (countMap[i] == 2) {
                rec[0] = i; // Duplicate number
            } else if (countMap[i] == 0) {
                rec[1] = i; // Missing number
            }
        }
        
        return rec;
    }
};
