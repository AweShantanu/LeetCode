class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int golaIndex=-1;
        int n=arr.size();
        for(int i=n-1;i>0;i--)
        {
            if(arr[i-1]<arr[i])
            {
                golaIndex=i-1;
                break;
            }
        }
        int swapIndex=golaIndex;
     
        if(golaIndex!=-1)
        {

            for(int i=n-1;i>=golaIndex+1;i--)
            {
                if(arr[i]>arr[golaIndex])
                {
                    swapIndex=i;
                    break;
                }
            }
            swap(arr[golaIndex],arr[swapIndex]);
        }
        
        reverse(arr.begin()+golaIndex+1,arr.end());
        
    }
};