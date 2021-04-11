class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        int n = nums.size();
        vector<string>ans;
        if(n == 0)
        {
            return ans;
        }
        int start = 0;
        string tmp;
        for(int i = 1; i < n ; i++)
        {
            // this case
            // [-2147483648,-2147483647,2147483647]
            if((long(nums[i]) - long(nums[i - 1])) != 1)
            {
                if(nums[start] != nums[i - 1])
                {
                   tmp = to_string(nums[start]) +  "->" + to_string(nums[i - 1]);
                }
                else
                {
                   tmp = to_string(nums[start]);
                }
                
                ans.push_back(tmp);
                start = i;
            }
        }
        if(nums[start] != nums[n - 1])
        {
            tmp = to_string(nums[start]) +  "->" + to_string(nums[n - 1]);
        }
        else 
        {
            tmp = to_string(nums[start]);
        }
        ans.push_back(tmp);
        return ans;
    }
};
