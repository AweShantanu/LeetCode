class Solution {
public:
    typedef vector<double> P;
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<P,vector<P>> pq;
        int n=arr.size();
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                double fraction = (double) arr[i] / arr[j];
                pq.push({fraction, (double)arr[i], (double)arr[j]});
                if(pq.size()>k)
                {
                    pq.pop();
                }
            }
        }
        vector<int> v(2);
        v[0]=(int)pq.top()[1];
        v[1]=(int)pq.top()[2];
        return v;
        
    }
};