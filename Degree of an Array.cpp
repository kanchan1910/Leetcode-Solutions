class Solution {
public:
    int findShortestSubArray(vector<int>& nums)
    {
        int n = nums.size();
        unordered_map<int, vector<int>>m;
        for(int i = 0; i < n; i++)
        {
            m[nums[i]].push_back(i);
        }
        int max_degree = 0;
        for(auto x: m)
        {
            max_degree = max(max_degree, (int)x.second.size());
        }
        int ans = n;
        for(auto x: m)
        {
            if(x.second.size() == max_degree)
            {
                ans = min(ans, x.second.back() - x.second[0] + 1);
            }
        }
        return ans;
    }
};


      
      

// tc o(n)
// sc o(n)

// only storing frequency in the map will not work, as we need to know the indexes for finding the length of the subarray
