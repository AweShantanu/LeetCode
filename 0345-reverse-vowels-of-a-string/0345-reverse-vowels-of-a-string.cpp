class Solution {
public:
    bool isVowel(char ch)
        {
            ch= tolower(ch);
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            {
                return true;
            }
            else{
                return false;
            }
        }
    string reverseVowels(string s) {
        
        int low=0;
        int high=s.length()-1;
        while(low<high)
        {
            if(isVowel(s[low]) && isVowel(s[high]))
            {
                swap(s[low],s[high]);
                low++;
                high--;
            }
            else if(!isVowel(s[low]))
            {
                low++;
            }
            else{
                high--;
            }
            
        }
        return s;
        
    }
};