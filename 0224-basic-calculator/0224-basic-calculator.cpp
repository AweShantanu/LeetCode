class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int len=s.length();
        int num=0;
        int sign=1;
        int res=0;
        for(int i=0;i<len;i++)
        {
            if(isdigit(s[i]))
            {
                num=(num*10) + (s[i]-'0');
            }
            else if(s[i]=='+')
            {
                res=res + (num*sign);
                sign=1;
                num=0;
                
            }
            else if(s[i]=='-')
                
            {
                res=res+(num*sign);
                sign=-1;
                num=0;
                
            }
            else if(s[i]=='(')
            {
                st.push(res);
                st.push(sign);
                sign=1;
                res=0;
                num=0;
            }
            else if(s[i]==')')
            {
                res=res+(num*sign);
                num=0;
                int stSign=st.top(); st.pop();
                int stRes=st.top(); st.pop();
                res=res*stSign;
                res=res+stRes;
                
            }
            
        }
        res=res+(num*sign);
        return res;
        
    }
};