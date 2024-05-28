class Solution {
public:
    stack<pair<int ,int>> st;
    vector<int> dailyTemperatures(vector<int>& t) {
        reverse(t.begin(),t.end());
        vector<int> ans;
        for(int i=0;i<t.size();i++)
        {
            int span=0;
            while(!st.empty())
            {
                if(st.top().first <= t[i])
                {
                    span=span+st.top().second;
                    st.pop();
                    if(st.empty()==true)
                    {
                        span=0;
                        break;
                    }
                }
                else{
                    span=span+1;
                    break;
                    
                }
               
            }
            st.push({t[i],span});
            ans.push_back(span);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
        
        
    }
};