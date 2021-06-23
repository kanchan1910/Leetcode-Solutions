class Solution
{
    public:
    bool dfs(vector<int> adj[], vector<bool>&vis, vector<bool>&ancestor, int source)
    {
        vis[source] = true;
        ancestor[source] = true;
        for(auto child: adj[source])
        {
            if(!vis[child])
            {
                if(dfs(adj, vis, ancestor, child) == true)
                {
                    return true;
                }
            }
            else
                {
                    if(ancestor[child] == true)
                    {
                        return true;
                    }
                }
        }
        ancestor[source] = false;
        return false;
    }
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	    vector<bool>vis(V, false);
	    vector<bool>ancestor(V, false);
	    for(int i = 0; i < V; i++)
	    {
	        if(!vis[i])
	        {
	            if(dfs(adj, vis, ancestor, i) == true)
	            {
	                return true;
	            }
	        }
	    }
	    return false;
	}
};
