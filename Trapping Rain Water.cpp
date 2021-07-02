class Solution {
public:
    int trap(vector<int>& height)
    {
        int n = height.size();
        if(n == 0)
        {
            return 0;
        }
        vector<int>left(n, 0);
        vector<int>right(n, 0);
        left[0] = height[0];
        for(int i = 1; i < n; i++)
        {
            left[i] = max(height[i], left[i - 1]);
        }
        right[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; i--)
        {
            right[i] = max(right[i + 1], height[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans += (min(left[i], right[i]) - height[i]);
        }
        return ans;
    }
};
// tc o(n)
// sc o(n)



class Solution {
public:
    int trap(vector<int>& height) {
     int n = height.size();
     int ans = 0;
        if(n < 2)
        {
            return 0;
        }
       int l = 0, r = n-1, lmax = 0, rmax = 0;
        while(l <= r)
        {
            if(height[l] <= height[r])
            {
                if(height[l] >= lmax)
                {
                    lmax = height[l];
                }
                else
                {
                    ans += lmax - height[l];
                }
                l++;
            }
            else 
            {
                if(height[r] >= rmax)
                {
                    rmax = height[r];
                }
                else
                {
                    ans += rmax - height[r];
                }
                r--;
            }
        }
        return ans;
    }
};
// tc o(n)
// sc o(1)
