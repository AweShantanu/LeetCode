class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();  //rows
        int m=n;              //column
        
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<m;j++)
            {
                swap(matrix[j][i],matrix[i][j]);
            }
        }
        //ab usko reverse kar denge
        for(int i=0;i<n;i++)
        {
            int l=0;
            int h=n-1;
            while(l<h)
            {
                swap(matrix[i][l],matrix[i][h]);
                l++;
                h--;
            }
            
        }
    }
};