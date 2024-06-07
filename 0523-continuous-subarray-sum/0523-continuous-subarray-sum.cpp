#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remainder_map; // Map to store the remainder and its index
        remainder_map[0] = -1; // To handle the case where a subarray from the start has a sum which is multiple of k
        int prefix_sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            prefix_sum += nums[i];
            int remainder = prefix_sum % k;
            
            if (remainder_map.find(remainder) != remainder_map.end()) {
                if (i - remainder_map[remainder] > 1) {
                    return true; // Found a subarray with length at least 2 and sum is multiple of k
                }
            } else {
                remainder_map[remainder] = i; // Store the remainder and index
            }
        }
        
        return false; // No such subarray found
    }
};
