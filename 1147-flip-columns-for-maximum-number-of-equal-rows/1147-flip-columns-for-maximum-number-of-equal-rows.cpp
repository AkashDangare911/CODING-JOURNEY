class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> mp;
        int m = matrix.size();
        int n = matrix[0].size();
        int ans=0;

        for(int i=0;i<m;i++)
        {
            string cur="";
            int st = matrix[i][0];
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==st)
                    cur.push_back('1');
                else
                    cur.push_back('0');
            }
            mp[cur]++;
        }

        for(auto p: mp)
        {
            ans = max(ans, p.second);
        }

        return ans;
    }
};