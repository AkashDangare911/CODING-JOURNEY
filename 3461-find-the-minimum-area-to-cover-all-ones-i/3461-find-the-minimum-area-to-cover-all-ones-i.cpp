class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // initial pointers - reverse assignment
        int top=m-1, bottom=0, left=n-1, right=0;

        // max possible ans would be the whole matrix
        // hence, try to minimize the area, by keeping track of occurence of 1's
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    top=min(top,i);
                    bottom=max(bottom,i);
                    left=min(left,j);
                    right=max(right,j);
                }
            }
        }

        return (right-left+1)*(bottom-top+1);
    }
};