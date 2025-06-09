class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int ones=-1, rowInd=-1, ans=-1;
        int m=mat.size(), n=mat[0].size();

        for(int i=0;i<m;i++)
        {
            int sum=0;
            for(int j=0;j<n;j++)
                sum+=mat[i][j];

            if(sum>ans)
            {
                ones=sum;
                rowInd=i;

                ans=sum;
            }
        }

        return {rowInd,ones};
    }
};