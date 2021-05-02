class Solution {
public:
    void fun(vector<vector<int>>& grid, int n, int m)
    {
        int prev = grid[n - 1][m - 1];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int cur = grid[i][j];
                grid[i][j] = prev;
                prev = cur;
            }
        }
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) 
    {
        int n = grid.size();
        int m = grid[0].size();
        while(k--)
        {
            fun(grid, n, m);
        }
        return grid;
    }
};
// tc o(n*m*k)
// sc o(1) 
