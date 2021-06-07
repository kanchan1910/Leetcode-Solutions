class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>ans;
       int top = 0, left = 0, right = m - 1, bottom = n - 1;
       int dir = 0;
       while(top <= bottom && left <= right)
       {
           if(dir == 0)
           {
               // left to right
               for(int i = left; i <= right; i++)
               {
                   ans.push_back(matrix[top][i]);
               }
               top++;
           }
           else if(dir == 1)
           {
               // top to bottom
               for(int i = top; i <= bottom; i++)
               {
                   ans.push_back(matrix[i][right]);
               }
               right--;
           }
           else if(dir == 2)
           {
               // right ot left
               for(int i = right; i >= left; i--)
               {
                   ans.push_back(matrix[bottom][i]);
               }
               bottom--;
           }
           else if(dir == 3)
           {
               // bottom to top
               for(int i = bottom; i >= top; i--)
               {
                   ans.push_back(matrix[i][left]);
               }
               left++;
           }
          dir = (dir + 1) % 4;
       }
       return ans;
    }
};
