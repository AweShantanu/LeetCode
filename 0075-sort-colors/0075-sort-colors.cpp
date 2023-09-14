// class Solution {
// public:
//     void sortColors(vector<int>& arr) {
//         int n=arr.size();
//         int c0=0,c1=0,c2=0;
//         for(int i=0;i<n;i++){
//             c0+=(arr[i]==0);
//             c1+=(arr[i]==1);
//             c2+=(arr[i]==2);
//         }
//         cout<<c0<<" "<<c0<<" "<<c2;
//         for(int i=0;i<n;i++){
//             if(c0>0)arr[i]=0,c0--;
//             else if(c1>0)arr[i]=1,c1--;
//             else arr[i]=2;
//         }
//     }
// };

//three pointers approach se bhi karna hai
class Solution{
public:
    void sortColors(vector<int>& arr)
    {
        int s=0;
        int e=arr.size()-1;
        int mid=0;
        while(mid<=e)
        {
            
            if(arr[mid]==0)
            {
                swap(arr[s],arr[mid]);
                s++;
                mid++;   
            }
            else if(arr[mid]==1)
            {
                mid++;
            }
            else{
                swap(arr[mid],arr[e]);
                e--;
            }
        }
    }
    
    
};
