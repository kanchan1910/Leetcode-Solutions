class Solution {
public:
    void dfs(int n,vector<int>adj[], int source,vector<bool>&vis)
    {
       vis[source] = true;
        for(auto child : adj[source])
        {
            if(vis[child] == false)
            {
                dfs(n , adj , child , vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections)
    // approach :
    {
 // first we will find number of connected components and if they are equal to 1 the answer is 0 , if 
// they are > 1 then we will the total number of cables and if they are equal to n - 1 then this mean that we can connect the componens we have sufficuent cables and so we will return the number of connected components as the number of connected components are same as the number of cables needed
    // but if cables are < n - 1 then return  -1;
        if(connections.size() < n - 1)
        {
            return -1;
        }
        vector<int>adj[n];
        for(int i = 0 ; i < connections.size() ; i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<bool>vis(n , false);
        int count = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(vis[i] == false)
            {
                count++;
                dfs(n , adj , i , vis);
            }
        }
     ///   cout << count << endl;
        if(count == 1)
        {
            return 0;
            
        }
      return count - 1;
    }
};
