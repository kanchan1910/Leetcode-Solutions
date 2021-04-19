class Solution {
public:
    // Each number in candidates may only be used once in the combination.
    void fun(vector<int>& candidates, int target, int n, int index, vector<vector<int>>& ans, vector<int>& ds)
    {
            if(target == 0)
            {
                ans.push_back(ds);
                return;
            }
        
        for(int i = index; i < n; i++)
        {
         if(i > index && candidates[i] == candidates[i - 1])
         {
             continue;
         }
         if(candidates[i] <= target)
         {
            ds.push_back(candidates[i]);
            fun(candidates, target - candidates[i], n, i + 1, ans, ds);
            ds.pop_back();
         }    
         else
         {
             break;
         }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        fun(candidates, target, n, 0, ans, ds);
        return ans;
    }
};
