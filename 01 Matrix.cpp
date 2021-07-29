class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int, int>>q;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({i, j});
                }
                else
                {
                    mat[i][j] = INT_MAX;
                }
            }
        }
        while(q.size() > 0)
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x - 1 >= 0)
                {
                    if(mat[x - 1][y] > mat[x][y] + 1)
                    {
                            mat[x - 1][y] = mat[x][y] + 1;
                            q.push({x - 1, y});
                    }
                }
                if(y - 1 >= 0)
                {
                   if(mat[x][y - 1] > mat[x][y] + 1)
                    {
                            mat[x][y - 1] = mat[x][y] + 1;
                            q.push({x, y - 1});
                    }
                }
                if(x + 1 < n)
                {
                    if(mat[x + 1][y] > mat[x][y] + 1)
                    {
                            mat[x + 1][y] = mat[x][y] + 1;
                            q.push({x + 1, y});
                    }
                }
                if(y + 1 < m)
                {
                    if(mat[x][y + 1] > mat[x][y] + 1)
                    {
                            mat[x][y + 1] = mat[x][y] + 1;
                            q.push({x, y + 1});
                    }
                }   
            }
        }
        return mat;
    }
};
