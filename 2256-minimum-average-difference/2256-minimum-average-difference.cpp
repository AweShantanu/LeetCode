#include <vector>
#include <cmath>
#include <climits>

class Solution {
public:
    int minimumAverageDifference(std::vector<int>& nums) {
        long long lSum = 0;
        long long rSum=0;
        int n = nums.size();
        long long totalSum = 0;
        int mini = INT_MAX;
        int resultIndex = -1;
        
        for (int i = 0; i < n; ++i) {
            totalSum += nums[i];
        }
        
        for (int i = 0; i < n; ++i) {
            lSum += nums[i];
            int nl = i + 1;
            rSum = totalSum - lSum;
            int nr = n - nl;
            
            long long avgl = lSum / nl;
            long long avgr = (nr == 0) ? 0 : rSum / nr;
            
            int abso = std::abs(avgl - avgr);
            
            if (abso < mini) {
                mini = abso;
                resultIndex = i;
            }
        }
        
        return resultIndex;
    }
};
