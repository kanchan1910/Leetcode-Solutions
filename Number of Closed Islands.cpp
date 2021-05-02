class Solution {
public:
   
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j, int n, int m)
    {
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 1 || vis[i][j] == true)
        {
            return;
        }
        vis[i][j] = true;
        dfs(grid, vis, i, j - 1, n, m);
        dfs(grid, vis, i, j + 1, n, m);
        dfs(grid, vis, i - 1, j, n, m);
        dfs(grid, vis, i + 1, j, n, m);

    }
    int closedIsland(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        int ans = 0;
           // same as number of islands, only difference is this
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if((grid[i][j] == 0 && !vis[i][j]) && (i == 0 || j == 0 || i == n - 1 || j == m - 1))
                {
                    dfs(grid, vis, i, j, n, m);
                    // vis[i][j] = true;
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 0 && !vis[i][j])
                {
                    dfs(grid, vis, i, j, n, m);
                    ans++;
                }
            }
        }
        return ans;
    }
};
