class Solution {
public:
    int n;
    int result = INT_MAX;
    void solve(int idx,vector<int>& cookies,vector<int> &stud, int k)
    {
        if(idx>=n)
        {
            int maxChild=*max_element(begin(stud),end(stud));
            result=min(result,maxChild);
            return;
        }
        int cooki=cookies[idx];
        for(int i=0;i<k;i++)
        {
            stud[i]+=cooki;
            solve(idx+1,cookies,stud,k);
            stud[i]-=cooki;
            
        }
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        n=cookies.size();
        vector<int> stud(k,0);
        solve(0,cookies,stud,k);
        return result;
        
    }
};