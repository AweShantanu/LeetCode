class Solution {
public:
    bool isART(vector<int>& arr)
    {
        sort(begin(arr),end(arr));
        int n=arr.size();
        int d=arr[1]-arr[0];
        for(int i=2;i<n;i++)
        {
            if(arr[i]-arr[i-1]!= d)
                return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n= l.size();
        vector<int> ans;
        vector<bool> res;
        for(int i=0;i<n;i++)
        {
        
            for(int j=l[i];j<=r[i];j++)
            {
                ans.push_back(nums[j]);
            }
            
            bool isArthimatic=isART(ans);
            res.push_back(isArthimatic);
            ans.clear();
        }
        return res;
        
    }
};