// https://leetcode.com/problems/sort-the-matrix-diagonally/


class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0 ;i < m ; i++)
        {
            vector<int>tmp;
            int x = 0;
            int y = i;
            while(x < n && y < m)
            {
                tmp.push_back(mat[x][y]);
                x++;
                y++;
            }
            sort(tmp.begin(),tmp.end());
            x = 0;
            y = i;
            int k = 0;
            while(x < n && y < m)
            {
                mat[x][y] = tmp[k];
                x++;
                y++;
                k++;
            }
            
        }
        for(int i = 1; i < n ; i++)
        {
            vector<int>tmp;
            int x = i;
            int y = 0;
            while(x < n && y < m)
            {
                tmp.push_back(mat[x][y]);
                x++;
                y++;
            }
            sort(tmp.begin(),tmp.end());
            int k = 0;
            x = i;
            y = 0;
            while(x < n && y < m)
            {
                mat[x][y] = tmp[k];
                x++;
                y++;
                k++;
            }
        }
        return mat;
    }
};


// https://practice.geeksforgeeks.org/problems/diagonal-morning-assembly0028/1#

 void diagonalSort(vector<vector<int> >& matrix, int n, int m) 
    {
        for(int j = 1; j < m; j++)
        {
            int x = 0, y = j;
            vector<int>tmp;
            while(x < n && y < m)
            {
                tmp.push_back(matrix[x][y]);
                x++;
                y++;
            }
            sort(tmp.begin(), tmp.end(), greater<int>());
            x = 0, y = j;
            int index = 0;
            while(x < n && y < m)
            {
                matrix[x][y] = tmp[index];
                index++;
                x++;
                y++;
            }
        }
        for(int i = 1; i < n; i++)
        {
            int x = i, y = 0;
            vector<int>tmp;
            while(x < n && y < m)
            {
                tmp.push_back(matrix[x][y]);
                x++;
                y++;
            }
            sort(tmp.begin(), tmp.end());
            x = i, y = 0;
            int index = 0;
            while(x < n && y < m)
            {
                matrix[x][y] = tmp[index];
                index++;
                x++;
                y++;
            }
        }
    }
