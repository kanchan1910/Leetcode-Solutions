class Solution
{
	public:
	 void dfs(int source, stack<int>&s,bool vis[],vector<int> adj[])
    {
        vis[source] = true;
        for(auto child:adj[source])
        {
            if(!vis[child])
            {
                dfs(child,s,vis,adj);
            }
        }
        s.push(source);
    }
     void ddfs(int source,bool vis[],vector<int> adj[])
    {
        vis[source] = true;
        for(auto child:adj[source])
        {
            if(!vis[child])
            {
                ddfs(child,vis,adj);
            }
        }
    }
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
     stack<int>s;
     bool vis[V];
     memset(vis,false,sizeof(vis));
     for(int i = 0; i < V; i++)
     {
         if(vis[i] == false)
         {
             dfs(i,s,vis,adj);
         }
     }
     memset(vis,false,sizeof(vis));
     vector<int>adj_rev[V];
     for(int source = 0; source < V; source++)
     {
         for(auto child:adj[source])
         {
             adj_rev[child].push_back(source);
         }
     }
     int ans = 0;
     while(!s.empty())
     {
         int top = s.top();
         s.pop();
         if(!vis[top])
         {
             ddfs(top,vis,adj_rev);
             ans++;
         }
     }
     return ans;
    }
};
