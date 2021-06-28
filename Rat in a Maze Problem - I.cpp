class Solution{
    public:
    void fun(vector<vector<int>> &m, int n, vector<vector<bool>>& vis, string str,vector<string>& ans, int i, int j)
    {
        if(i < 0 || j < 0 || i >= n || j >= n || vis[i][j] == true || m[i][j] == 0)
        {
            return;
        }
        if(i == n - 1 && j == n - 1)
        {
            ans.push_back(str);
            return;
        }
        vis[i][j] = true;
        fun(m, n, vis, str + "D", ans, i + 1, j);
        fun(m, n, vis, str + "U", ans, i - 1, j);
        fun(m, n, vis, str + "L", ans, i, j - 1);
        fun(m, n, vis, str + "R", ans, i, j + 1);
        str.pop_back();
        vis[i][j] = false;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) 
    {
        vector<string>ans;
        if(m[n - 1][n - 1] == 0)
        {
            return ans;
        }
        string str = "";
        vector<vector<bool>>vis(n, vector<bool>(n, false));
        fun(m, n, vis, str, ans, 0, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
