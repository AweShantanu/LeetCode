class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open=0;
        int n=s.size();
        string res="";
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                
                open++;
                res.push_back(s[i]);
            }
            else if(s[i]==')')
            {
                if(open>0)
                {
                    open--;
                res.push_back(s[i]);
                }
                
            }
            else{
                res.push_back(s[i]);
            }
        }
        //ab ham ye dekh rahe hain ki agar open ka count kuch bhi bacha hai to ham ab wo extra open bracket ko nikalenge 
        string result="";
        int m=res.size();
        for(int i=m-1;i>=0;i--)
        {
            if(res[i]=='(' && open >0)
            {
                open--;
                
            }
            else{
                result.push_back(res[i]);
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};