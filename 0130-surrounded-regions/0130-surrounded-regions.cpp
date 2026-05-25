class Solution {
private:
    int row[4]={0,0,1,-1};
    int col[4]={-1,1,0,0};

    void dfs(int i, int j, vector<vector<char>>& board)
    {
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]=='X' || board[i][j]=='Y')
            return;
        
        board[i][j]='Y';

        for(int ind=0;ind<4;ind++)
        {
            int nrow=i+row[ind];
            int ncol=j+col[ind];

            dfs(nrow,ncol,board);
        }
    }
public:
    // CONVERT ALL THE BOUNDARY NODES AND ITS ADJACENT NODES AS NON-CONVERTABLE i.e., 'Y'
    // THEN, CONVERT THE SURROUNDED O's TO X
    // AND, REVERT THE BOUNDARY NODES TO O's
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        // first & last rows
        for(int i=0;i<n;i++)
        {
            if(board[0][i]=='O')
                dfs(0,i,board);
            
            if(board[m-1][i]=='O')
                dfs(m-1,i,board);
        }

        // first & last col
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O')
                dfs(i,0,board);
            
            if(board[i][n-1]=='O')
                dfs(i,n-1,board);
        }

        // convert all the surrounded O's to 'X' and revert all the 'Y' to 'O'
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='Y')
                    board[i][j]='O';
            }
        } 
    }
};