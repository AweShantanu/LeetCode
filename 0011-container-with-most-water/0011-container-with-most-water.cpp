class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int l = 0;
        int r = n - 1;
        
        int maxArea = 0;
        
        while (l < r) {
            int height = min(arr[l], arr[r]);
            int width = r - l;
            int currArea = height * width;
            maxArea = max(currArea, maxArea);
            
            if (arr[l] < arr[r]) {
                l++;
            } else {
                r--;
            }
        }
        
        return maxArea;
    }
};
