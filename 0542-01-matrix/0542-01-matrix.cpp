class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> visited(m,vector<int> (n,0));
        vector<vector<int>> ans(m,vector<int> (n,0));
        int row[4] = {-1,1,0,0};
        int col[4] = {0,0,1,-1};
        queue<pair<int,int>> q;

        // put all 0's into queue --> starting points
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    visited[i][j]=1;    // mark the nodes as visited
                }
            }
        }

        int dist=1;

        while(!q.empty())
        {
            int nq=q.size();

            for(int i=0;i<nq;i++)
            {
                int curRow=q.front().first;
                int curCol=q.front().second;
                q.pop();

                for(int i=0;i<4;i++)
                {
                    int nextRow=curRow+row[i];
                    int nextCol=curCol+col[i];

                    // if next node with val=1 which is within the bounds and not previous visited
                    // put into queue and mark it as visited
                    if(nextRow>=0 && nextRow<m && nextCol>=0 && nextCol<n && 
                        visited[nextRow][nextCol]==0 && mat[nextRow][nextCol]==1)
                    {
                        ans[nextRow][nextCol]=dist;
                        visited[nextRow][nextCol]=1;
                        q.push({nextRow,nextCol});
                    }
                }
            }

            // at each iteration, distance will increase by 1
            dist++;
        }

        return ans;
    }
};