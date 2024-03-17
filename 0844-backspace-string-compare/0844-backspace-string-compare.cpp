class Solution {
public:
    bool backspaceCompare(string s, string t) {
        //ham do string babake pop kar kar ke last mein compare kar lenge dono ko 
        // ya dusra method ye hai ki ham
        int i=s.length()-1;
        int j=t.length()-1;
        int skip1=0;
        int skip2=0;
        int n=s.length();
        int m=t.length();
        while(i>=0 || j>=0)
        {
            while(i>=0)
            {
                if(s[i]=='#')
                {
                    skip1=skip1+1;
                    i--;
                }
                else if(skip1>0){
                    skip1--;
                    i--;
                }
                else
                    break;
            }
            while(j>=0)
            {
                if(t[j]=='#')
                {
                    skip2=skip2+1;
                    j--;
                }
                else if(skip2>0){
                    skip2--;
                    j--;
                }
                else
                    break;
            }
            char first=(i<0)?'$':s[i];
            char second=(j<0)? '$':t[j];
        
            if(first != second)
                return false;
            i--;
            j--;
            
        }
        return true;
        
        
    }
};