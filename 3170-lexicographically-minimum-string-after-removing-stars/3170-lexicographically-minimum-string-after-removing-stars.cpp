class Solution {
public:
    typedef pair<int,int> P;
    struct comp{
        bool operator()(P &p1, P &p2)
        {
            if(p1.first==p2.first)
            {
                return p2.second > p1.second;
            }
            
        return p1.first> p2.first;
        }
    };
    
    string clearStars(string s) {
        int n=s.size();
        priority_queue<P,vector<P> , comp> pq;
        for(int i=0;i<n;i++)
        {
            if(s[i]!='*')
            {
                pq.push({s[i],i});
            }
            else{
                int idx=pq.top().second;
                pq.pop();
                s[idx]='*';
                
            }
        }
        string res="";
        for(int i=0;i<n;i++)
        {
            if(s[i]!='*')
                res.push_back(s[i]);
        }
        return res;
    }
};