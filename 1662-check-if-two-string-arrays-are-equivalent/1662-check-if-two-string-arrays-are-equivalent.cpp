class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n=word1.size();
        int m=word2.size();
        int wrd1=0;
        int wrd2=0;
        int i=0;
        int j=0;
        while(wrd1<n && wrd2<m)
        {
            if(word1[wrd1][i]!=word2[wrd2][j])
            {
                return false;
            }
            i++;
            j++;
            if(i==word1[wrd1].length())
            {
                i=0;
                wrd1++;
            }
            if(j==word2[wrd2].length())
            {
                j=0;
                wrd2++;
            }
        }
        if(wrd1==n && wrd2==m)
            return true;
        return false;
    }
};