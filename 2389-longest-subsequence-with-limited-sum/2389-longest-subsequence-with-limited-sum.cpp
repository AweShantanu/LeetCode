class Solution {
public:
    vector<int> ans;
    int binarySearch(vector<int> cumSum,int target,int n)
    {
        int l=0;int r=n-1;
        int resIndex=-1;
        int mid;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(cumSum[mid]<=target)
            {
                 resIndex=mid;
                l=mid+1;
            }   
            else{
                r=mid-1;
            }
            
            
        }
        return resIndex+1;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
    
        int m=queries.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
            nums[i]=sum;
            
        }
        for(int i=0;i<m;i++)
        {
            int k= binarySearch(nums,queries[i],n);
            ans.push_back(k);
        }
        return ans;
        
        
    }
};