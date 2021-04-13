class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>ans;
        if(n == 1)
        {
            return {nums[0]};
        }
        sort(nums.begin(), nums.end(), greater<int>());
        int total = 0;
        for(int i = 0; i < n; i++)
        {
            total += nums[i];
        }
        int cur_sum = 0;
        for(int i = 0; i < n; i++)
        {
            cur_sum += nums[i];
            if(cur_sum > total - nums[i])
            {
                ans.push_back(nums[i]);
                break;
            }
            else
            {
                total -= nums[i];
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
