class Solution {
private:
    bool checkBipartite(int cur, int color, vector<int>& vis, vector<vector<int>>& graph)
    {
        // mark as visited
        vis[cur]=color;

        bool ans = true;
        for(int adjNode:graph[cur])
        {
            // un-visited
            if(vis[adjNode] == -1)
            {
                // inner recursive call may return false, hence consider all outputs
                ans = ans && checkBipartite(adjNode,!color,vis,graph);
            }
            // this adjacent node is already visited by other node and has same color of current node
            // hence we can't color this node with same color
            else if(vis[adjNode] == vis[cur])
            {
                return false;
            }
        }

        return ans;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,-1);

        // the graph can be dis-connected, hence try each node
        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                // if any non-connected component returned false, 
                // hence we can't paint the graph with 2 colors 
                if(!checkBipartite(i,0,vis,graph))
                    return false;
            }
        }

        // all non-connected components returned true
        return true;
    }
};