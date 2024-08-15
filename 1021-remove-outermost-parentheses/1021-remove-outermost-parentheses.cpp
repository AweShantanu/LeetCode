class Solution {
public:
    string removeOuterParentheses(string s) {
        int open =0;
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            
            if(s[i]=='(')
            {
                if(open==0)
                {
                    open++;
                    continue;
                }
                else{
                    open++;
                    ans+='(';
                }
            }
            else
            {
                open--;
                if(open==0)
                    continue;
                else{
                    ans+=')';
                }
                
          
            }
        }
        return ans;
    }
};