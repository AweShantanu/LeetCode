class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        int n=s.size();
        if(s[0]=='*')
        {
            return "";
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]=='*')
            {
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string se="";
        while(!st.empty())
        {
            se.push_back(st.top());
            st.pop();
        }
        reverse(se.begin(),se.end());
        return se;
    }
};