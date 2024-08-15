/*

    Time Complexity : O(1), The maximum length of the string(s) can be 15 (as per the Constgraint), therefore, the
    worst case time complexity can be O(15) or O(1).

    Space Complexity : O(1), We are using unordered_map(map) to store the Roman symbols and their corresponding
    integer values but there are only 7 symbols hence the worst case space complexity can be O(7) which is
    equivalent to O(1).

    Solved using String + Hash Table + Math.

*/

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map;

        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;
        
        int ans = 0;
        
        for(int i=0; i<s.length(); i++){
            if(map[s[i]] < map[s[i+1]]){
                ans -= map[s[i]];
            }
            else{
                ans += map[s[i]];
            }
        }
        return ans;
    }
};