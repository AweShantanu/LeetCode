class Solution {
public:
    string simplifyPath(string path) {
        string token="";
        stringstream ss(path);
        stack<string> st;
        
        while(getline(ss,token,'/'))
        {
            if(token=="" || token==".")
                continue;
            if(token!="..")
                st.push(token);
            if(token=="..")
            {
                if(st.empty())
                    continue;
                else
                    st.pop();
            }
            
            
        }
        if(st.empty())
        {
            return"/";
            
        }
        string res="";
        while(!st.empty())
        {
            res="/"+st.top()+res;
            st.pop();
        }
        return res;
    }
};