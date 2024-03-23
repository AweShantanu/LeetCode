// class Solution {
// public:
//     string orderlyQueue(string s, int k) {
//         if(k>1)
//         {
//             sort(begin(s),end(s));
//             return s;
//         }
//         string str=s;
//         int n=s.length();
//         for(int i=1;i<n-1;i++)
//         {
//             string temp=s.substr(i)+s.substr(0,i);
//             str=min(str,temp);
//         }
//         return str;
            
//     }
// };

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1) {
            sort(begin(s), end(s));
            return s;
        }
        
        string str = s;
        int n = s.length();
        
        // Consider the original string as well (cyclic shift by 0)
        for (int i = 1; i < n; ++i) {
            string temp = s.substr(i) + s.substr(0, i);
            str = min(str, temp);
        }
        
        return str;
    }
};
