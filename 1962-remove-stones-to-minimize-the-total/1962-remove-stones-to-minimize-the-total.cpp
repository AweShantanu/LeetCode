class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n=piles.size();
        priority_queue<int> pq;
        for(int i=0;i<n;i++)
        {
            pq.push(piles[i]);
        }
        int sum =0;
        while(k>0)
        {
            int a=pq.top();
            pq.pop();
            a=a-a/2;
            pq.push(a);
            k--;
        }
        while(pq.size()!=0)
        {
            sum=sum+pq.top();
            pq.pop();
            
        }
        return sum;
        
    }
};