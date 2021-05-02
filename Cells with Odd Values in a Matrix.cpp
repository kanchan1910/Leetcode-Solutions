class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices)
    {
        vector<vector<int>>v(m, vector<int>(n, 0));
        int ans = 0;
        for(int i = 0; i < indices.size(); i++)
        {
            int row = indices[i][0];
            int col = indices[i][1];
            for(int r = 0; r < m; r++)
            {
                if(row == r)
                {
                    for(int c = 0; c < n; c++)
                    {
                        v[r][c]++;
                    }
                }
                else
                {
                    continue;
                }
            }
            for(int c = 0; c < n; c++)
            {
                if(c == col)
                {
                    for(int r = 0; r < m; r++)
                    {
                        v[r][c]++;
                    }
                }
                else
                {
                    continue;
                }
            }
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(v[i][j] % 2 != 0)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
