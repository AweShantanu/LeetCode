class Solution {
public:
    int myAtoi(string s) {
        int num=0;
        int i=0;
        int sign=1;
        int count=0;
        while(s[i]==' ')
        {
            i++;
        }
        
        while(i<s.size() && (s[i]=='-' || s[i]=='+'))
        {
             sign = s[i]=='-' ? -1: 1;
             i++;
             count ++;
            if(count>1)
                return 0;
             
        }

        while(i<s.size() && isdigit(s[i])){
            if(num>(INT_MAX/10) || (num==INT_MAX/10 && s[i]>'7') )
            { 
                return sign== -1? INT_MIN : INT_MAX;
            }
            num=num*10 + (s[i] -'0');
            ++i;
        }
        return num*sign;
    }
};