class Solution {
public:
    int hammingWeight(int n) {
        int count =0;
        while(n!=0)
        {
            n=(n&(n-1));  //ye process se right most bit joo 1 hota hai usko 0 bana deta hai
            count++;
        }
        return count;
    }
};