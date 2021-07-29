 // need of visited array is in the case when oldColor = newColor and this might be the case
    void dfs(int n, int m, vector<vector<int>>& image, int i, int j, int oldColor, int newColor, vector<vector<bool>>& vis)
    {
        if(i < 0 || j < 0 || i >= n || j >= m ||image[i][j] != oldColor || vis[i][j] == true)
        {
            return;
        }
        image[i][j] = newColor;
        vis[i][j] = true;
        dfs(n, m, image, i - 1, j, oldColor, newColor, vis);
        dfs(n, m, image, i + 1, j, oldColor, newColor, vis);
        dfs(n, m, image, i, j - 1, oldColor, newColor, vis);
        dfs(n, m, image, i, j + 1, oldColor, newColor, vis);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
       int n = image.size();
       int m = image[0].size();
       vector<vector<bool>>vis(n, vector<bool>(m, false));
       dfs(n, m, image, sr, sc, image[sr][sc], newColor, vis);
       return image;
    }
// Time Compelxity: O(n*m)
// Space Complexity: O(n*m)
