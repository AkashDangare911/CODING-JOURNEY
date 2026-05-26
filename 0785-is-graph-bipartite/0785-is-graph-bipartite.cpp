class Solution {
private:
    bool checkBipartite(int ind, vector<int>& vis, vector<vector<int>>& graph)
    {
        // put starting point in queue and start with color - 0
        int color=0;
        queue<int> q;
        vis[ind]=color;
        q.push(ind);

        while(!q.empty())
        {
            // color the adjacent nodes with different color, hence alter the color
            color=!color;
            
            int nq=q.size();
            for(int i=0;i<nq;i++)
            {
                int cur=q.front();
                q.pop();

                for(int adjNode:graph[cur])
                {
                    // un-visited
                    if(vis[adjNode] == -1)
                    {
                        vis[adjNode]=color;
                        q.push(adjNode);
                    }
                    // this adjacent node is already visited by other node and has same color of current node
                    // hence we can't color this node with same color
                    else if(vis[adjNode] == vis[cur])
                    {
                        return false;
                    }
                }
            }
        }

        return true;
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
                if(!checkBipartite(i,vis,graph))
                    return false;
            }
        }

        // all non-connected components returned true
        return true;
    }
};