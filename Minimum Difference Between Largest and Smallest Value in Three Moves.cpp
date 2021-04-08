class Solution {
public:
    int minDifference(vector<int>& nums)
    {
        int n = nums.size();
        if(n <= 4)
        {
            return 0;
        }
        int fmin = INT_MAX, smin = INT_MAX, tmin = INT_MAX, frmin = INT_MAX, fmax= INT_MIN, smax = INT_MIN, tmax = INT_MIN, frmax = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] < fmin)
            {
                frmin = tmin;
                tmin = smin;
                smin = fmin;
                fmin = nums[i];
            }
            else if(nums[i] < smin)
            {
                frmin = tmin;
                tmin = smin;
                smin = nums[i];
            }
            else if(nums[i] < tmin)
            {
                frmin = tmin;
                tmin = nums[i];
            }
            else if(nums[i] < frmin)
            {
                frmin = nums[i];
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(fmax < nums[i])
            {
                frmax = tmax;
                tmax = smax;
                smax = fmax;
                fmax = nums[i];
            }
            else if(smax < nums[i])
            {
                frmax = tmax;
                tmax = smax;
                smax = nums[i];
            }
            else if(tmax < nums[i])
            {
                frmax = tmax;
                tmax = nums[i];
            }
            else if(frmax < nums[i])
            {
                frmax = nums[i];
            }
        }
        int ans = INT_MAX;
      ans = min(fmax - frmin, frmax - fmin);
      // confirm 
      ans = min(smax - tmin, ans);
      ans = min(ans, tmax - smin);
        return ans;
    }
};
// tc o(n)
// sc o(1)
