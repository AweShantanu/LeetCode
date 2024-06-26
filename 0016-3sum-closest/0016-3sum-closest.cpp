class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());  // Sort the array
        int closest = INT_MAX / 2;  // Initialize closest to a very large value

        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(target - sum) < abs(target - closest)) {
                    closest = sum;  // Update closest if this sum is closer to target
                }
                if (sum < target) {
                    ++left;  // Move left pointer to the right
                } else {
                    --right;  // Move right pointer to the left
                }
            }
        }

        return closest;
    }
};
