class Solution {
public:
    bool detectCapitalUse(string word) {
        int countCapitals=0;
        for(char &ch:word)
        {
            if(ch>='A' && ch<='Z')
                countCapitals++;
            
        }
        if(countCapitals==word.length() || countCapitals==0 || (countCapitals==1 && isupper(word[0])))
            return true;
        return false;
    }
    
};