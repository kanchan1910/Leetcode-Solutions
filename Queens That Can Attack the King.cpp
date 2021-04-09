class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king)
    {
        vector<vector<int>>ans;
        // check in the left row
        int kingx = king[0];
        int kingy = king[1] - 1;
        while(kingy >= 0)
        {
            if(find(queens.begin(), queens.end(), vector<int>{kingx, kingy}) != queens.end())
            {
                ans.push_back(vector<int>{kingx, kingy});
                break;
            }
            kingy--;
        }
        // checkin the right row
        kingy = king[1] + 1;
        while(kingy < 8)
        {
            if(find(queens.begin(), queens.end(),vector<int>{kingx, kingy}) != queens.end())
            {
                ans.push_back(vector<int>{kingx, kingy});
                break;
            }
            kingy++;
        }
        kingx = king[0] - 1;
        kingy = king[1];
        //check in upper column
        while(kingx >= 0)
        {
             if(find(queens.begin(), queens.end(),vector<int>{kingx, kingy}) != queens.end())
            {
                ans.push_back(vector<int>{kingx, kingy});
                 break;
            }
            kingx--;
        }
        kingx = king[0] + 1;
        //check bottom columnn
       while(kingx < 8)
        {
             if(find(queens.begin(), queens.end(),vector<int>{kingx, kingy}) != queens.end())
            {
                ans.push_back(vector<int>{kingx, kingy});
                 break;
            }
            kingx++;
        }
        kingx = king[0] - 1;
        kingy = king[1] - 1;
        // left diagonal up
        while(kingx >= 0 && kingy >= 0)
        {
             if(find(queens.begin(), queens.end(),vector<int>{kingx, kingy}) != queens.end())
            {
                ans.push_back(vector<int>{kingx, kingy});
                 break;
            }
            kingx--;
            kingy--;
        }
        kingx = king[0] + 1;
        kingy = king[1] - 1;
        // left diagonal down
        while(kingx < 8 && kingy >= 0)
        {
             if(find(queens.begin(), queens.end(),vector<int>{kingx, kingy}) != queens.end())
            {
                ans.push_back(vector<int>{kingx, kingy});
                 break;
            }
            kingx++;
            kingy--;
        }
        kingx = king[0] - 1;
        kingy = king[1] + 1;
        // right diagonal up
         while(kingx >= 0 && kingy < 8)
        {
             if(find(queens.begin(), queens.end(),vector<int>{kingx, kingy}) != queens.end())
            {
                ans.push_back(vector<int>{kingx, kingy});
                 break;
            }
            kingx--;
            kingy++;
        }
        kingx = king[0] + 1;
        kingy = king[1] + 1;
        // right diagonal down
        while(kingx < 8 && kingy < 8)
        {
             if(find(queens.begin(), queens.end(),vector<int>{kingx, kingy}) != queens.end())
            {
                ans.push_back(vector<int>{kingx, kingy});
                 break;
            }
            kingx++;
            kingy++;
        }
        return ans;
    }
};
