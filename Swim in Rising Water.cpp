class Solution 
{
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int n, int maxi, int i, int j)
    {
        if(i < 0 || j < 0 || i >= n || j >= n || vis[i][j] == true || grid[i][j] > maxi)
        {
            return;
        }
        vis[i][j] = true;
        dfs(grid, vis, n, maxi, i + 1, j);
        dfs(grid, vis, n, maxi, i - 1, j);
        dfs(grid, vis, n, maxi, i, j + 1);
        dfs(grid, vis, n, maxi, i, j - 1);
    }
    int swimInWater(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int l = 0, r = n * n - 1;
        int ans = 0;
        while(l <= r)
        {
            int mid = (l + (r - l) / 2);
            vector<vector<bool>>vis(n, vector<bool>(n, false));
            dfs(grid, vis, n, mid, 0, 0);
            if(vis[n - 1][n - 1] == true)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};

// sc o(n*n)
// tc o(n*n*logn)


// brute force solution
// We can start with the brute force approach and explore all the possible paths to reach the end of the grid. The path which minimizes the maximum value of some cell in a path will be chosen /*
/*Time Complexity : O(4n2), for each cell of the grid, we have 4 choices. So, in the worst case we may need 4*4*4*...n2times

Space Complexity : O(n2)
*/


// linear search for every value from 0 to n * n - 1
// Time Complexity : O(n4), we are exploring all water-level values from 1 to n*n. For each water-level MAX, we call dfs() having O(n2) time complexity in the worst case. Thus, overall time complexity becomes O(n*n) * O(n2) = O(n4)

// Space Complexity : O(n2)
