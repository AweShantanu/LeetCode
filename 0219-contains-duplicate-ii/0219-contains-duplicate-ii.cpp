#include <vector>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j <= i + k && j < n; ++j) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};
