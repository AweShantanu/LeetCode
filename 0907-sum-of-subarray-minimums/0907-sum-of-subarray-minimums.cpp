class Solution {
public:
    
    vector<int> getLCE(vector<int>& arr, int n)
    {
        vector<int> res(n);
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                res[i]=-1;
            }
            else
            {
                while(!st.empty() && arr[st.top()]>arr[i])
                {
                    st.pop();
                }
                res[i]=st.empty()? -1:st.top();
            }
            st.push(i);
        }
        return res;
    }
    
    
    vector<int> getRCE(vector<int>& arr, int n)
    {
        vector<int> res(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                res[i]=n;
            }
            else
            {
                while(!st.empty() && arr[st.top()]>=arr[i])
                {
                    st.pop();
                }
                res[i]=st.empty()? n:st.top();
            }
            st.push(i);
        }
        return res;
    }
    
    
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> LCE= getLCE(arr,n);   //left chota element
        vector<int> RCE=getRCE(arr,n);
        
        long long sum=0;
        int mod=1e9+7;
        
        
        for(int i=0;i<n;i++)
        {
            long long ls=i-LCE[i];
            long long rs=RCE[i]-i;
            long long res=ls*rs;  // number of times ho gaya ye
            long long total=arr[i]*res;
            sum=(sum+total)%mod;  
        }
        return sum;
    }
};