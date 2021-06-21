
class Solution 
{
    public:
    bool dfs(int V, vector<int> adj[], vector<bool>& vis, int source, int parent)
    {
        vis[source] = true;
        for(auto child: adj[source])
        {
            if(!vis[child])
            {
                bool res = dfs(V, adj, vis, child, source);
                if(res == true)
                {
                    return true;
                }
            }
            else
            {
                if(child != parent)
                {
                    return true;
                }
            }
        }
        return false;
    }
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	    vector<bool>vis(V, false);
	    for(int i = 0; i < V; i++)
	    {
	        if(vis[i] == false)
	        {
	            bool res = dfs(V, adj, vis, i, -1);
	            if(res == true)
	            {
	                return true;
	            }
	        }
	    }
	    return false;
	}
};
