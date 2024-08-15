class Solution {
public:
    string rot(string s, int k) {
        string sd = s.substr(0, k);  // Extract the first k characters
        s = s.substr(k);             // Get the rest of the string after the first k characters
        return s + sd;               // Concatenate the two parts
    }

    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;  // If lengths are not equal, goal can't be a rotation
        }

        string ans;
        for (int i = 0; i < s.length(); i++) {
            ans = rot(s, i);  // Rotate the string by i positions
            if (ans == goal) {
                return true;  // If the rotated string matches the goal, return true
            }
        }

        return false;  // If no rotation matches, return false
    }
};
