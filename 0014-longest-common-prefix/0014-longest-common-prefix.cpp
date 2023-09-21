// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         int l=strs[0].length();
//         string s="";
//         char ch;
//         if(strs.size() == 0 || strs[0] == "") return s;
//         if(strs.size() == 1) return strs[0];
//         for(int i=0; i<l;i++)
//        {
//             ch=strs[0][i];
//             if(strs[1][i]== ch && strs[2][i]==  ch)
//             {
//                 s.push_back(ch);
//             }
//             else{
//                 break;
//             }
            
//         }
//         return s;
//     }
// };
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";

        if(strs.size() == 0 || strs[0] == "") return result;

        if(strs.size() == 1) return strs[0];

        int i=0;

        while(i < strs[0].length()) {
            int j=0;

            while(j < strs.size()) {
                if(strs[0][i] != strs[j][i]) {
                    return result;
                }
                j++;
            }

            result.push_back(strs[0][i]);
            i++;
        }
        
        return result;
    }
};