class Solution {
private:
    int findMax(vector<vector<int>>& mat, int mid)
    {
        int m=mat.size();
        int maxInd=0;

        for(int i=0;i<m;i++)
        {
            if(mat[i][mid]>mat[maxInd][mid])
            {
                maxInd=i;
            }
        }

       // return row index with max value
        return maxInd;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        int low=0, high=n-1;
        int mid;

        while(low<=high)
        {
            mid=(low+high)/2;

            // get max element and it's from 'mid' column
            int maxElementRowIndex = findMax(mat,mid);
            int maxElementFromMidColumn = mat[maxElementRowIndex][mid];

            cout<<maxElementFromMidColumn<<endl;

            int leftElement=0, rightElement=0;
            if(mid>0) leftElement = mat[maxElementRowIndex][mid-1];
            if(mid<n-1) rightElement = mat[maxElementRowIndex][mid+1];

            // check if our maxElement is peak or not
            if((!leftElement && rightElement<maxElementFromMidColumn) ||
                (!rightElement && leftElement<maxElementFromMidColumn) ||
                (leftElement<maxElementFromMidColumn && rightElement<maxElementFromMidColumn))
            {
                return {maxElementRowIndex,mid};
            }
            // if maxElement is on increasing slope, means peak will occur afterwards
            else if(leftElement<maxElementFromMidColumn)
                low=mid+1;
            
            // decreasing slope, means peak element already occured, so move backward
            else
                high=mid;
        }

        return {-1,-1};
    }
};