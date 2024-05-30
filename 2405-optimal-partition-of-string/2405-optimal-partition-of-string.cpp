// class Solution {
// public:
//     int partitionString(string s) {
//         int n=s.length();
//         int count=0;
//         for(int i=0;i<n;i++)
//         {
//             unordered_map<char,bool> mp;
//             mp[s[i]]=true;
//             count++;
//             for(int j=i+1;j<n;j++)
//             {
//                 if(mp.find(s[i])!=mp.end())
//                 {
//                     i=j;
//                     break;
//                 }
//                 else{
//                     mp[s[j]]=true;
                    
//                 }
//             }
//         }
//         return count;
//     }
// };

#include <string>
#include <unordered_map>

class Solution {
public:
    int partitionString(std::string s) {
        int n = s.length();
        int count = 0;

        for (int i = 0; i < n;) {
            std::unordered_map<char, bool> mp;
            count++;
            for (int j = i; j < n; j++) {
                if (mp.find(s[j]) != mp.end()) {
                    i = j;
                    break;
                } else {
                    mp[s[j]] = true;
                    if (j == n - 1) {
                        i = n;  // End the outer loop if we reach the end of the string
                    }
                }
            }
        }
        return count;
    }
};
