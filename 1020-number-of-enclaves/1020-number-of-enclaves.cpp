class Solution {
private:
    int row[4]={0,0,1,-1};
    int col[4]={-1,1,0,0};

    void markBoundaryNodes(int i, int j, vector<vector<int>>& grid)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)
            return;
        
        grid[i][j]=0;

        for(int ind=0;ind<4;ind++)
        {
            int nrow=i+row[ind];
            int ncol=j+col[ind];

            markBoundaryNodes(nrow,ncol,grid);
        }
    }
    
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        // first & last rows
        for(int i=0;i<n;i++)
        {
            if(grid[0][i]==1)
                markBoundaryNodes(0,i,grid);
            
            if(grid[m-1][i]==1)
                markBoundaryNodes(m-1,i,grid);
        }

        // first & last col
        for(int i=0;i<m;i++)
        {
            if(grid[i][0]==1)
                markBoundaryNodes(i,0,grid);
            
            if(grid[i][n-1]==1)
                markBoundaryNodes(i,n-1,grid);
        }

        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                    ans++;
            }
        } 

        return ans;
    }
};