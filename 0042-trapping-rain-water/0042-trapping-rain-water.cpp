class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        
        vector<int> left(n);
        vector<int> right(n);
        
        // Initialize the left and right arrays
        left[0] = height[0];
        right[n-1] = height[n-1];
        
        // Fill the left array with the maximum heights from the left
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i-1], height[i]);
        }
        
        // Fill the right array with the maximum heights from the right
        for (int i = n-2; i >= 0; i--) {
            right[i] = max(right[i+1], height[i]);
        }
        
        // Calculate the trapped water
        int area = 0;
        for (int i = 0; i < n; i++) {
            area += min(left[i], right[i]) - height[i];
        }
        
        return area;
    }
};
