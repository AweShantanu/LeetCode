class Solution {
public:
//     int strStr(string haystack, string needle) {
//         int found=haystack.find(needle);
//         if(found == string::npos)
//         {
//         return -1;

//         }
//         else{
//             return found;
//          }
        
//     }
    int strStr(string haystack, string needle)
    {
        
        for(int i=0;i<haystack.length();i++)
        {
            for(int j=i; j<haystack.size();j++)
            {

                string t=haystack.substr(i,j-i+1);
                if(t==needle){
                    return i;
                }

            
            }
        }
        return -1;
    }
};
