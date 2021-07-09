class Solution {
public:
    int minMoves(vector<int>& nums) 
    {
        int n = nums.size();
        int mini = *min_element(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans += (nums[i] - mini);
        }
        return ans;
    }
};

// n-1 numbers increment is equal to 1 numbers decrement.

