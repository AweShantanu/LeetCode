class Solution {
public:
    vector<int> asteroidCollision(vector<int>& num) {
        int n=num.size();
        stack<int> st;
    
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && num[i]<0 && st.top()>0)
            {
                int s=num[i]+st.top();
                if(s<0)
                    st.pop();
                else if(s>0)
                    num[i]=0;
                else if(s==0)
                {
                    num[i]=0;
                    st.pop();
                }
                
            }
            if(num[i]!=0)
                st.push(num[i]);
            
        }
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};