class Solution {
public:
    void fun(vector<vector<int>>& image,int i , int j , int newcolor , int oldcolor, int n , int m,  vector<vector<bool>>&vis)
    {
        if(i < 0 || j < 0 || i >= n || j >= m || image[i][j] != oldcolor || vis[i][j] == true)
        {
            return;
        }
            vis[i][j] = true;
            image[i][j] = newcolor;
            fun(image , i , j + 1, newcolor, oldcolor , n , m, vis);
            fun(image , i , j - 1, newcolor , oldcolor , n, m, vis);
            fun(image, i + 1 , j , newcolor, oldcolor , n, m, vis);
            fun(image , i - 1, j, newcolor , oldcolor , n, m, vis);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m , false));
      fun(image, sr, sc, newColor, image[sr][sc], n ,m , vis);
        return image;
    }
};
