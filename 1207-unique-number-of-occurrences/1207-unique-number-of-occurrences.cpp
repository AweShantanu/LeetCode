class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int num=0;
        vector<int> ans;
        for(int i=0; i< arr.size(); i++)
        {
            if(i==arr.size()-1)
            {
                ans.push_back(num+1);
                continue;
            }
            if(arr[i]==arr[i+1])
            {
                num++;
            }
            else{
                ans.push_back(num+1);
                num=0;
            }
                
        }
        sort(ans.begin(),ans.end());
        for(int j=0;j<ans.size()-1;j++)
        {
            if(ans[j]==ans[j+1])
            {
                return false;
            }
        }
        return true;
            
        
        
    }
};