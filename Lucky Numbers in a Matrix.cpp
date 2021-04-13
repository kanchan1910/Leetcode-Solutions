class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix)
    {
        vector<int>ans;
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_set<int>s;
        for(int i = 0; i < n; i++)
        {
            int mini = INT_MAX;
            for(int j = 0; j < m; j++)
            {
                mini = min(mini, matrix[i][j]);
            }
                s.insert(mini);
        }
        for(int j = 0; j < m; j++)
        {
            int maxi = INT_MIN;
            for(int i = 0; i < n; i++)
            {
                maxi = max(maxi, matrix[i][j]);
            }
            if(s.count(maxi) == 0)
            {
                s.insert(maxi);
            }
            else
            {
                ans.push_back(maxi);
            }
        }
        return ans;
    }
};

// tc o(n ^ 2)
// sc o(1)
