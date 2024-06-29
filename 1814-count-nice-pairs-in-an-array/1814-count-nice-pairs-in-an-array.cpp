#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Function to reverse the digits of an integer
    int reverse(int n) {
        int ans = 0;
        while (n > 0) {
            int remainder = n % 10; // Get the last digit
            ans = (ans * 10) + remainder; // Add the last digit to the reversed number
            n = n / 10; // Remove the last digit from the original number
        }
        return ans;
    }

    // Function to count nice pairs
    int countNicePairs(vector<int>& nums) {
        int MOD = 1e9 + 7; // Define the modulo value to prevent overflow
        unordered_map<int, int> mp; // Map to store the frequency of (nums[i] - reverse(nums[i]))

        // Modify nums to store nums[i] - reverse(nums[i])
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] - reverse(nums[i]);
        }

        int res = 0; // Variable to store the result

        // Count nice pairs
        for (auto &i : nums) {
            res = (res + mp[i]) % MOD; // Add the frequency of the current value to the result
            mp[i]++; // Increment the frequency of the current value
        }

        return res;
    }
};
