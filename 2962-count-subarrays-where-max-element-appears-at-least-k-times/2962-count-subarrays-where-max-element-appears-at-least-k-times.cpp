class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int largest = INT_MIN;
        for (int i = 0; i < n; i++) {
            largest = max(largest, nums[i]);
        }
        
        int j = 0;
        int i = 0;
        long long total = 0; // Change to long long to handle large numbers
        int count = 0;
        
        while (j < n) {
            if (nums[j] == largest) {
                count++;
                if (count < k) {
                    j++;
                    continue;
                } else {
                    total += 1 + (n - j - 1);
                    while (count >= k) {
                        if (nums[i] == largest) {
                            count--;
                        }
                        i++;
                        if (count >= k) {
                            total += 1 + (n - j - 1);
                        }
                    }
                }
            }
            j++;
        }
        return total;
    }
};
