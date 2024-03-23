class Solution {
public:
    bool isVowel(char ch)
    {
        if(ch=='a'|| ch=='e'|| ch=='i'|| ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
            return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        int n=s.length();
        int mid=n/2;
        int i=0;
        int j=mid;
        int countL=0;
        int countR=0;
        while(i<mid && j<n)
        {
            if(isVowel(s[i]))
                countL++;
            if(isVowel(s[j]))
                countR++;
            i++;
            j++;
        }
        return countL==countR;
    }
};