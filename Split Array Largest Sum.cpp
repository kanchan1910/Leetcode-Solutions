class Solution {
public:
    bool isValid(vector<int>& nums, int n, int m, int cur_min)
    {
        int split = 1;
        int cur_sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] > cur_min)
            {
                return false;
            }
            if(cur_sum + nums[i] > cur_min)
            {
                split++;
                cur_sum = nums[i];
                if(split > m)
                {
                    return false;
                }
            }
            else
            {
                cur_sum += nums[i];
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m)
    {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        int l = 0, r = sum;
        int ans = INT_MAX;
        while(l <= r)
        {
            int mid = (l + (r - l) / 2);
            if(isValid(nums, n, m, mid) == true)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};
// varaition of allocation of minimum pages problem and the painters partition problem
