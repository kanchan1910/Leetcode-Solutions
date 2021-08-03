class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<bool>>& vis, int& count)
    {
        if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] == true || grid[i][j] == 0)
        {
            return;
        }
        count++;
        vis[i][j] = true;
        dfs(i + 1, j, n, m, grid, vis, count);
        dfs(i - 1, j, n, m, grid, vis, count);
        dfs(i, j + 1, n, m, grid, vis, count);
        dfs(i, j - 1, n, m, grid, vis, count);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1 && !vis[i][j])
                {
                    int count = 0;
                    dfs(i, j, n, m, grid, vis, count);
                    ans = max(ans, count);
                }
            }
        }
        return ans;
    }
};
