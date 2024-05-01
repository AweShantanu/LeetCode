class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int l = 0;
        int h = n - 1;
        
        int maxArea = 0;
        
        while (l < h) {
            int height = min(arr[l], arr[h]);
            int width = h - l;
            int currArea = height * width;
            maxArea = max(currArea, maxArea);
            
            if (arr[l] < arr[h]) {
                l++;
            } else {
                h--;
            }
        }
        
        return maxArea;
    }
};
