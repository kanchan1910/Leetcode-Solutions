class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>>q;
        int fresh = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    fresh++;
                }
                else if(grid[i][j] == 2)
                {
                    q.push({i, j});  
                } 
            }
        }
        int ans = 0;
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    if(x - 1 >= 0 && grid[x - 1][y] == 1)
                    {
                        fresh--;
                        grid[x - 1][y] = 2;
                        q.push({x - 1, y});
                    }
                    if(y - 1 >= 0 && grid[x][y - 1] == 1)
                    {
                        fresh--;
                        grid[x][y - 1] = 2;
                        q.push({x, y - 1});
                    }
                    if(x + 1 < n && grid[x + 1][y] == 1)
                    {
                        fresh--;
                        grid[x + 1][y] = 2;
                        q.push({x + 1, y});
                    }
                    if(y + 1 < m && grid[x][y + 1] == 1)
                    {
                        fresh--;
                        grid[x][y + 1] = 2;
                        q.push({x, y + 1});
                    }   
            }
            if(q.size() > 0)
            {
                ans++;
            }
        }
        return fresh == 0 ? ans : -1;
    }
};
