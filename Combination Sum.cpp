class Solution {
public:
    // can choose unlimited number of times
    void fun(int target, int index, vector<int>& candidates, int n, vector<vector<int>>&ans, vector<int>&ds)
    {
        // base case
        if(index == n)
        {
            if(target == 0)
            {
                ans.push_back(ds);
            }
            return;
        }
        // choose to pick
        if(candidates[index] <= target)
        {
            ds.push_back(candidates[index]);
            fun(target - candidates[index], index, candidates, n, ans, ds);
            ds.pop_back();
        }	
        // not pick
        fun(target, index + 1, candidates, n, ans, ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        int n = candidates.size();
        vector<vector<int>>ans;
        vector<int>ds;
        fun(target, 0, candidates, n, ans, ds);
        return ans;
    }
};
