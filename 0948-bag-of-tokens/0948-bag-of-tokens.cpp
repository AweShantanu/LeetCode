class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        int score=0;
        int maxScore=0;
        int i=0;
        int j=n-1;
        sort(begin(tokens),end(tokens));
    
         while(i<=j)
        {
            if(power>=tokens[i])
            {
                power=power-tokens[i];
                score++;
                i++;
                maxScore=max(maxScore,score);
            }
            else if(score>=1)
            {
                power=power+tokens[j];
                score-=1;
                j--;
                
            }
             else{
                 return maxScore;
             }
            
        }
        return maxScore;
    }
};