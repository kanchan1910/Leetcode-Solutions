class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int n = nums.size();
        int cur = nums[0];
        int sum = nums[0];
        for(int i = 1; i < n; i++)
        {
            cur = max(nums[i], cur + nums[i]);
            sum = max(sum, cur);
        }
        return sum;
    }
};

// tc o(n)
// sc o(1)

// brute force sol o(n ^ 3)
// optimised from brute force solution o(n ^ 2)
