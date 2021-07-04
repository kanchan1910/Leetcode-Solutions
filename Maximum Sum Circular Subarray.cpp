class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int n = nums.size();
        int cur1 = nums[0];
        int maxsum = nums[0];
        int cur2 = nums[0];
        int minsum = nums[0];
        int sum = nums[0];
        for(int i = 1; i < n; i++)
        {
            sum += nums[i];
            cur1 = max(nums[i], cur1 + nums[i]);
            maxsum = max(maxsum, cur1);
            cur2 = min(nums[i], cur2 + nums[i]);
            minsum = min(minsum, cur2);
        }
        if(maxsum < 0)
        {
            return maxsum;
        }
        return max(maxsum, sum - minsum);
    }
};
// tc o(n)
// sc o(1)
