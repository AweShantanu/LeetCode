class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0;i<stones.size();i++)
        {
            pq.push(stones[i]);  //log(n)
        }
        while(pq.size()>1)
        {
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            if(a!=b)
            {
                pq.push(abs(a-b));
            }
        }
        if(pq.size()==1)
            return pq.top();
        else if(pq.size()==0)
            return 0;
        else{
            return pq.top();
        }
        
    }
};