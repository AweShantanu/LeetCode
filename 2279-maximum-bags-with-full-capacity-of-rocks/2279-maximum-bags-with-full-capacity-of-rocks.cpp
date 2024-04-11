class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int count=0;
        int n=rocks.size();
        vector<int> vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back(capacity[i]-rocks[i]);
        }
        sort(begin(vec),end(vec));
        for(int i=0;i<n;i++)
        {
            if(vec[i]==0)
                count++;
            else{
                if(additionalRocks>=vec[i])
                {
                    count++;
                    additionalRocks=additionalRocks-vec[i];
                    
                }
                else{
                    break;
                }
            }
        }
        return count;
        
    }
};