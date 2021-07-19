class Solution {
public:
    bool find132pattern(vector<int>& nums)
    {
        int n = nums.size();
        vector<int>leftmin(n);
        leftmin[0] = nums[0];
        for(int i = 1; i < n; i++)
        {
            leftmin[i] = min(leftmin[i - 1], nums[i]);
        }
        set<int>s;
        s.insert(nums[n - 1]);
        for(int i = n - 2; i >= 0; i--)
        {
            auto itr = s.lower_bound(nums[i]);
            if(itr != s.begin())
            {
                itr--;
                if(*itr > leftmin[i])
                {
                    return true;
                }
            }
            s.insert(nums[i]);
        }
        return false;
    }
};


// tc o(nlogn)
// sc o(n)


class Solution {
public:
    bool find132pattern(vector<int>& nums)
    {
        int n = nums.size();
        int c = INT_MIN;
        stack<int>s;
        for(int i = n - 1; i >= 0; i--)
        {
            if(nums[i] < c)
            {
                return true;
            }
            while(s.size() > 0 && nums[i] > s.top())
            {
                c = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};
// tc o(N)
// sc o(N)
