class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int n = nums.size();
        unordered_map<int, int>m;
        int cur_sum = 0;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            cur_sum += nums[i];
            if(cur_sum == k)
            {
                ans++;
            }
            if(m.find(cur_sum - k) != m.end())
            {
                ans += m[cur_sum - k];
            }
            m[cur_sum]++;
        }
            return ans;
    }
};
// tc o(n)
// sc o(n)
