class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int count=0;
        sort(costs.begin(),costs.end());
        int n=costs.size();
        
        for(int i=0;i<n;i++)
        {
            if(coins>0 && costs[i]<=coins)
            {
                count++;
                coins=coins-costs[i];
            }
        }
        return count;
    }
};