// variation of allocatio of minimum pages problem and the painter's partition problem
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
    int shipWithinDays(vector<int>& weights, int days)
    {
        int n = weights.size();
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += weights[i];
        }
        int l = 0, r = sum;
        int ans = INT_MAX;
        while(l <= r)
        {
            int mid = (l + (r - l) / 2);
            if(isValid(weights, n, days, mid) == true)
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
